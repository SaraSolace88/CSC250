#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[400];
    int totchar;
    scanf("%399s", str); //throwing in 3 after % says we can only enter 3 characters.
    printf("%s\n", str);

    for(int i = 0; str[i] != 0; i++){ //declare i inside of for loop to only have variable inside for loop.
        totchar++;
    }

    printf("The string length is: %d", totchar);
    printf("\n");

    return 0;
}