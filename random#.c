#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int x;
    x = rand() % 3;
    printf("%d\n", x);

    x = rand() % 3;
    printf("%d\n", x);

    return 0;
}