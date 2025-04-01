//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Stack {
//private:
//	vector<int>ids;
//	vector<int>res;
//	int start = 0;
//public:
//
//	void push(int value) {
//		ids.push_back(value);
//	}
//
//	void star() {
//		start += 1;
//	}
//
//	void pop() {
//		ids.pop_back();
//	}
//
//	void how(int q) {
//		int i = start;
//		while (ids[i++]!=q) {}
//		res.push_back(i - start - 1);
//	}
//
//	void who() {
//		res.push_back(ids[start]);
//	}
//
//	void show() {
//		for (int i = 0; i < res.size(); ++i) {
//			cout << res[i];
//			if (i!=res.size()-1) {
//				cout << endl;
//			}
//		}
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Stack Alina;
//	for (int i = 0; i < n; ++i) {
//		int y,k;
//		cin >> y;
//		switch (y) {
//		case 1:
//			cin >> k;
//			Alina.push(k);
//			break;
//		case 2:
//			Alina.star();
//			break;
//		case 3:
//			Alina.pop();
//			break;
//		case 4:
//			cin >> k;
//			Alina.how(k);
//			break;
//		case 5:
//			Alina.who();
//			break;
//		}
//	}
//	Alina.show();
//	return 0;
//}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Функция для вычисления глубины каждой вершины
void computeDepths(const vector<vector<int>>& tree, vector<int>& depths, int node, int currentDepth) {
    depths[node] = currentDepth;
    for (int child : tree[node]) {
        computeDepths(tree, depths, child, currentDepth + 1);
    }
}

// Функция для поиска самой дальней вершины от заданной
pair<int, int> findFarthestNode(const vector<vector<int>>& tree, int start) {
    vector<int> distances(tree.size(), -1);
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    int farthestNode = start;
    int maxDistance = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : tree[node]) {
            if (distances[child] == -1) {
                distances[child] = distances[node] + 1;
                q.push(child);

                if (distances[child] > maxDistance) {
                    maxDistance = distances[child];
                    farthestNode = child;
                }
            }
        }
    }

    return { farthestNode, maxDistance };
}

int main() {
    int n;
    cin >> n;

    // Построение дерева
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    // Вычисление глубины каждой вершины
    vector<int> depths(n, 0);
    computeDepths(tree, depths, 0, 0);

    // Нахождение высоты дерева
    int height = *max_element(depths.begin(), depths.end());

    // Нахождение диаметра дерева
    auto farthestNode1 = findFarthestNode(tree, 0).first;
    auto _ = findFarthestNode(tree, 0).second;
    auto farthestNode2 = findFarthestNode(tree, farthestNode1).first;
    auto diameter = findFarthestNode(tree, farthestNode1).second;

    // Вывод результатов
    cout << height << " " << diameter << endl;
    for (int depth : depths) {
        cout << depth << " ";
    }
    cout << endl;

    return 0;
}
