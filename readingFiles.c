#include <stdio.h>

int main(){
    FILE* f;
    f = fopen("File.Name","rw"); //add a + sign to make it update file instead of replace.
    int x;
    do{
        fscanf(f, "%d", &x); //reading from file into variable x, then printing out variable x.
        printf("%d\n", x);
    }while(!feof(f)); //checks if we're at the end of file/ if not keeps loop going

    fprintf(f, "HELLO\n"); //this command prints into file.

    fclose(f);
}