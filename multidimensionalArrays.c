#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int arr[5][5]){
    int a, b;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
}

int main(){

    srand(time(NULL));

    int arr[5][5];
    int a, b;

    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            arr[a][b] = 0;
        }
    }

    print_matrix(arr);

    printf("\n----------\n");

    for(a =0; a < 5; a++){
        for(b = 0; b < 5; b++){
            arr[a][b] = rand() %10 + 1;
        }

    }
     print_matrix(arr);

    return 0;
}