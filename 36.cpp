#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    //rows
    for(int i = 0; i<board.size(); i++){
        unordered_set<char> present;
        for(int j = 0; j<board[0].size(); j++){
            if(present.find(board[i][j])!=present.end())
                return false;
            if(board[i][j] != '.')
                present.insert(board[i][j]);
        }
    }
    //columns
    for(int i = 0; i<board.size(); i++){
        unordered_set<char> present;
        for(int j = 0; j<board[0].size(); j++){
            if(present.find(board[j][i])!=present.end())
                return false;
            if(board[j][i] != '.')
                present.insert(board[j][i]);
        }
    }
    //squares
    for(int iOff = 0; iOff<3; iOff++){
        for(int jOff=0; jOff<3; jOff++){
            unordered_set<char> present;
            for(int i=0; i<3; i++){
                for(int j = 0; j<3; j++){
                    char c = board[iOff*3 + i][jOff*3 + j];
                    if(present.find(c)!=present.end())
                        return false;
                    if(c != '.')
                        present.insert(c);
                }
            }
        }
    }
    return true;
}
int main(){
    vector<vector<char>> cs = {{'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','8','.','.','7','9'}};
    cout << (isValidSudoku(cs) ? "true" : "false");
    return 0;

}