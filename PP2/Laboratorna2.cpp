#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

// Create a function to calculate the mathematical expression
double s(double x, double eps) noexcept {
    double x0 = 1.0;
    double sum = 1.0;
    const double minusx2 = -x*x;
    int n =0;
    while (x0 <= -eps or x0 >= eps) {
        x0 *= minusx2 / ((4*n+1.0)*(4*n+2.0)*(4*n+3.0)*(4*n+4.0));
        sum += x0;
        n++;
    }
    return sum;
}

void checkx(double x){
    if (!(x >= 0 && x <= 1)){
            throw invalid_argument("x must be in diapason [0, 1]");
        }

}

void checkeps(double eps){
    if (!(eps > 0)){
            throw invalid_argument("epsilon must be > 0");
        }

}

void checkcin(double& value) {
    cin >> value;

    if (cin.fail()) {
        throw invalid_argument("invalid input");
    }

    string rest;
    getline(cin, rest);

    if (rest.find_first_not_of(" \t\r") != string::npos) {
        throw invalid_argument("extra characters after number");
    }
}



int main() {
    cout << "Author: Alhinin Ivan" << endl;
    cout << "Calculation of a mathematical expression by given x: variant 157"<< endl;


    try{
        double x;
        cout << "Enter x in diapason [0, 1] use point not comma: ";

        checkcin(x);
        checkx(x);


        double eps;
        cout << "\nEnter epsilon > 0 for calculation use point not comma: ";

        checkcin(eps);
        checkeps(eps);
        


        cout << "\n***** do calculations ... " ;
        double result = s(x, eps);
        cout << "done"<< endl;

        cout << "for x = " << uppercase << scientific << setprecision(7)<< x << endl; 
        cout << "for eps = " << uppercase << scientific << setprecision(9)<< eps << endl;
        cout << "result = " << fixed << setprecision(8)<< result << endl;
    }
    catch (const invalid_argument& e){
        cout << "\n*****error: " << e.what() << endl;
    }
}