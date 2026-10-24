#include "FuzzyNumber.h"
#include <sstream>

namespace FuzzyLib {
    FuzzyNumber::FuzzyNumber() : x(0.0), el(0.0), er(0.0) {}
    FuzzyNumber::FuzzyNumber(double x_val, double el_val, double er_val) {
        if (!Init(x_val, el_val, er_val)) {
            x = 0.0;
            el = 0.0;
            er = 0.0;
        }
    }
    FuzzyNumber::FuzzyNumber(const FuzzyNumber& other) : x(other.x), el(other.el), er(other.er) {}
    FuzzyNumber::~FuzzyNumber() {}
    bool FuzzyNumber::Init(double x_val, double el_val, double er_val) {
        if (el_val >= 0 && er_val >= 0) {
            x = x_val;
            el = el_val;
            er = er_val;
            return true;
        }
        return false;
    }
    std::string FuzzyNumber::toString() const {
        std::stringstream ss;
        ss << "(" << (x - el) << ", " << x << ", " << (x + er) << ")";
        return ss.str();
    }
    FuzzyNumber FuzzyNumber::operator+(const FuzzyNumber& B) const {
        double left_bound = x + B.x - el - B.er;
        double center = x + B.x;
        double right_bound = x + B.x + er + B.er;
        return FuzzyNumber(center, center - left_bound, right_bound - center);
    }
    FuzzyNumber FuzzyNumber::operator-(const FuzzyNumber& B) const {
        double left_bound = x - B.x - el - B.er;
        double center = x - B.x;
        double right_bound = x - B.x + er + B.er;
        return FuzzyNumber(center, center - left_bound, right_bound - center);
    }
    FuzzyNumber FuzzyNumber::operator*(const FuzzyNumber& B) const {
        double center = x * B.x;
        double left_bound = center - B.x * el - x * B.el + el * B.el;
        double right_bound = center + B.x * el + x * B.el + el * B.el;
        return FuzzyNumber(center, center - left_bound, right_bound - center);
    }
    FuzzyNumber FuzzyNumber::operator/(const FuzzyNumber& B) const {
        if (B.x > 0 && (B.x - B.el) > 0) {
            double center = x / B.x;
            double left_bound = (x - el) / (B.x + B.er);
            double right_bound = (x + er) / (B.x - B.el);
            return FuzzyNumber(center, center - left_bound, right_bound - center);
        }
        else {
            std::cout << "Error: Division by zero or invalid bounds!\n";
            return FuzzyNumber();
        }
    }
    std::ostream& operator<<(std::ostream& out, const FuzzyNumber& A) {
        out << A.toString();
        return out;
    }
    std::istream& operator>>(std::istream& in, FuzzyNumber& A) {
        double x_val, el_val, er_val;
        do {
            std::cout << "Enter (x, e_l, e_r), e_l >= 0, e_r >= 0:\n";
            std::cout << "x = ";
            in >> x_val;
            std::cout << "e_l = ";
            in >> el_val;
            std::cout << "e_r = ";
            in >> er_val;
        } while (!A.Init(x_val, el_val, er_val));
        return in;
    }
}