#include <cstdio>

class Piece{
    public:
        int get_type();

};

char all_pieces[7][4][5][5] = {
    //square
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,0,2,1,0},
         {0,0,1,1,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,0,0},
         {0,1,1,0,0},
         {0,0,0,0,0}},
        
        //rot 3
        {{0,0,0,0,0},
         {0,1,1,0,0},
         {0,1,2,0,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,0,1,1,0},
         {0,0,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}}
    },
    //I-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,1,1},
         {0,0,0,0,0},
         {0,0,0,0,0}},
        
        //rot 2
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,2,0,0},
         {0,0,1,0,0},
         {0,0,1,0,0}},

        //rot 3
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {1,1,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,1,0,0},
         {0,0,1,0,0},
         {0,0,2,0,0},
         {0,0,1,0,0},
         {0,0,0,0,0}}
    },
    //L-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,2,0,0},
         {0,0,1,1,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,1,0},
         {0,1,0,0,0},
         {0,0,0,0,0}},

        //rot 3
        {{0,0,0,0,0},
         {0,1,1,0,0},
         {0,0,2,0,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,0,0,1,0},
         {0,1,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}}
    },

    //J-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,2,0,0},
         {0,1,1,0,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,1,0,0,0},
         {0,1,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        //rot 3
        {{0,0,0,0,0},
         {0,0,1,1,0},
         {0,0,2,0,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,1,0},
         {0,0,0,1,0},
         {0,0,0,0,0}}
    },
    
    //N-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,0,1,0},
         {0,0,2,1,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,0,0},
         {0,0,1,1,0},
         {0,0,0,0,0}},
        
        //rot 3
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,1,2,0,0},
         {0,1,0,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,1,1,0,0},
         {0,0,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}}
    },

    //Z-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,1,0,0,0},
         {0,1,2,0,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,0,1,1,0},
         {0,1,2,0,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},
        
        //rot 3
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,2,1,0},
         {0,0,0,1,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,0,2,1,0},
         {0,1,1,0,0},
         {0,0,0,0,0}}
    },

    //T-piece
    {
        //rot 1
        {{0,0,0,0,0},
         {0,0,0,0,0},
         {0,1,2,1,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 2
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,1,2,0,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        //rot 3
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,1,2,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        //rot 4
        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,2,1,0},
         {0,0,1,0,0},
         {0,0,0,0,0}}
    }
};

int starting_posistion[7][4][2]= {
    //square
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -3},
        //rot 3
        {-2, -3},
        //rot 4
        {-3, -3}
    },

    //I-piece
    {
        //rot 1
        {-2, -2},
        //rot 2
        {-2, -3},
        //rot 3
        {-2, -2},
        //rot 4
        {-2, -3}
    },

    //L-piece
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -3},
        //rot 3
        {-2, -3},
        //rot 4
        {-2, -2}
    },

    //J-piece
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -2},
        //rot 3
        {-2, -3},
        //rot 4
        {-2, -3}
    },

    //N-piece
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -3},
        //rot 3
        {-2, -3},
        //rot 4
        {-2, -2}
    },

    //Z-piece
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -2},
        //rot 3
        {-2, -3},
        //rot 4
        {-2, -3}
    },
    //T-piece
    {
        //rot 1
        {-2, -3},
        //rot 2
        {-2, -3},
        //rot 3
        {-2, -2},
        //rot 4
        {-2, -3}
    }
};