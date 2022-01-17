//
//  MyMatrix.cpp
//  Homemisiion4
//
//  Created by רפאל חציטריאן וגל יצחקי  on 26/12/2020.
//

#include "MyMatrix.hpp"

//building constructor that first get a colomn size and give to every colomn
//a raw size of 3
MyMatrix::MyMatrix(){
    this->_n =3;
    this->_m =3;
    this-> _matrix = new double* [3];
    for (int i=0; i<3; i++) {
        this-> _matrix[i] = new double[3];
    }
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            _matrix[i][j] = 0;
        }
    }
    
}

MyMatrix::MyMatrix(int n,int m){
    this->_n =n;
    this->_m =m;
    this-> _matrix = new double* [n];
    for (int i=0; i<n; i++) {
        this-> _matrix[i] = new double[m];
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            _matrix[i][j] = 0;
        }
    }
    
}

MyMatrix::MyMatrix(const MyMatrix & other){
    //i am changing the dynamic pointer to NULL in order to avoid deleting empty cell in the operator=.
        _matrix = NULL;
        *this = other;
    
    
}

MyMatrix::~MyMatrix(){
    for (int i=0; i<_n; i++) {
        if(_matrix[i]!=NULL)
            delete [] _matrix[i];
        _matrix[i]= NULL;    }
   // delete this->_matrix;
}

//Set the size of the matrix
void MyMatrix::setMatrix(int n , int m)
{
    MyMatrix matrix(m, n);
    *this = matrix;
}

const MyMatrix MyMatrix::operator+(const MyMatrix& other) const throw(const char*){
   
    if ((_n != other._n) || (_m != other._m))
    {
        throw "The rows & the columns must be in the same size";
    }
    
        
        MyMatrix res(_n,_m);
    
     
        for (int i=0; i< _n; i++) {
            for (int j=0; j<_m; j++) {
                
                res._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
            }
        }
    
    
    return res;
}

const MyMatrix MyMatrix::operator-(const MyMatrix& other) const throw(const char*){
   
    if ((_n != other._n) || (_m != other._m))
    {
        throw "The rows & the columns must be in the same size";
    }
    
        
        MyMatrix res(_n,_m);
    
     
        for (int i=0; i< _n; i++) {
            for (int j=0; j<_m; j++) {
                
                res._matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
            }
        }
    
    
    return res;
}

const MyMatrix MyMatrix::operator*(const MyMatrix& other) const throw(const char*){
   
    if ((_n != other._n) || (_m != other._m))
    {
        throw "The rows & the columns must be in the same size";
    }
    
        
        MyMatrix res(_n,_m);//creating a matrix that takes the rows and columns data from the present matrix
    
     
        for (int i=0; i< _n; i++) {
            for (int j=0; j<_m; j++) {
                
                res._matrix[i][j] = _matrix[i][j] * other._matrix[i][j];
            }
        }
    
    
    return res;
}

//Operator for scalar * matrix. receives a scalar and matrix and calculate the result.
//returns the result matrix,the first option
MyMatrix operator*(double num, const MyMatrix& other)
{
    MyMatrix res(other._m, other._n);
    for (int i = 0; i < other._n; i++)
    {
        for (int j = 0; j < other._m; j++)
        {
            res._matrix[i][j] = other._matrix[i][j] * num;
        }
    }
    return res;
}

//Operator for scalar * matrix. receives a scalar and matrix and calculate the result.
//returns the result matrix,the second option
const MyMatrix MyMatrix::operator*(double scalar) const
{
    MyMatrix res(_m, _n);
    for (int i = 0; i < _n; i++)
    {
        for (int j = 0; j < _m; j++)
        {
            res._matrix[i][j] = _matrix[i][j] * scalar;
        }
    }
    return res;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other) throw(const char*){
   
    //if this is the same matrix (same adress not just equal)
        if (this == &other) return *this;
        //if the 2 matrices size isn't equal - delete and then define the matrix again
        if ((this->_m != other._m) || (this->_n != other._n))
        {
            for (int i = 0; i < this->_n; i++)
            {
                delete[] this->_matrix[i];
            }
            delete this->_matrix;
            this->_matrix = nullptr;
            this->_matrix = new double* [other._n];//columns
            for (int i = 0; i < other._n; i++)
            {
                this->_matrix[i] = new double[other._m];//rows
            }
            this->_m = other._m;
            this->_n = other._n;
        }
        if (this->_matrix == nullptr)//if the arr is NULL
        {
            this->_matrix = new double* [other._n];//columns
            for (int i = 0; i < other._n; i++)
            {
                this->_matrix[i] = new double[other._m];//rows
            }
            this->_m = other._m;
            this->_n = other._n;
        }
        for (int i = 0; i < _n; i++)
        {
            for (int j = 0; j < _m; j++)
            {
                this->_matrix[i][j] = other._matrix[i][j];
            }
        }
        return *this;
}

bool MyMatrix::operator==(const MyMatrix& other)const{
    
    if ((this->_m != other._m) || (this->_n != other._n))
    {
        return false;
    }
        for (int i=0; i< _n; i++) {
            for (int j=0; j<_m; j++) {
                
               if( _matrix[i][j] != other._matrix[i][j])
               {
                   return false;
               }
            }
        }
    
    return true;
}

//Matrix printing operator that receives a matrix from an ostream object, and prints the matrix.
//The function return - ostream out
std::ostream& operator<<(std::ostream& out, const MyMatrix& other)
{
    for (int i = 0; i < other._n; i++)
    {
        for (int j = 0; j < other._m; j++)
        {
            //std::cout << other._matrix[i][j] << "\t";
            out << other._matrix[i][j]<<"\t";
        }
        out << std::endl;
    }
    out << "******************************************";
    return out;
}

//An operator that receives two objects: istream and MyMatrix by reference
//store the data members in the matrix and return the object in
std::istream& operator>>(std::istream& in, MyMatrix& other)
{
    for (int i = 0; i < other.getRaw(); i++)
        for (int j = 0; j < other.getCol(); j++)
        {
            std::cout << "Enter the value of " << i + 1 << "," << j + 1 << " : ";
            in >> other.getMatrix()[i][j];
        }
    return in;
}

double* MyMatrix::operator[](int row) const{
    
    return _matrix[row];
}

//A casting operator that receives nothing but returns the sum of the matrix members
MyMatrix::operator double() const
{
    int s=0;
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
    {
        {
            s += (*this)[i][j];
        }
    }
        
    return s;
}

