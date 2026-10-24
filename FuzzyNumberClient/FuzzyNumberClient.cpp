#include <iostream>
#include "FuzzyNumber.h"
using namespace std;

int main() {
    cout << "Demonstration of FuzzyNumber Static Library\n";
    FuzzyLib::FuzzyNumber A(5.0, 1.0, 2.0);
    FuzzyLib::FuzzyNumber B(3.0, 0.5, 1.0);

    cout << "Number A" << A << endl;
    cout << "Number B" << B << endl << endl;

    cout << "Arithmetic Operations" << endl;

    FuzzyLib::FuzzyNumber sum = A + B;
    cout << "A + B = " << sum << endl;

    FuzzyLib::FuzzyNumber diff = A - B;
    cout << "A - B = " << diff << endl;

    FuzzyLib::FuzzyNumber prod = A * B;
    cout << "A * B = " << prod << endl;

    FuzzyLib::FuzzyNumber div = A / B;
    cout << "A / B = " << div << endl;
    return 0;
}