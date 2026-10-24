#ifndef FUZZYNUMBER_H
#define FUZZYNUMBER_H
#include <string>
#include <iostream>

namespace FuzzyLib {
    class FuzzyNumber {
    private:
        double x;  // Center value
        double el; // Left error (e_l)
        double er; // Right error (e_r)
    public:
        FuzzyNumber();
        FuzzyNumber(double x_val, double el_val, double er_val);
        FuzzyNumber(const FuzzyNumber& other);
        ~FuzzyNumber();

        double getX() const { return x; }
        double getEl() const { return el; }
        double getEr() const { return er; }

        void setX(double value) { x = value; }
        void setEl(double value) { el = value; }
        void setEr(double value) { er = value; }

        bool Init(double x_val, double el_val, double er_val);
        std::string toString() const;
        // Перевантажені операції
        FuzzyNumber operator+(const FuzzyNumber& B) const;
        FuzzyNumber operator-(const FuzzyNumber& B) const;
        FuzzyNumber operator*(const FuzzyNumber& B) const;
        FuzzyNumber operator/(const FuzzyNumber& B) const;

        friend std::ostream& operator<<(std::ostream& out, const FuzzyNumber& A);
        friend std::istream& operator>>(std::istream& in, FuzzyNumber& A);
    };
}

#endif
