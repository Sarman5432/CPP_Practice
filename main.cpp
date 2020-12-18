#include <iostream>     // std::cout
#include <cmath>


const int MATRIX_WIDTH = 3;

double vector_modulus(double arr[], int size);
bool exclusive_or(bool a, bool b);
bool implies(bool a, bool b);
void print_square(int size, char character);
void print_right_triangle(int size, char character);
void print_pyramid(int size, char character);
void print_diamond(int size, char character);
void print_diamond_left(int size, char character);
void print_diamond_right(int size, char character);
void print_matrix(double matrix[MATRIX_WIDTH][MATRIX_WIDTH]);
void swap_rows(double rowA[], double rowB[]);
double* matrix_reduced_row_echelon_form(double arr[MATRIX_WIDTH][MATRIX_WIDTH]);

int main() {
    std::cout << "**** LOGICAL EXPRESSIONS ****" << std::endl;
    std::cout << exclusive_or(true, true) << std::endl;
    std::cout << implies(false, true) << std::endl;
    
    std::cout << "**** Calculus/Vectors ****" << std::endl;
    double arr[] = {2,4,5.5};
    std::cout << vector_modulus(arr, 3) << std::endl << std::endl;  //arays are always "pass by reference"
    
    //double matrix[MATRIX_WIDTH][MATRIX_WIDTH] = {{4, -2, -5}, {1, 1, 1}, {-2, 3, -2}};
    //std::cout << "Original Matrix: " << std::endl;
    //print_matrix(matrix);
    //matrix_reduced_row_echelon_form(matrix);
    
    std::cout << "**** Drawing Shapes Via Loops *****" << std::endl;
    print_square(5, '*');
    print_right_triangle(5, '*');
    print_pyramid(10, '*');
    print_diamond(10, '*');
    print_diamond_left(10, '*');
    print_diamond_right(10, '*');
    
    
    return 0;
}

/**** Calculus/Vectors ****/
double vector_modulus(double arr[], int size) {
    double result;
    std::cout << "Modulus of vector [";
    
    for(int i=0; i<size; i++){
        if(i != size-1) 
            std::cout << arr[i] << ", ";
        result = result + (arr[i] * arr[i]);
    }
    
    std::cout << "] is equal to: ";
    return sqrt(result);
}

//TODO - Build a matrix class where you set MATRIX_WIDTH in constructor
void print_matrix(double matrix[MATRIX_WIDTH][MATRIX_WIDTH]){
    for(int i=0; i<MATRIX_WIDTH; i++){
        for(int j=0; j<MATRIX_WIDTH; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

//TODO - build row addition, scaling, and general algorithm to solve
double* matrix_reduced_row_echelon_form(double arr[MATRIX_WIDTH][MATRIX_WIDTH]){
    std::swap(arr[0], arr[1]);  //swap only works if arr row size is the same
    std::cout << "Swapped Row Matrix: " << std::endl;
    print_matrix(arr);
}

/**** LOGICAL EXPRESSIONS ****/
//XOR
bool exclusive_or(bool a, bool b){
    if((a && !b) || (!a && b))
        return true;
    else
        return false;
}

//Implies  a => b
bool implies(bool a, bool b){
    if(a && !b)
        return false;
    else
        return true;
}

/**** Drawing Shapes Via Loops *****/
void print_square(int size, char character){
    std::cout << "<< SQUARE >>" << std::endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            std::cout << character << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_right_triangle(int size, char character){
    std::cout << "<< RIGHT TRIANGLE >>" << std::endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            std::cout << character << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_pyramid(int size, char character){
    std::cout << "<< PYRAMID >>" << std::endl;
    for(int i=0; i<size; i++){
        //print the spaces
        for(int j=0; j<=size-i; j++){
            std::cout << " ";
        }
        //print the character
        for(int j=0; j<=i; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_diamond(int size, char character){
    std::cout << "<< DIAMOND >>" << std::endl;
    //print top half
    for(int i=0; i<size; i++){
        //print the spaces
        for(int j=0; j<=size-i; j++){
            std::cout << " ";
        }
        //print the character
        for(int j=0; j<=i; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    
    //print bottom half
    for(int i=0; i<=size; i++){
        //print the spaces
        for(int j=0; j<=i; j++){
            std::cout << " ";
        }
        //print the characters
        for(int j=0; j<=size-i; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_diamond_left(int size, char character){
    std::cout << "<< LEFT OF DIAMOND >>" << std::endl;
    //print the top half
    for(int i=0; i<size; i++){
        //print the spaces
        for(int j=0; j<=size-i; j++){
            std::cout << " ";
        }
        //print the character
        for(int j=0; j<=i/2; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    //print bottom half
    for(int i=0; i<=size; i++){
        //print the spaces
        for(int j=0; j<=i; j++){
            std::cout << " ";
        }
        //print the characters
        for(int j=0; j<=(size-i)/2; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_diamond_right(int size, char character){
    std::cout << "<< RIGHT OF DIAMOND >>" << std::endl;
    //print the top half
    for(int i=0; i<size; i++){
        //print the character
        for(int j=0; j<=i; j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    //print bottom half
    for(int i=0; i<=size; i++){
        //print the characters
        for(int j=0; j<=(size-i); j++){
            std::cout << character << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
