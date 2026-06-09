#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <windows.h> 

using namespace std;

void solve(int n) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        q.push(i);
    }

    vector<string> result(n);
    bool isWhite = true;

    while (!q.empty()) {
        int current_index = q.front();
        q.pop();

        result[current_index] = isWhite ? "Белая" : "Черная";
        isWhite = !isWhite;

        if (!q.empty()) {
            int next_index = q.front();
            q.pop();
            q.push(next_index);
        }
    }

    cout << "Исходное расположение карточек в стопке (от верхней к нижней):\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "-я карточка: " << result[i] << "\n";
    }
}

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    cout << "Введите количество карточек (n): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Ошибка ввода. Введите положительное число.\n";
        return 1;
    }

    solve(n);


    cout << "\nЛобанкин Денис Витальевич РПИ-Б\n";

    cout << "\nНажмите Enter для завершения программы...";
    cin.ignore(10000, '\n');
    cin.get(); 

    return 0;
}
