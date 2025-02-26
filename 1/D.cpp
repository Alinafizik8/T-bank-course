#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double eps = 0.000001;

bool Eplips(double C, double v, const double eps) {
    return (fabs(C - v) < eps);
}

double check() {
    double t;
    cin >> t;
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error!";
        return check();
    }
    return t;
}

int Square(double C) {
    double left = 0;
    double right = C;
    bool flag = true;
    while (flag) {
        double mid = left + (right - left) / 2;
        double prim = ((mid * mid) + sqrt(1 + mid));

        if (Eplips(C,prim,eps)) {
            cout << setprecision(20) << mid;
            flag = false;
        }
        else if (prim<C) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return 0;
}

int main()
{
    double C;
    C = check();
    Square(C);
    return 0;
}
