#include <stdio.h>
#include <stdlib.h>

void test_func(char *str, int len){
    str[2] = 'a';
}

void foo(int *double_you){
    *double_you = 10;
}


int main(int argc, char **argv){
    char str[20];
    char arr[10][10];
    char **arr2; //don't have to give arr2 a size, arr does need a size.
    printf("%p\n", str);
    printf("%p\n", str + 1);
    return 0;

    foo(&y);

    printf("%d\n", y);

    //make a function that changes a variable in main to the value 10
}
//& gives variable memory address//
//*x = can change pointers value.


/*
int arr[3]      //visulaization of how arrays store in memory
[      [32][5][21]                          ]
*/