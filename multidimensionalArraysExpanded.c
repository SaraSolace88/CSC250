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
    printf("\n");
}

void print_product_of_col(int arr[5][5]){
    int product;
    int a,b;
    for(b = 0; b < 5; b++){
        product = 1;
        for(a = 0; a < 5; a++){
            product *= arr[a][b];
        }
        printf("Product of col: %d\n", product);
    }
}

void print_max(int arr[5][5]);

void print_min(int arr[5][5]);

void print_total_sum(int arr[5][5]);

void print_sum_of_rows(int arr[5][5]){
    int sum;
    int a, b;
    for(a = 0; a < 5; a++){
        sum = 0;
        for(b = 0; b < 5; b++){
            sum += arr[a][b];
        }
        printf("Sum of row %d\n", sum);
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

    printf("----------\n\n");

    for(a =0; a < 5; a++){
        for(b = 0; b < 5; b++){
            arr[a][b] = rand() %10 + 1;
        }

    }
     print_matrix(arr);

     print_total_sum(arr);
     printf("\n");

     print_product_of_col(arr);
     printf("\n");

     print_max(arr);
     printf("\n");

     print_min(arr);
     printf("\n");

    return 0;
}

void print_max(int arr[5][5]){
    int max = 0;
    int a,b;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            if (max < arr[a][b])
            {
                max = arr[a][b];
            }
        }
    }
    printf("Max value: %d", max);
    printf("\n");
}

void print_min(int arr[5][5]){
    int min = 10;
    int a,b;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            if (min > arr[a][b])
            {
                min = arr[a][b];
            }
        }
    }
    printf("Min value: %d", min);
    printf("\n");
}

void print_total_sum(int arr[5][5]){
    int sum = 0;
    int a,b;
    for(a = 0; a < 5; a++){
        for(b = 0; b < 5; b++){
            sum = sum + arr[a][b];
        }
    }
    printf("Sum of all elements in array: %d", sum);
    printf("\n");
}