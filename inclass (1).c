#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Your computer's memory is divided into individual pieces
// called "bytes", each of which has a unique address. On a
// 32-bit computer, the address is between 0 and 2^32 - 1 = 4GB
// On a 64-bit computer, the address is between 0 and 2^64 - 1 =18ExB
//


//
// Every variable in your program lives at some memory address.
// In C, to get the address where a variable is stored, use the
// '&' operator.
//
void simple_pointer() {
    // Here, x is an integer variable on the stack.
    // If that means nothing to you, we'll see what that means soon.
    int x = 123;

    // We can print the address of x (where x is stored) using the
    // '&' operator and the '%p' format specifier.
    printf("&x is %p.\n", &x);


    // We can store the address of x as another variable.
    // When you take the address of a variable of type T, the
    // resulting value is of type T * (read pointer to T).

    // Here, we take the address of x and store it into a pointer
    // variable called px.
    int *px = &x;

    // We can print the value using the '%p' specify like before.
    printf("px is %p.\n", px);

    // Why not put the '*' next to int, instead of px?
    // Well, C is confusing, and they decided that type modifiers
    // like '*' and '[10]' need to be specified per variable, not
    // as a group. Take this example.
    //
    // int* p1, p2;
    //
    // It looks like p1 and p2 are both pointers. But actually,
    // p1 is a pointer, and p2 an int. That's why its a better to
    // write it like so:
    //
    // int *p1, p2;
}

//
// Dummy function to demonstrate changing through a pointer.
void change_the_pointer(int *px) {
    *px = 789;
}

//
// If all we could do was ask for the address of a variable,
// that would not be very useful. So, let's look at how to 
// change a variable through a pointer.
void modifying_through_pointer() {
    int x = 123;

    int *px = &x;

    //
    // We can access the data stored where the pointer is pointing
    // by using the '*' (dereference) operator.
    printf("Before modification: %d\n", *px);

    //
    // By combining the deference operator (*) and the assignment
    // operator (=) we can modify the memory at the address in the
    // pointer. This effectively changes the value of 'x' to be 456.
    *px = 456;

    printf("After modification: %d\n", x);

    //
    // Why is this useful? For one, we can pass the pointer to a
    // function, and that function can modify the variable. This
    // is called "pass by pointer". Where normally, values are
    // "pass by value".

    change_the_pointer(&x);

    printf("After change_the_pointer: %d\n", x);

    //
    // This is exactly what scanf does. We ask it to parse a value
    // and then write the result into the memory at the location
    // we provide it.
}


//
// Arrays in C are a little different from normal variables.
// Let's see how they behave.
void arrays_are_weird() {

    int arr[10];

    //
    // Look at what this prints.
    printf("arr     is %p.\n", arr);
    printf("&arr    is %p.\n", &arr);

    // What this shows us, is that when we write 'arr', it is actually
    // just a pointer. It technically is a pointer to the first element
    // of the array. To prove this, we could also write:
    
    printf("&arr[0] is %p.\n", &arr[0]);

    //
    // This might seem weird, but it is rather useful. It does mean
    // that arrays are *always* passed by pointer. This is why in scanf
    // you do not need to put a '&' in front of a char array.
}


//
void pointer_arithmetic() {

    int arr[10] = {0};

    //
    // We know arr is a pointer to the first element of the array.
    // We know we can get a pointer to other elements of the array
    // using &arr[i].
    int *px = &arr[2];

    //
    // Alternatively, we can use "pointer addition".
    // When we say "pointer + integer", the compiler actually converts
    // it to "pointer + sizeof(thing pointed at) * integer".
    //
    // So, if we have the following:

    px = arr + 2;

    // 'arr' is a pointer to ints. ints are 4-bytes in size.
    // Therefore, "arr + 2" is converted to "arr + 4 * 2".
    // Therefore, px will be 8 bytes greater than arr.
    
    printf("arr is %p\n", arr);
    printf("px  is %p\n", px);

    //
    // To take this one step further (if you're curious), arr[i]
    // actually means *(arr + i). So, it first usings pointer addition
    // to add the integer, then it deferences the result to fetch the
    // value. It's okay if that doesn't make any sense. It's just a
    // technicallity.
}


