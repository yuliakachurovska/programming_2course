#include <iostream>
#include <vector>
#include <algorithm> // Для sort
#include <limits>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int p, t;

    cout << "Enter number of rows (p): ";
    cin >> p;
    cout << "Enter number of columns (t): ";
    cin >> t;

    if (p < 1 || p > 100 || t < 1 || t > 100) {
        cout << "p and t must be natural numbers <= 100." << endl;
        return 1;
    }
    vector<vector<int>> matrix(p, vector<int>(t));

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < t; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<pair<int, vector<int>>> rowsWithMax;
    for (const auto& row : matrix) {
        int maxElem = *max_element(row.begin(), row.end()); // Знаходимо максимальний елемент в рядку
        rowsWithMax.push_back(make_pair(maxElem, row));
    }

    sort(rowsWithMax.begin(), rowsWithMax.end(), [](const auto& a, const auto& b) {
        return a.first > b.first; // Сортуємо за спаданням
    });

    vector<vector<int>> sortedMatrix;
    for (const auto& pair : rowsWithMax) {
        sortedMatrix.push_back(pair.second);
    }
    cout << "Sorted matrix:" << endl;
    printMatrix(sortedMatrix);
}
