#include <stdlib.h>
#include <time.h>

//multiply 2 matrices together and print out the result.
void matrix_multiplication(int arr1[5][5], int arr2[5][5]){
    int a, b, c;
    int mul_arr[5][5];
    int total;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            total = 0;
            for(c = 0; c < 5; c++){
                total += arr1[a][c] * arr[c][b];
            }
            mul_arr[a][b]= total;
        }
    }
    print_matrix(mul_arr);
}

int main(){
    int arr1[5][5];
    int arr2[5][5];
    int a, b;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            arr1[a][b] = rand() % 3 + 1;
            arr2[a][b] = rand() % 3 + 1;
        }
    }

    print_matrix(arr1);
    print_matrix(arr2);

    matrix_multiplication
    return 0;
}