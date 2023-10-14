#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encrypt(char* str){
    int len = strlen(str);
    for(int a = 0; a < len; a++){
        str[a] = str[a] - 'a';
        str[a] = str[a] + 21;
        str[a] = str[a] % 26;
        str[a] = str[a] + 'a';
    }
    printf("%s\n", str);
}

int main(int argc, char* argv[]){
    for(int a = 1; a < argc; a++){
        printf("%s\n", argv[a]);
        encrypt(argv[a]);
    }
    return 0;
}