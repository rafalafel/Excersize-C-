//
//  main.cpp
//  Homemisiion4
//
//  Created by רפאל חציטריאן וגל יצחקי on 26/12/2020.
//


#include <iostream>
#include <string>
#include "MyMatrix.hpp"

int main() {
    int choice;
    double c = 1.0;
    MyMatrix A, B, C, D, E, F, res;
    do
    {
        std::cout << std::endl << "Press 1 for setting matrix A" << std::endl << "Press 2 for setting matrix B" << std::endl
            << "Press 3 for setting matrix C" << std::endl << "Press 4 for setting matrix D" << std::endl
        << "Press 5 for changing the 'scalar' c (The defstd::endl of c is 1)  " << std::endl << "Press 6 for printing matrix A"
            << std::endl << "Press 7 for printing matrix B" << std::endl << "Press 8 for A + B" << std::endl << "press 9 for A - B"
            << std::endl << "Press 10 for A * c" << std::endl << "Press 11 for c * B" << std::endl << "Press 12 for A * B" << std::endl
            << "Press 13 for A * c + B" << std::endl << "Press 14 for A + B + C + D" << std::endl << "Press 15 for A * B * C * D"
            << std::endl << "Press 16 for get value of matrix A by index" << std::endl << "Press 17 for A = B" << std::endl
            << "Press 18 for A == B" << std::endl << "Press 19 for the sum of all A elemnts" << std::endl
            << "Press 20 for checking associativity of A & B & C" << std::endl<< "Press 21 for exit" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int aRow, aCol;
            std::cout << "Enter number of rows of matrix A" << std::endl;
            std::cin >> aRow;
            std::cout << "Enter number of columns of matrix A" << std::endl;
            std::cin >> aCol;

            if ((aRow < 1) || (aCol < 1))
            {             //if the (row,col) input of any of the matrices is 1,0\0,1\0,0 -  ileagal input!
                std::cout << "The matrix must have at lease one row and one column" << std::endl;
            }
            else
            {
                A.setMatrix(aRow, aCol);            // changing the sizes of the matrix
                std::cin >> A;
                std::cout << A << std::endl;
            }
            break;
        }
        case 2:
        {
            int bRow, bCol;
            std::cout << "Enter number of rows of matrix B" << std::endl;
            std::cin >> bRow;
            std::cout << "Enter number of columns of matrix B" << std::endl;
            std::cin >> bCol;

            if ((bRow < 1) || (bCol < 1))
                std::cout << "The matrix must have at lease one row and one columns" << std::endl;
            else
            {
                B.setMatrix(bRow, bCol);
                std::cin >> B;
                std::cout << B << std::endl;
            }
            break;
        }
        case 3:
        {
            int cRow, cCol;
            std::cout << "Enter number of rows of matrix C" << std::endl;
            std::cin >> cRow;
            std::cout << "Enter number of columns of matrix C" << std::endl;
            std::cin >> cCol;

            if ((cRow < 1) || (cCol < 1))
                std::cout << "The matrix must have at lease one row and one columns" << std::endl;
            else
            {
                C.setMatrix(cRow, cCol);
                std::cin >> C;
                std::cout << C << std::endl;
            }
            break;
        }
        case 4:
        {
            int dRow, dCol;
            std::cout << "Enter number of rows of matrix D" << std::endl;
            std::cin >> dRow;
            std::cout << "Enter number of columns of matrix D" << std::endl;
            std::cin >> dCol;

            if ((dRow < 1) || (dCol < 1))
                std::cout << "The matrix must have at lease one row and one columns" << std::endl;
            else
            {
                D.setMatrix(dRow, dCol);
                std::cin >> D;
                std::cout << D << std::endl;
            }
            break;
        }
        case 5:
        {
            std::cout << "Enter Number : " << std::endl;
            std::cin >> c;
            break;
        }
        case 6:
        {
            std::cout << A << std::endl;
            break;
        }
        case 7:
        {
            std::cout << B << std::endl;
            break;
        }
        case 8:
        {
            try
            {
                res = A + B;
                std::cout << res << std::endl;
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
            break;
        }
        case 9:
        {

            try
            {
                res = A - B;
                std::cout << res << std::endl;
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
            break;
        }
        case 10:
        {
            res = A * c;
            std::cout << res << std::endl;
            break;
        }
        case 11:
        {
            res = c * B;
            std::cout << res << std::endl;
            break;
        }
        case 12:
        {
            res = A * B;
            std::cout << res << std::endl;
            break;
        }
        case 13:
        {
            try
            {
                res = A * c + B;
                std::cout << res << std::endl;
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
            break;
        }
        case 14:
        {
            try
            {
                res = A + B + C + D;
                std::cout << res << std::endl;
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
            break;
        }
        case 15:
        {
            try
            {
                res = A * B * C * D;
                std::cout << res << std::endl;
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }
            break;
        }
        case 16:
        {
            int indexRow, indexCol;
            std::cout << "Enter index row" << std::endl;
            std::cin >> indexRow;
            std::cout << "Enter index col" << std::endl;
            std::cin >> indexCol;
            if (indexRow == 0 || indexRow > A.getRaw() || indexCol == 0 || indexCol > A.getCol())
            {
                std::cout << "Error - Out of range!!" << std::endl;
                break;
            }
            std::cout << "The value of this element is : " << A[indexRow - 1][indexCol - 1] << std::endl;
        }
        case 17:
        {
            A = B;
            std::cout << "A is equal to B" << std::endl;
            break;
        }
        case 18:
        {
            if (A == B)
            {
                std::cout << "The martices are equal" << std::endl;
            }
            else
            {
                std::cout << "The martices aren't equal" << std::endl;
            }
            break;
        }
        case 19:
        {
            double sumA = (double)A;
            std::cout << "The sum of the elements of A is : " << sumA << std::endl;
            break;
        }
        case 20:
        {
            try
            {
                E = A + (B - C);
                F = (A + B) - C;
                if (E == F)
                {
                    std::cout << "The matrices are associative" << std::endl;
                }
                else
                {
                    std::cout << "The matrices aren't associative" << std::endl;
                }
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
                std::cout << "The matrices aren't associative" << std::endl;
            }
            break;

        }
        case 21:
        {
            break;
        }
        default:
                std::cout << "There is no option " << choice << "." << std::endl;
        }
    } while (choice != 21);

    return 0;
}
