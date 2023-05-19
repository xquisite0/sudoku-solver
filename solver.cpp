#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<vector<char> >& b, int x, int y, char n) {
    for (int i = 0; i < 9; i++) {
        if (b[i][y] == n) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (b[x][i] == n) return false;
    }
    
    int nx = x / 3 * 3;
    int ny = y / 3 * 3;
    for (int i = nx; i < nx+3; i++) {
        for (int j = ny; j < ny+3; j++) {
            //  cout << nx << " " << ny << "|";
            if (b[i][j] == n) return false;
        }
    }
    return true;
}
bool solve(vector<vector<char> >& b, int x, int y) {
    if (x == 9) return true;
    if (y == 9) return solve(b,x+1, 0);
    if (b[x][y] != '.') return solve(b,x, y+1);
    
    for (char i = '1'; i <='9'; i++) {
        //  cout << "\n";
        if (valid(b,x, y, i)) {
            b[x][y] = i;
            if (solve(b, x, y+1)) return true;
            b[x][y] = '.';
        }
    }
    return false;
}
bool solveSudoku(vector<vector<char> >& board) {
    return solve(board, 0, 0);
}

int main() {
    cout << "Please input the 9 x 9 sudoku board line-by-line. (Empty grids as '.')\n";
    vector<vector<char> > board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;
        if (line.length() != 9) {
            cout << "Please input a valid row\n";
            cin >> line;
        }
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j];
        }
    }
    cout << "\n";
    if (!solveSudoku(board)) {
        cout << "Invalid puzzle.\n";
    } else {
        cout << "Solution.\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

}
