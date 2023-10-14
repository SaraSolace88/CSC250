#include <stdio.h>

int main(int argc, char* argv[]){

    FILE* in;
    FILE* out;

    in = fopen(input,"r");
    out = fopen(output,"rw");

    char x[10];

    do{
        fscanf(in, "%s", &x);
        printf("%s", x);
        fprintf(out, "%s\n", &x);
    }while(!feof(in));

    fclose(in);
    fclose(out);

    return 0;
}
