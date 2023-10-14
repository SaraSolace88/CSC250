#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(){
    char str1[10];
    char str2[10];
    char str3[20];

    scanf("%s\n", str1);
    scanf("%s", str2);

    int str1len = strlen(str1);
    int str2len = strlen(str2);

    printf("First string length: %d\n", str1len);
    printf("Second string length: %d\n", str2len);

    strcat(str3, str1);
    strcat(str3, str2);

    printf("%s\n", str3);
    printf("%s\n", str1);
    printf("%s\n", str2);
}
