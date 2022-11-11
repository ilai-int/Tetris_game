#ifndef _PIECES_
#define _PIECES_

class Piece{
    public:
        int get_block_type(int piece, int rotation, int x, int y);
        int get_x_initial_position(int piece, int rotation);
        int get_y_initial_poisiton(int piece, int rotation);

};

#endif // _PIECES_