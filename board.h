#ifndef _BOARD_
#define _BOARD_

// INCLUDES

#include "pieces.h"

// DEFINES

#define BOARD_LINE_WIDTH 6 // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16 // Width and Height of each block of a piece
#define BOARD_POSITION 320 // Center position of the board from the left of the screen
#define BOARD_WIDTH 10 // Board width in blocks
#define BOARD_HEIGHT 20 // Board height in blocks
#define MIN_VERTICAL_MARGIN 20 // Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20 // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5 // Number of horizontal and vertical blocks of a matrix piece

// BOARD
class Board{
    public:
        Board(Piece *p, int ScreenHeight);
        int GetXPosInPixels (int pPos);
        int GetYPosInPixels (int pPos);
        bool IsFreeBlock (int pX, int pY);
        bool IsPossibleMovement (int pX, int pY, int pPiece, int pRotation);
        void StorePiece (int pX, int pY, int pPiece, int pRotation);
        void DeletePossibleLines ();
        bool IsGameOver ();
    private:
        enum{POS_FREE, POS_FILLED};
        int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
        Piece *mPieces;
        int screenHeight;
        void initBoard();
        void deleteLine(int pY);
};
void Board::initBoard(){
    for (int i=0;i<BOARD_WIDTH;i++){
        for (int j=0;j<BOARD_HEIGHT; j++){
            mBoard[i][j] = POS_FREE;
        }
    }
}

#endif