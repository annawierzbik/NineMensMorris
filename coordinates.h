#ifndef COORDINATES_H
#define COORDINATES_H

class coordinates {
    private:
        int row;
        int col;
    public:
        coordinates(int r, int c);
        //constructor, throws an exception for invalid values
        const int get_row();
        //accessor
        const int get_col();
        //accessor
        void set_row(int n);
        //changes value of row
        void set_col(int n);
        //changes value of col
        bool is_coordinate_valid(int r);
        //checks if this part of coordinate is in the bonds
};

#endif // COORDINATES_H
