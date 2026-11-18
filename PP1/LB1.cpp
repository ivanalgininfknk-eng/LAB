#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>
using namespace std;

// Create a function to calculate the mathematical expression
double f(double x) {
    return cos(3.0 / 55.0) - 25.0 * numbers::pi
        + 45.0 * numbers::e * 4.0 / ((x - 9.0) * (x - 15.0))
        + 8.0 * atan(1.0 / (x - 13.0)) 
        + 1.0 / sqrt(x - 14.0);
}
bool Range(double x) {
    return x > 14.0 && x != 15.0;
}
int main() {
    cout << "Author: Alhinin Ivan" << endl;
    cout << "Calculation of a mathematical expression by given x: variant 157"<< endl;

    double x;
    cout << "Enter x (x > 14, x != 15): ";
    cin >> x;

    if (cin.fail()) {
        cout << "wrong input" << endl;
    } 
    else {
        cout << "***** do calculations ... ";
        const bool defined = Range(x);
        double result = f(x);

        cout << "done"<< endl;
        cout << "for x = " << fixed << setprecision(5)<< x << endl;
        
        if (defined) {
            cout << "result = " << setprecision(9)<< result << endl;
        }
        else {
            cout << "result = undefined" << endl;
        }
    }
}
