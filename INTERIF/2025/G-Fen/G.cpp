#include <bits/stdc++.h>
using namespace std;

int main() {
    string fen;
    cin >> fen;

    vector<vector<char>> board(8, vector<char>(8, ' '));
    int row = 0, col = 0;

    for (char c : fen) {
        if (c == '/') {
            row++;
            col = 0;
        }
        else if (isdigit(c)) {
            col += c - '0';
        }
        else {
            board[row][col] = c;
            col++;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }

    return 0;
}
