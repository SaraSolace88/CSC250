#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int_arr(int arr[30], int max){
    int i;
    for(i = 0; i < max; i++){
        printf("%d\n", arr[i]);
    }
}

void print_char_arr(char arr[30][15], int max){
    int i;
    for(i = 0; i < max; i++){
        printf("%s\n", arr[i]);
    }
}

void fill_int_arr(int arr[30], int max){
    int i;
    for(i = 0; i < max; i++){
        arr[i] = 0;
    }
}

void print_string_descending(char strArr[30][15], int intArr[30], int max){
    int i, a;
    for(i =15; i >= 0; i--){
        for(a = 0; a < max; a++){
            if(intArr[a] == i){
                printf("%s\n", strArr[a]);
            }
        }
    }
}

int main(int argc, char *argv[]){
    char strArr[30][15];
    int intArr[30];
    int strCount = 0;
    int arrMax = 0;
    int length = 0;

    FILE *input;
    input = fopen(argv[1], "r");

    fscanf(input, "%d", &strCount);

    arrMax = strCount;
    fill_int_arr(intArr, arrMax);

    do{
        strCount--;
        fscanf(input, "%s", strArr[strCount]);
        length = strlen(strArr[strCount]);
        intArr[strCount] = length;
    }while(strCount > 0);

    print_string_descending(strArr, intArr, arrMax);

    fclose(input);
    return 0;
}