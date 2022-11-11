#include "board.h"

void Board::initBoard(){
    for (int i=0;i<BOARD_WIDTH;i++){
        for (int j=0;j<BOARD_HEIGHT; j++){
            mBoard[i][j] = POS_FREE;
        }
    }
}
