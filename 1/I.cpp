#include <iostream>
#include <vector>
using namespace std;

int check() {
    int t;
    cin >> t;
    if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
        cin.clear();
        cin.ignore(1000,'\n');
        return check();
    }
    return t;
}

void change(vector<int>&c,int p) {
    c[p - 1] = 1;
}

int main()
{
    bool flag = true;
    int n;
    n = check();
    int gran = n-1;//позиция самого правого нуля
    vector <int> nulls(n);
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
        nulls[i] = check();
        pos[i] = 0;
    }
    cout << 1 << " ";
    for (int i = 0; i < n; ++i) {
        change(pos, nulls[i]);
        for (int j = gran; j >=0 && flag ; --j) {
            if (pos[j] == 0) {
                gran = j;
                flag = false;
            }
        }
        flag = true;
        if (i != (n - 1)) {
            cout << (i + 1) - (n - 1 - gran) + 1;
            cout << " ";
        }
        else {
            cout << 1;
        }
    }
}
