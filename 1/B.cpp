#include <iostream>
#include <vector>
using namespace std;

int ste(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

bool ram(vector <int>& n, int u) {
    if ((n[n.size() - 1] < u) || (n[0] > u)) {
        return false;
    }
    else {
        return true;
    }
}

vector<int> binarySearch(const vector<int>& arr, int target) {
    vector<int> res;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            res.push_back(1);
            res.push_back(mid);
            return res;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    res.push_back(0);
    res.push_back(left);
    return res;
}

int check() {
    int t;
    cin >> t;
    if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
        cin.clear();
        cout << "Error!\n";
        cin.ignore(10000, '\n');
        return check();
    }
    return t;
}

int main()
{
    int n, k;
    n = check();
    k = check();
    vector<int> numbers(n);
    vector<int> ques(k);
    for (int i = 0; i < n; ++i) {
        numbers[i] = check();
    }
    for (int i = 0; i < k; ++i) {
        ques[i] = check();
    }
    int c = 0;
    for (const int& query : ques) {
        vector<int>u = binarySearch(numbers, query);
        if (u[0]) {
            cout << numbers[u[1]];
        }
        else {
            if (!ram(numbers, query)) {
                if (query > numbers[0]) {
                    cout << numbers[numbers.size()-1];
                }
                else {
                    cout << numbers[0];
                }
            }
            else {
                int sravn = ste(10, 7);
                int b = -1;
                if (u[1] > 0 && u[1]<(numbers.size()-1)) {
                    for (int i = 2; i>=0 ; --i) {
                        b = (abs(numbers[u[1] - 1 + i] - query) <= sravn) ? u[1] - 1 + i : b;
                        sravn = (abs(numbers[u[1] - 1 + i] - query) <= sravn)? abs(numbers[u[1] - 1 + i] - query) : sravn;
                    }
                }
                else if (u[1]==0) {
                    for (int i = 0; i < 2; ++i) {
                        b = (abs(numbers[u[1] + i] - query) <= sravn) ? u[1] + i : b;
                        sravn = (abs(numbers[u[1] + i] - query) <= sravn) ? abs(numbers[u[1] + i] - query) : sravn;
                    }
                }
                else {
                    for (int i = 0; i < 2; ++i) {
                        b = (abs(numbers[u[1] - i] - query) <= sravn) ? u[1] - i : b;
                        sravn = (abs(numbers[u[1] - i] - query) <= sravn) ? abs(numbers[u[1] - i] - query) : sravn;
                    }
                }
                cout << numbers[b];
            }
        }
        c += 1;
        if (c != k) {
            cout << endl;
        }
    }
    return 0;
}
