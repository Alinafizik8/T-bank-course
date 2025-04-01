#include <iostream>
#include <vector>
using namespace std;

int check() {
	int t;
	cin >> t;
	if (cin.fail() || (cin.peek()!='\n' && cin.peek()!=' ')) {
		cin.clear();
		cin.ignore(1000, '\n');
		return check();
	}
	return t;
}

class Stack {
private:
	vector<int>elements;
	vector<int>cs;
	int c;
	int res;
public:

	Stack() : c(1), cs(), res(0), elements() {};

	void pushstrarts(int value) {
		elements.push_back(value);
		cs.push_back(1);
	}

	void push(int value) {
		if (elements[elements.size() - 1] == value) {
			c += 1;
			cs.push_back(c);
		}
		else {
			if (c >= 3) {
				for (int y = 0; y < c; ++y) {
					elements.pop_back();
					cs.pop_back();
					res += 1;
				}
				if (cs.size() >= 1) {
					c = cs[cs.size() - 1];
					if (elements[elements.size() - 1] == value && elements.size() > 0) {
						c += 1;
						cs.push_back(c);
					}
				}
				else {
					c = 1;
					cs.push_back(c);
				}
			}
			else {
				c = 1;
				cs.push_back(c);
			}
		}
		elements.push_back(value);
	}

	void end() {
		if (c >= 3) {
			for (int y = 0; y < c; ++y) {
				res += 1;
			}
		}
	}

	int result() {
		return res;
	}
};

int main() 
{
	int n = check();
	Stack Alina;
	Alina.pushstrarts(check());
	for (int i = 1; i < n; ++i) {
		Alina.push(check());
	}
	Alina.end();
	cout << Alina.result();
	return 0;
}
