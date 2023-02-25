/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false ;



void intmatrix2 ::fini() {
    if(show){
        if (rows != 0 && columns != 0) {
            for (int p = 0; p < rows; ++p) {
                delete[] mat[p];
            }
            delete[] mat;
        }
    }
    else{
        assert(0);
    }

}

void intmatrix2 ::print(string str) {
    if(show()) {
        cout << "--------" << str << "--------" << endl;
        if (rows == 0 || columns == 0) {
            cout << "        "
                 << "Empty Matrix"
                 << "        " << endl;
        } else {
            for (int p = 0; p < rows; p++) {
                for (int q = 0; q < columns; q++) {
                    cout << mat[p][q] << ' ';
                }
                cout << endl;
            }
        }
    }
    else{
        assert(0);
    }
}
ostream& operator<<(ostream& os, const intmatrix2& matrix) {
    if(intmatrix2::show()){
    if (matrix.rows == 0 || matrix.columns == 0) {
        os << "        " << "Empty Matrix" << "        " << endl;
    } else {
        for (int p = 0; p < matrix.rows; p++) {
            for (int q = 0; q < matrix.columns; q++) {
                os << matrix.mat[p][q] << ' ';
            }
            os << endl;
        }
    }
    return os;
}else{
        assert(0);
    }
}
bool operator!(const intmatrix2& matrix)  {
    if(intmatrix2::show()){
    return (matrix.rows == 0 || matrix.columns == 0);
}
    else{
        assert(0);
    }
}

bool intmatrix2 ::isEmpty() { if(intmatrix2::show()){return (this->rows == 0 || this->columns == 0); }else{
        assert(0);
    }}

bool intmatrix2 ::isEqual(intmatrix2& obj) {
    if(intmatrix2::show()){
    if (rows == 1) return true;
    if (obj.rows == 0 && rows == 0 || obj.columns == 0 && columns == 0) return true;
    if (obj.rows != rows || obj.columns != columns) return false;
    for (int p = 0; p < rows; p++) {
        for (int q = 0; q < columns; q++) {
            if (mat[p][q] != obj.mat[p][q]) return false;
        }
    }
    return true;
}else{
        assert(0);
    }}



intmatrix2 intmatrix2 ::add(intmatrix2& obj) {
    if(intmatrix2::show()){
    if (this->rows == obj.rows && this->columns == obj.columns) {
        intmatrix2 mat1(obj.rows, obj.columns, 0);
        for (int p = 0; p < rows; p++) {
            for (int q = 0; q < columns; q++) {
                mat1.mat[p][q] = this->mat[p][q] + obj.mat[p][q];
            }
        }
        return mat1;
    } else {
        intmatrix2 mat1(0, 0, 0);
        return mat1;
    }
}else{
        assert(0);
    }}




intmatrix2 intmatrix2 ::mult(intmatrix2& obj) {
    if(intmatrix2::show()){
    if (this->columns == 1 && this->rows == 1) {
        intmatrix2 mat1(obj.rows, obj.columns, 0);
        int mult = this->mat[0][0];
        for (int p = 0; p < obj.rows; p++) {
            for (int q = 0; q < obj.columns; q++) {
                mat1.mat[p][q] = mult * obj.mat[p][q];
            }
        }
        return mat1;
    } else if (obj.columns == 1 && obj.rows == 1) {
        intmatrix2 mat1(this->rows, this->columns, 0);
        int mult = obj.mat[0][0];
        for (int p = 0; p < this->rows; p++) {
            for (int q = 0; q < this->columns; q++) {
                mat1.mat[p][q] = mult * this->mat[p][q];
            }
        }



        return mat1;
    } else if (this->columns == obj.rows) {
        int rows = this->rows;
        int cols = obj.columns;
        intmatrix2 mat1(rows, cols, 0);
        for (int p = 0; p < rows; p++) {
            for (int q = 0; q < cols; q++) {
                for (int r = 0; r < obj.rows; r++) {
                    mat1.mat[p][q] += this->mat[p][r] * obj.mat[r][q];
                }
            }
        }
        return mat1;
    }




    intmatrix2 mat1;


    return mat1;
}else{
        assert(0);
    }}

intmatrix2::intmatrix2() {
    if(intmatrix2::show()){
        cout<<"In constructor r = 0 c = 0 v = 0"<<endl;
    //init();
    this->rows = 0;
    this->columns = 0;
    this->mat= new int*[0];
}else{
        assert(0);
    }}

