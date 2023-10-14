#include <stdio.h>

int main(){
    int arr[10]; //creates an array of size 10.
    
    //asking user for 10 #s and storing those #s in the array.
    int i = 0;
    printf("Please enter 10 numbers: ");
    while(i <= 9){
        scanf("%d",&arr[i]); //need & here, bc of scanf?
        i++;
    }

    //printing out #s in reverse order
    i = 9;
    printf("Reversed numbers: ");
    while(i >= 0){
        printf("%d ", arr[i]); // don't need & here
        i--;
    }
    printf("\n");
    return 0;
}