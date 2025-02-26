#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
using namespace std;

double pp(double a, double b, double c) {
    return ((-((b*b)/(3*a*a)))+(c/a));
}

double qq(double a, double b, double c, double d) {
    return (((2*pow(b,3))/(27*pow(a,3))) - ((b*c)/(3*a*a)) + (d/a));
}

double check() {
    double t;
    cin >> t;
    if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error!";
        return check();
    }
    return t;
}

void Square(double a, double b, double c, double d) {
    double q = qq(a, b, c, d);
    double p = pp(a, b, c);
    double x = (cbrt((-q / 2) + sqrt((q * q / 4) + (pow(p, 3) / 27))) + cbrt((-q / 2) - sqrt((q * q / 4) + (pow(p, 3) / 27)))) - (b/(3*a));
    cout << x;
}

int main()
{
    double a,b,c,d;
    a = check();
    b = check();
    c = check();
    d = check();
    Square(a,b,c,d);
    return 0;
}
