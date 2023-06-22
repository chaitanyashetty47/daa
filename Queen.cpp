#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<bool>>& board, int row, int col) {
    // Check upper areas
    for (int i = row; i >= 0; i--) {
        if (board[i][col]) {
            return false;
        }
    }

    int r = row;
    int c = col;

    // Check diagonal left
    while (r >= 0 && c >= 0) {
        if (board[r][c]) {
            return false;
        }
        r--;
        c--;
    }

    int rr = row;
    int cr = col;

    // Check diagonal right
    while (rr >= 0 && cr < board[0].size()) {
        if (board[rr][cr]) {
            return false;
        }
        rr--;
        cr++;
    }

    return true;
}

void display(vector<vector<bool>>& board) {
    for (vector<bool>& row : board) {
        for (bool ele : row) {
            if (ele) {
                cout << "Q ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int nQueen(vector<vector<bool>>& board, int row) {
    if (row == board.size()) {
        display(board);
        return 1;
    }

    int count = 0;

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            count += nQueen(board, row + 1);
            board[row][col] = false;
        }
    }

    return count;
}

int main() {
    int n = 5;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    cout << nQueen(board, 0) << endl;

    return 0;
}

