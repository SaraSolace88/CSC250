#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int string_length(char arr[100]);

int main(){ 
    printf("%d\n", string_length("string"));
    return 0;
}

int string_length(char arr[100]){
    int count = 0;
    
    while(arr[count] != 0){
        count++;
    }

    return count;
}