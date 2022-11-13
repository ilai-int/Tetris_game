#include  "game.h"
#ifndef LINUX
#include <windows.h>
#endif

/*
==================
Main
==================
*/

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    // —– Vars —–

    // Class for drawing staff, it uses SDL for the rendering. Change the methods of this class
    // in order to use a different renderer
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    //Pieces
    Piece mPieces;

    //Board
    Board mBoard(&mPieces, mScreenHeight);

    //Game
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    // Get the actual clock milliseconds (SDL)
    unsigned long mTime1 = SDL_GetTicks();

    // —– Main Loop —–

    while (!mIO.IsKeyDown (SDLK_ESCAPE)){
        // —– Draw —–

        mIO.ClearScreen (); // Clear screen
        mGame.DrawScene (); // Draw staff
        mIO.UpdateScreen (); // Put the graphic context in the screen

        // —– Input —–

        int mKey = mIO.Pollkey();

        switch (mKey){
            case (SDLK_RIGHT):
            {
                if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)){
                    mGame.mPosX++;
                    break;
                }
            }
            case (SDLK_LEFT):
            {
                if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)){
                    mGame.mPosX--;
                    break;
                }
            }

            case (SDLK_DOWN):
            {
                if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)){
                    mGame.mPosY++;
                    break;
                }
            }

            case(SDLK_SPACE):
            {
                // Check collision from up to down
                while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
                    mGame.mPosY++; 
                }

                mBoard.StorePiece(mGame.mPosX, mGame.mPosY-1, mGame.mPiece, mGame.mRotation);
                mBoard.DeletePossibleLines();

                if (mBoard.IsGameOver()){
                        mIO.Getkey();
                        exit(0);
                }
            }

            case (SDLK_UP):
            {
                if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation+1)%4)){
                    mGame.mRotation = (mGame.mRotation+1)%4;
                    break;
                }
            }
        }

        // —– Vertical movement —–
        unsigned long mTime2 = SDL_GetTicks();

        if ((mTime2 - mTime1) > WAIT_TIME){
            if (mBoard.IsPossibleMovement (mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)){
                mGame.mPosY++;
            }
            else{
                mBoard.StorePiece (mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
                mBoard.DeletePossibleLines ();
                if (mBoard.IsGameOver()){
                    mIO.Getkey();
                    exit(0);
                }
                mGame.createNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }
    }
    return 0;
}