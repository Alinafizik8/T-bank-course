#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> SplitPhrase(string input) {

	istringstream iss(input);
	string temp;
	vector<string> result;

	while (iss >> temp) {
		result.push_back(temp);
	}
	return result;
}

class Stack {
private:
	vector<string>alls;
	vector<int>pro_resls;
public:
	void push(string value) {
		alls.push_back(value);
	}

	int maths() {
		int res = 0;
		for (int i = 0; i < alls.size();++i) {
			if (!isdigit(alls[i][0]) && alls[i].size()<2) {
				/*if (isdigit(alls[i+1][0]) || alls[i+1].size() == 2) {
					switch (alls[i][0]) {
					case '+':
						res = stoi(alls[i + 1]) + stoi(alls[i + 2]);
						pro_resls.push_back(res);
						break;
					case '-':
						res = stoi(alls[i + 2]) - stoi(alls[i + 1]);
						pro_resls.push_back(res);
						break;
					case '*':
						res = stoi(alls[i + 1]) * stoi(alls[i + 2]);
						pro_resls.push_back(res);
						break;
					}
				}
				else {
					for (int u = 0; u < (2 - (alls.size() - 1 - i)); ++u) {

					}
				}*/
				switch (alls[i][0]) {
				case '+':
					res = pro_resls[pro_resls.size()-2] + pro_resls[pro_resls.size() - 1];
					pro_resls.pop_back();
					pro_resls.pop_back();
					pro_resls.push_back(res);
					break;
				case '-':
					res = pro_resls[pro_resls.size() - 2] - pro_resls[pro_resls.size() - 1];
					pro_resls.pop_back();
					pro_resls.pop_back();
					pro_resls.push_back(res);
					break;
				case '*':
					res = pro_resls[pro_resls.size() - 2] * pro_resls[pro_resls.size() - 1];
					pro_resls.pop_back();
					pro_resls.pop_back();
					pro_resls.push_back(res);
					break;
				}
			}
			else {
				pro_resls.push_back(stoi(alls[i]));
			}
		}
		return res;
	}
};

int main()
{
	string line;
	getline(cin,line);
	vector<string>elements = SplitPhrase(line);
	Stack Alina;
	for (string b : elements) {
		Alina.push(b);
	}
	cout << Alina.maths();
	return 0;
}

