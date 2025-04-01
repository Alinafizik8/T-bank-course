#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMin(int N, int K, const vector<int>& sequence) {
    deque<int> dq; // Двусторонняя очередь для хранения индексов
    vector<int> result; // Вектор для хранения результатов

    for (int i = 0; i < N; ++i) {
        // Удаляем индексы, которые вышли за пределы окна
        while (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // Удаляем индексы, значения которых больше или равны текущему элементу
        while (!dq.empty() && sequence[dq.back()] >= sequence[i]) {
            dq.pop_back();
        }

        // Добавляем текущий индекс в очередь
        dq.push_back(i);

        // Если окно сформировано, добавляем минимум в результат
        if (i >= K - 1) {
            result.push_back(sequence[dq.front()]);
        }
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    // Вычисляем минимумы для каждого окна
    vector<int> minima = slidingWindowMin(N, K, sequence);

    // Выводим результаты
    for (int i = 0; i < minima.size();++i) {
        cout << minima[i];
        if (i != minima.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