intmatrix2::intmatrix2(int rows, int columns) {
    if(intmatrix2::show()){
    cout<<"In constructor r = "<<rows<<" c = "<<columns<<" v = 0"<<endl;
   // init(rows,columns);
    if (rows != 0 && columns != 0) {
        this->rows = rows;
        this->columns = columns;
        this->mat = new int*[rows];
        for (int p = 0; p < rows; p++) {
            mat[p] = new int[columns];
        }
        for (int p = 0; p < rows; p++) {
            for (int q = 0; q < columns; q++) {
                mat[p][q] = 0;
            }
        }
    }
}else{
        assert(0);
    }}

intmatrix2::intmatrix2(int rows, int columns, int val) {
    if(intmatrix2::show()){
    cout<<"In constructor r = "<<rows<<" c = "<<columns<<" v = 0"<<endl;
    //init(rows,columns,val);
    if (rows != 0 && columns != 0) {
        this->rows = rows;
        this->columns = columns;
        this->mat = new int*[rows];
        for (int p = 0; p < rows; p++) {
            mat[p] = new int[columns];
        }
        for (int p = 0; p < rows; p++) {
            for (int q = 0; q < columns; q++) {
                mat[p][q] = val;
            }
        }
    }

}else{
        assert(0);
    }}

intmatrix2::intmatrix2(string str) {
    if(intmatrix2::show()){
    cout<<"In constructor s = "<<str<<endl;
    //init(str);
    int size = str.length();
    int bar_count = 0;
    int vec_index = 0;
    int* vec = new int[size];

    for (int p = 0; p < size; p++) {
        if (str[p] == '|') {
            bar_count++;
            continue;
        }
        if (str[p] != ' ' && str[p] != '|') {
            if (str[p + 1] == ' ' || str[p + 1] == '|') {
                vec[vec_index++] = str[p] - '0';
            } else {
                int q = p;
                int temp_num = 0;
                int counter = 0;

                while ((str[q] != ' ' && str[q] != '|') && str[q] != '\0') {
                    int temp_digit = str[q] - '0';
                    temp_num = temp_num * 10 + temp_digit;
                    q++;
                    counter++;
                }
                vec[vec_index++] = temp_num;
                p += counter - 1;
            }
        }
    }

    this->columns = vec_index / (bar_count + 1);
    this->rows = bar_count + 1;
    if (vec_index % (bar_count + 1) != 0) {
        this->rows = this->columns = 0;
        this->mat = nullptr;
        delete[] vec;
        return;
    }

    this->mat = new int*[this->rows];
    for (int p = 0; p < this->rows; p++) {
        this->mat[p] = new int[this->columns];
    }

    vec_index = 0;
    for (int p = 0; p < this->rows; p++) {
        for (int q = 0; q < this->columns; q++) {
            this->mat[p][q] = vec[vec_index++];
        }
    }

    delete[] vec;
}else{
        assert(0);
    }}
intmatrix2::intmatrix2(const intmatrix2& other) {
    if(intmatrix2::show()){
    cout<<"in copy constructor"<<endl;
    cout<<other;
    // Copy other matrix's dimensions
    rows = other.rows;
    columns = other.columns;
    // Allocate memory for the new matrix
    mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[columns];
        // Copy values from other matrix to new matrix
        for (int j = 0; j < columns; j++) {
            mat[i][j] = other.mat[i][j];
        }
    }
}else{
        assert(0);
    }}

intmatrix2& intmatrix2::operator=(const intmatrix2& other) {
    if(intmatrix2::show()){
    cout<<"In equal operator rhs"<<endl;
    cout<<other;
    if (this != &other) { // Check for self-assignment
        // Free memory of current matrix
        fini();
        // Copy other matrix's dimensions
        rows = other.rows;
        columns = other.columns;
        // Allocate memory for the new matrix
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[columns];
            // Copy values from other matrix to new matrix
            for (int j = 0; j < columns; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    return *this;
}else{
        assert(0);
    }}
intmatrix2::~intmatrix2() {
    if(intmatrix2::show()){
    cout<<"In distructor";
    print("");
    // Deallocate the memory for the matrix
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    mat = nullptr; // Set the pointer to null to prevent accessing deallocated memory
}else{
        assert(0);
    }}


/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/




//EOF

