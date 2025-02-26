#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Избегаем переполнения

        if (arr[mid] == target) {
            return true; // Найден элемент
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой части
        }
        else {
            right = mid - 1; // Ищем в левой части
        }
    }
    return false; // Элемент не найден
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
    vector<int> nombers(n);
    vector<int> ques(k);
    for (int i = 0; i < n; ++i) {
        nombers[i] = check();
    }
    for (int i = 0; i < k; ++i) {
        ques[i] = check();
    }
    int c = 0;
    for (const int& query : ques) {
        if (binarySearch(nombers,query)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        c += 1;
        if (c!=k) {
            cout << endl;
        }
    }
    return 0;
}
