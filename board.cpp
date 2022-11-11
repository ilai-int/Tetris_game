#include "board.h"

/*
======================================
Init the board blocks with free positions
======================================
*/
void Board::initBoard(){
    for (int i=0;i<BOARD_WIDTH;i++){
        for (int j=0;j<BOARD_HEIGHT; j++){
            mBoard[i][j] = POS_FREE;
        }
    }
}

/*

======================================
Store a piece in the board by filling the blocks

Parameters:

>> pX: Horizontal position in blocks
>> pY: Vertical position in blocks
>> pPiece: Piece to draw
>> pRotation: 1 of the 4 possible rotations
======================================
*/
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation){
    // Store each block of the piece into the board
    for (int i=pX;i< pX+PIECE_BLOCKS; i++){
        for (int j=pY;j<pY+PIECE_BLOCKS;j++){
            // Store only the blocks of the piece that are not holes
            if (all_pieces->get_block_type(pPiece, pRotation, i-pX, j-pY)>0){
                mBoard[i][j]=POS_FILLED;
            }
        }
    }
    
}
/*
======================================
Check if the game is over becase a piece have achived the upper position

Returns true or false
======================================
*/
bool Board::IsGameOver(){
    //If the first line has blocks, then, game over
    for(int i=0;i<BOARD_WIDTH;i++){
        if (mBoard[i][0] == POS_FILLED){
            return true;
        }
        return false;
    }
}
/*
======================================
Delete a line of the board by moving all above lines down

Parameters:

>> pY: Vertical position in blocks of the line to delete
======================================
*/

void Board::deleteLine(int pY){
    // Moves all the upper lines one row down
    for (int j=pY;j>0;j--){
        for (int i=0;i<BOARD_WIDTH;i++){
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}

/*
======================================
Delete all the lines that should be removed
======================================
*/

void Board::DeletePossibleLines(){
    for (int j=0; j<BOARD_HEIGHT; j++){
        int i=0;
        while(i<BOARD_WIDTH){
            if (mBoard[i][j] == POS_FREE){
                break;
            }
            i++;
        }

        if (i==BOARD_WIDTH){
            deleteLine(j);
        }
    }
}

/*
======================================
Returns 1 (true) if the this block of the board is empty, 0 if it is filled

Parameters:

>> pX: Horizontal position in blocks
>> pY: Vertical position in blocks
======================================
*/

bool Board::IsFreeBlock(int pX, int pY){
    if (mBoard[pX][pY] == POS_FREE){
        return true;
    }
    return false;
}

/*
======================================
Returns the horizontal position (in pixels) of the block given like parameter

Parameters:

>> pPos: Horizontal position of the block in the board
======================================
*/

int Board::GetXPosInPixels(int pPos){
    return ((BOARD_POSITION - (BLOCK_SIZE*(BOARD_WIDTH/2))) + (BLOCK_SIZE*pPos));
}

/*
======================================
Returns the vertical position (in pixels) of the block given like parameter

Parameters:

>> pPos: Horizontal position of the block in the board
======================================
*/

int Board::GetYPosInPixels(int pPos){
    return ((screenHeight - (BLOCK_SIZE*BOARD_HEIGHT))+(pPos*BLOCK_SIZE));
}

/*
======================================
Check if the piece can be stored at this position without any collision
Returns true if the movement is possible, false if it not possible

Parameters:

>> pX: Horizontal position in blocks
>> pY: Vertical position in blocks
>> pPiece: Piece to draw
>> pRotation: 1 of the 4 possible rotations
======================================
*/

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation){
    // Checks collision with pieces already stored in the board or the board limits
    // This is just to check the 5×5 blocks of a piece with the appropriate area in the board
    for (int i=pX;i< pX+PIECE_BLOCKS; i++){
        for (int j=pY;j<pY+PIECE_BLOCKS;j++){
            // Check if the piece is outside the limits of the board
            if ( i<0 || i > BOARD_WIDTH - 1 || j > BOARD_HEIGHT - 1){
                if (all_pieces->get_block_type(pPiece, pRotation, i-pX, j-pY)>0){
                    return false;
                }
            } 
            // Check if the piece have collisioned with a block already stored in the map
            if (all_pieces->get_block_type(pPiece, pRotation, i-pX, j-pY)>0 && !IsFreeBlock(i,j)){
                return false;
            }
        }
    }
    // No collision
    return true;
}