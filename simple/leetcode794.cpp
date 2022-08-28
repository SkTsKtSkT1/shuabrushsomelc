//
// Created by lzw on 2022/8/28.
//

#include "leetcode794.h"


bool leetcode794::validTicTacToe(std::vector<std::string> &board) {
    int xCnt=0;
    int oCnt=0;
    bool xWin=win(board,'X');
    bool oWin=win(board,'O');
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='X') xCnt++;
            if(board[i][j]=='O') oCnt++;
        }
    }
    if(!xWin && !oWin && (xCnt==oCnt || xCnt==(oCnt+1))){
        return true;
    }
    if(xCnt==oCnt && oWin &&!xWin){
        return true;
    }
    if(xCnt==(oCnt+1)&& xWin && !oWin){
        return true;
    }
    return false;
}

bool leetcode794::win(std::vector<std::string> &board, char p) {
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p
            || board[i][0] == p && board[i][1] == p && board[i][2] == p) {
            return true;
        }//三行三列
        return (board[0][0] == p && board[1][1] == p && board[2][2] == p)
               || (board[2][0] == p && board[1][1] == p && board[0][2] == p);//对角线
    }
}