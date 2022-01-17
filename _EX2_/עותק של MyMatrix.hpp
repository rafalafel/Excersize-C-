//
//  MyMatrix.hpp
//  Homemisiion4
//
//  Created by רפאל חציטריאן וגל יצחקי  on 26/12/2020.
//
#include <iostream>
#include <string.h>
#ifndef MyMatrix_hpp
#define MyMatrix_hpp

#include <stdio.h>
#pragma once

class MyMatrix {
    
private:
    int _n;
    int _m;
    
    double** _matrix;
public:
    //setters
    void setMatrix(int n , int m);
    
    //getters
    int getRaw() {return this->_n; }
    int getCol() {return this-> _m ;}
    double** getMatrix() {return _matrix;}
    
    //functions
    const MyMatrix operator+(const MyMatrix& other) const  throw(const char*);//decleration of the methods
    const MyMatrix operator-(const MyMatrix& other) const throw(const char*);
    const MyMatrix operator*(const MyMatrix& other) const throw(const char*);
    friend MyMatrix operator*(double num, const MyMatrix& other);
    const MyMatrix operator*(double scalar) const;
    MyMatrix& operator=(const MyMatrix& other) throw(const char*);
    bool operator==(const MyMatrix& other)const;
    friend std::ostream& operator<<(std::ostream& out, const MyMatrix& other);
    friend std::istream& operator>>(std::istream& in, MyMatrix& other);
    double* operator[](int row) const;
    operator double() const;
    
    //consrtuctors/distructors and more
    MyMatrix();
    MyMatrix(int n,int m);
    MyMatrix(const MyMatrix & other);//copyconstructor
    ~MyMatrix();//destructor
    
    
    
};
#endif /* MyMatrix_hpp */