//
// You have used pointers before this class when using strings.
// Lets look at how those work.
void c_strings() {
    //
    // You've used strings before. You declare a string as an array of char.
    char name[128] = {0};
    strncpy(name, "Brendan", 128);

    //
    // You probably already know that a string in C has to end with a NUL
    // ('\0') byte. In fact, now that you know about pointers, you know
    // everything about strings in C.
    //
    // A string in C is represented as a char *. It is a pointer to the
    // first character of the string. Eventually, there should be a NUL
    // byte to signify the end of the string.
    //
    // All things that work with strings in C make this assumption.
    
    printf("%s\n", name);
}


//
// So far, every variable you have made has been on the stack.
// So what is the stack?
//
// Every time you call a function, some memory is reserved for
// the variables inside of that function. When the function returns
// all memory for those variables is released and invalidated. We
// call these blocks of memory "stack frames". Its not super important
// to understand everything right now, but conceptually, this what it
// looks like:
//
//    |     |             +-----+            |     |
//    |     |             | bar |            |     |
//    +-----+   Call bar  +-----+  Return    +-----+
//    | foo |      =>     | foo |     =>     | foo |
//    +-----+             +-----+            +-----+
//    |main |             |main |            |main |
//    +-----+             +-----+            +-----+
//
// When your program starts, it makes space for all of these stack frames.
// Generally, it is around 4-8 Megabytes. If you fill this space, you will
// get a stack-overflow error and your program will crash.
//
// The problem with the stack is that variables are "freed" automatically
// when the function returns. Let's see how to use the heap to create
// more permanent variables.
//
void heap_intro() {

    // malloc(size) is used to allocate memory from the heap.
    // It returns a pointer to "size" bytes of memory that you can use.
    // Normally, you will use sizeof() to get the size of the type you
    // want to store.

    int *heap_value = malloc(sizeof(int));

    // We can set the value using the syntax from before.
    *heap_value = 123;

    printf("heap_value is %p\n", heap_value);
    printf("*heap_value is %d\n", *heap_value);

    // When we are done using the memory, we need to free it.
    // This is done by calling free(pointer).
    free(heap_value);

    // At this point the heap_value is no longer valid and should
    // not be used anymore.
}


//
// We can use the heap to allocate large arrays that would not fit
// on the stack normally.
void arrays_in_the_heap() {
    //
    // Pretend 'n' is actually defined by user and could be any value.
    int n = 10000;

    //
    // In most compilers, this is not legal. This is a feature called
    // variable length arrays. Most compilers do not support and it
    // should not be used for security reasons.
    // int arr[n];
    
    //
    // In order create an array of variable length, we need to use the
    // heap. We simply allocate enough space for n integers.
    int *arr = malloc(sizeof(int) * n);

    //
    // We can then set these integers using a normal for-loop.
    // Notice here that we are using that fact that arr[i] simply
    // uses pointer arithmetic.
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    //
    // To make sure it worked, we can print 3 random numbers.
    printf("arr[123] is %d\n", arr[123]);
    printf("arr[9999] is %d\n", arr[9999]);
    printf("arr[1337] is %d\n", arr[1337]);

    //
    // Don't forget, when we are done with the memory, we need to
    // free it.
    free(arr);
}



int main(void) {
    simple_pointer();
    puts("\n==========================================\n");
    modifying_through_pointer();
    puts("\n==========================================\n");
    arrays_are_weird();
    puts("\n==========================================\n");
    pointer_arithmetic();
    puts("\n==========================================\n");
    c_strings();
    puts("\n==========================================\n");
    heap_intro();
    puts("\n==========================================\n");
    arrays_in_the_heap();
}






