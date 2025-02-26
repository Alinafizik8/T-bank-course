#include <iostream>
#include <vector>
using namespace std;

int c = { 0 };

int check() {
    int t;
    cin >> t;
    if (cin.fail() || (cin.peek()!='\n' && cin.peek() != ' ')) {
        cin.clear();
        cin.ignore(1000, '\n');
        return check();
    }
    return t;
}

vector<int> merge(vector<int> l, vector<int> r) {
    int L = l.size();
    int R = r.size();
    vector<int> res;
    int tl = 0;
    int tr = 0;
    while (L > 0 && R > 0) {
        if (l[tl] <= r[tr]) {
            res.push_back(l[tl]);
            L -= 1;
            tl += 1;
        }
        else {
            c += L;
            res.push_back(r[tr]);
            R -= 1;
            tr += 1;
        }
    }
    if (L > 0) {
        for (int i = tl; i < l.size(); ++i) {
            res.push_back(l[i]);
        }
    }
    if (R > 0) {
        for (int i = tr; i < r.size(); ++i) {
            res.push_back(r[i]);
        }
    }
    return res;
}//функция сортирующая элементы из двух векторов в результирующий

vector<int> slianie(vector<int> s) {
    int n = s.size();
    if (n <= 1) {
        return s;
    }
    else {
        int mid = n / 2;
        vector<int> dm;
        vector<int> pm;
        for (int i = 0; i < mid; ++i) {
            dm.push_back(s[i]);
        }
        for (int i = mid; i < n; ++i) {
            pm.push_back(s[i]);
        }
        auto left = slianie(dm);
        auto right = slianie(pm);
        return merge(left, right);
    }
}//фукнция, делящая вектор пополам, пока не останется два единичных вектора

int main()
{
    int n;
    n = check();
    vector<int>sortirovOchki(n);
    for (int i = 0; i < n; ++i) {
        sortirovOchki[i] = check();
    }
    sortirovOchki = slianie(sortirovOchki);
    cout << c << endl;
    for (int i = 0; i < n; ++i) {
        cout << sortirovOchki[i];
        if (i < (n - 1)) {
            cout << " ";
        }
    }
}
