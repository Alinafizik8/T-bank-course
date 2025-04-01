#include <iostream>
#include <vector>
using namespace std;

int check() {
    int t;
    cin >> t;
    if ((!cin) || (cin.peek() != '\n' && cin.peek()!=' ')) {
        cin.clear();
        cin.ignore(1000, '\n');
        return check();
    }
    return t;
}

class Stack {
private:
    vector<int>elements;
    vector<int>mins;
public:
    void start() {
        mins.push_back(2000000000);
    }

    void push(int value) {
        elements.push_back(value);
        if (mins[mins.size() - 1] >= value) {
            mins.push_back(value);
        }
    }

    void pop() {
        if (mins[mins.size() - 1] == elements[elements.size() - 1]) {
            mins.pop_back();
        }
        elements.pop_back();
    }

    int min_element() {
        return mins[mins.size() - 1];
    }
};

int main() {
    Stack Alina;
    int n = check();
    Alina.start();
    vector<int>resls;
    for (int i = 0; i < n; ++i) {
        switch (check()) {
        case(1):
            Alina.push(check());
            break;
        case(2):
            Alina.pop();
            break;
        default:
            resls.push_back(Alina.min_element());
            break;
        }
    }
    for (int i = 0; i < resls.size(); ++i) {
        cout << resls[i];
        if (i != resls.size() - 1) {
            cout << endl;
        }
    }
    return 0;
}
