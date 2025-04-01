#include <iostream>
#include <vector>
using namespace std;

int check() {
	int t;
	cin >> t;
	if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
		cin.clear();
		cin.ignore(1000, '\n');
		return check();
	}
	return t;
}

class Stack {
private:
	vector<int>elements;
	vector<vector<int>>res;
	int c = 1;
	bool flag = true;
public:

	void start() {
		res.push_back(vector<int>());
		res[res.size() - 1].push_back(1);
		res[res.size() - 1].push_back(0);
	}

	void push(int value) {
		elements.push_back(value);
		res[res.size() - 1][1]++;
		if (elements[elements.size() - 1] == c) {
			res.push_back(vector<int>());
			res[res.size() - 1].push_back(2);
			res[res.size() - 1].push_back(0);
		}
		while (!elements.empty() && elements[elements.size() - 1] == c) {
			elements.pop_back();
			c += 1;
			res[res.size() - 1][1]++;
			flag = false;
		}
		if (!flag) {
			res.push_back(vector<int>());
			res[res.size() - 1].push_back(1);
			res[res.size() - 1].push_back(0);
			flag = true;
		}
	}


	void get_ans(int n) {
		if (res[res.size() - 1][1] == 0) {
			res.pop_back();
		}
		if (c != n+1) {
			cout << 0;
		}
		else {
			cout << res.size() << endl;
			for (int i = 0; i < res.size(); ++i) {
				cout << res[i][0] << " " << res[i][1];
				if (i < (res.size() - 1)) {
					cout << endl;
				}
			}
		}
	}
};

int main()
{
	int n = check();
	Stack Alina;
	Alina.start();
	for (int i = 0; i < n; ++i) {
		Alina.push(check());
	}
	Alina.get_ans(n);
	return 0;
}
