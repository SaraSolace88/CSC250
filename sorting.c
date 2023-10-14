#include <stdio.h>

void bubble_sort(int *list, int len){
    int outer_it, inner_it, num_swaps = 0, tmp, counter = 0;

    for(outer_it = 0; outer_it < len - 1 - outer_it; outer_it++){
        for(inner_it = 0; inner_it < len; inner_it++){
            counter++;
            if(list[inner_it] > list[inner_it + 1]){
                num_swaps++;
                tmp = list[inner_it + 1];
                list[inner_it + 1] = list[inner_it];
                list[inner_it] = tmp;
            }
        }
        if(num_swaps == 0){
            break;
        }
    }
    printf("number of comparisons: %d", counter);
}

void print_list(int *list, int len){
    printf("List: ");
    for(int i = 0; i < len; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(int argc, char **argv){
    int arr[10] = {3, 5, 1, -8, 4, 9, 0, 7, -6, 4};
    print_list(arr, 10);

    bubble_sort(arr, 10);

    print_list(arr, 10);
    return 0;
}