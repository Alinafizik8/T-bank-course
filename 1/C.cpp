#include <iostream>
#include <string>
using namespace std;

bool am() {
    string line;
    getline(cin, line);
    if (line == ">=") {
        return true;
    }
    else {
        return false;
    }
}

int check() {
    int t;
    cin >> t;
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error!";
        return check();
    }
    return t;
}

void search(int& n) {
    int left = 1;
    int right = n;
    cout << right << endl;
    fflush(stdout);
    if (!am()) {
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            cout << mid << endl;
            fflush(stdout);
            if (am()) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        cout << "! " << left;
    }
    else {
        cout << "! " << right;
    }
}

int main()
{
    int n;
    n = check();
    cin.ignore(1000, '\n');
    search(n);
    return 0;
}
