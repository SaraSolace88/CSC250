#include <stdio.h>
#include <stdlib>

struct Foo {
    int age;
    char name[50];
};

int main(int argc, char *argv[]) {

    //on the stack struct Foo foo

    //int on the heap
    //int *x = malloc(sizeof(int));
    //assigning value to variable on the heap.
    //*x = 123;

    struct Foo *foo = malloc(sizeof(struct Foo));

    //set foo's age to 42

    foo->age = 42;
    printf("Age: %d\n", foo->age);

    //array of 64 ints on the heap

    int *x = malloc(sizeof(int) * 64);

    //set all the ints to 123;

    for(int i = 0; i <64 ; i++){
        x[i] = 123;
    }

    //foos be an array of 8 foos on the heap
    struct Foo *foos = malloc(sizeof(struct Foo)* 8);
    //set 3rd foos age to 42
    foos[2].age = 42; //using x[i] syntax includes * so no need to use -> instead of .


    free(foo);
    return 0;
}