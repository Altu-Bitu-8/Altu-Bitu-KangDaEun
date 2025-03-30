#include <iostream>
#include <string>

using namespace std;

int king_col, king_row, rock_col, rock_row;

bool isCollision() {
    if (king_col == rock_col && king_row == rock_row) {
        return true;
    }
    return false;
}

bool isOut() {
    if (king_col < 0 || king_col > 7) return true;
    if (king_row < 0 || king_row > 7) return true;
    if (rock_col < 0 || rock_col > 7) return true;
    if (rock_row < 0 || rock_row > 7) return true;
    return false;
}


void move(string dir) {

    if (dir == "R") {
        king_col++;
        if (isOut()) king_col--;
        if (isCollision()) {
            rock_col++;
            if (isOut()) {
                king_col--;
                rock_col--;
            }
        }
    }
    if (dir == "L") {
        king_col--;
        if (isOut()) king_col++;
        if (isCollision()) {
            rock_col--;
            if (isOut()) {
                king_col++;
                rock_col++;
            }
        }
    }
    if (dir == "B") {
        king_row++;
        if (isOut()) king_row--;
        if (isCollision()) {
            rock_row++;
            if (isOut()) {
                king_row--;
                rock_row--;
            }
        }
    }
    if (dir == "T") {
        king_row--;
        if (isOut()) king_row++;
        if (isCollision()) {
            rock_row--;
            if (isOut()) {
                king_row++;
                rock_row++;
            }
        }
    }
    if (dir == "RT") {
        king_col++;
        king_row--;
        if (isOut()) {
            king_col--;
            king_row++;
        }
        if (isCollision()) {
            rock_col++;
            rock_row--;
            if (isOut()) {
                king_col--;
                king_row++;
                rock_col--;
                rock_row++;
            }
        }
    }
    if (dir == "RB") {
        king_col++;
        king_row++;
        if (isOut()) {
            king_col--;
            king_row--;
        }
        if (isCollision()) {
            rock_col++;
            rock_row++;
            if (isOut()) {
                king_col--;
                king_row--;
                rock_col--;
                rock_row--;
            }
        }
    }
    if (dir == "LT") {
        king_col--;
        king_row--;
        if (isOut()) {
            king_col++;
            king_row++;
        }
        if (isCollision()) {
            rock_col--;
            rock_row--;
            if (isOut()) {
                king_col++;
                king_row++;
                rock_col++;
                rock_row++;
            }
        }
    }
    if (dir == "LB") {
        king_col--;
        king_row++;
        if (isOut()) {
            king_col++;
            king_row--;
        }
        if (isCollision()) {
            rock_col--;
            rock_row++;
            if (isOut()) {
                king_col++;
                king_row--;
                rock_col++;
                rock_row--;
            }
        }
    }
}

int main()
{
    string king, rock;

    int n;
    int king_loc = 1;
    int rock_loc = -1;

    string dir;

    cin >> king >> rock >> n;

    king_col = king[0] - 'A';
    king_row = '8' - king[1];
    rock_col = rock[0] - 'A';
    rock_row = '8' - rock[1];

    while (n--) {
        cin >> dir;

        /*if (dir[0] == 'R') {
            move("R");
            if (dir[1] == 'T') {
                cout << "1\n";
                move("T");
            }
            if (dir[1] == 'B') {
                cout << "3\n";
                move('B');
            }

        }*/
        /*if (dir[0] == 'L') {
            move('L');
            if (dir[1] == 'T') move('T');
            if (dir[1] == 'B') move('B');
        }*/

        move(dir);

    }

    char king_col_char = king_col + 'A';
    char king_row_char = '8' - king_row;
    char rock_col_char = rock_col + 'A';
    char rock_row_char = '8' - rock_row;

    king = string(1, king_col_char) + king_row_char;
    rock = string(1, rock_col_char) + rock_row_char;

    cout << king << "\n";
    cout << rock;
}

