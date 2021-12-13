#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

struct Move {
    int row, col;
};

char player {'x'};
char opponent {'o'};

bool isMovesLeft(char board[3][3]) {
    for (int i{}; i < 3; i++)
        for (int j{}; j < 3; j++) if (board[i][j] == '_') return true;
    return false;
}

int evaluate(char b[3][3]) {
    for (int row{}; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == player) return +10;
            else if (b[row][0] == opponent) return -10;
        }
    }

    for (int col{}; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == player) return +10;
            else if (b[0][col] == opponent) return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == player) return +10;
        else if (b[0][0] == opponent) return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == player) return +10;
        else if (b[0][2] == opponent) return -10;
    }

    return 0;
}

int minimax(char board[3][3], int depth, bool isMax) {
    int score {evaluate(board)};
    if (score == 10) return score;
    if (score == -10) return score;
    if (isMovesLeft(board) == false) return 0;
    if (isMax) {
        int best { -1000};
        for (int i{}; i < 3; i++) {
            for (int j{}; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    best = max(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        int best {1000};
        for (int i{}; i < 3; i++) {
            for (int j{}; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    best = min(best,minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

Move findBestMove(char board[3][3]) {
    int bestVal {-1000};
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {

            if (board[i][j] == '_') {
                board[i][j] = player;
                int moveVal {minimax(board, 0, false)};
                board[i][j] = '_';
                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    cout << bestVal << " ";
    return bestMove;
}

int main() {
    char board[3][3];
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) board[i][j] = '_';
    }

    int n;
    cin >> n;
    while (n--) {
        int row, column;
        char player;
        cin >> row >> column >> player;
        board[row][column] = player;
    }
    Move best_move {findBestMove(board)};
    cout << "row: " << best_move.row << " " << "col: " << best_move.col << endl;
}
