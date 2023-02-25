/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "util.h"


/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //WRITE CODE.
  //CANNOT DECLARE ANY GLOBAL VARIABLE
  void init();


    void init(int rows, int columns);
    void init(int rows, int columns, int val);
    void init(string str);
    intmatrix2();
    intmatrix2(int rows, int columns);
    intmatrix2(int rows, int columns, int val);
    intmatrix2(string str);
    bool isEqual(intmatrix2 obj);
    bool isEmpty();
    void print(string str);
    void fini();
    intmatrix2 add(intmatrix2 obj);
    intmatrix2 mult(intmatrix2 obj);
    friend ostream& operator<<(ostream& os, const intmatrix2& matrix);
    intmatrix2(const intmatrix2& other);
    intmatrix2& operator=(const intmatrix2& other);
    friend bool operator!(const intmatrix2& matrix)  ;
    ~intmatrix2();



    //USE this as is. I will explain when I show
  static void makeShowOn() {_show = true;}
  static void makeShowOff() {_show = false;}
  static bool show() {return _show ;}

private:
  static bool _show ; //MUST USE THIS
    int rows = 0, columns = 0;
    int **mat;

    //WRITE CODE BELOW

  //use xxx_ so that we know all variables are private
};




//EOF

