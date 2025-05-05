#include <iostream>
#include <vector>

using namespace std;

void recur(vector<vector<int>> &v, int startx, int starty, int endx, int endy, int b) {
    if (startx == endx && starty == endy) {
        v[startx][starty] = b;
        return;
    }

    if (endx - startx == 1 && endy - starty == 1) {
        v[startx][starty] = b;
        v[startx][starty + 1] = b - 1;
        v[startx + 1][starty] = b + 1;
        v[startx + 1][starty + 1] = b;
        return;
    }

    int midx = (startx + endx) / 2;
    int midy = (starty + endy) / 2;

    recur(v, startx, starty, midx, midy, b);               // Top-left
    recur(v, startx, midy + 1, midx, endy, b-1);             // Top-right
    recur(v, midx + 1, starty, endx, midy, b+1);             // Bottom-left
    recur(v, midx + 1, midy + 1, endx, endy, b);           // Bottom-right
}

int main() {
    int r, b;
    cin >> r >> b;
    int row = 1 << r;
    vector<vector<int>> matrix(row, vector<int>(row, 0));

    recur(matrix, 0, 0, row - 1, row - 1, b);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
