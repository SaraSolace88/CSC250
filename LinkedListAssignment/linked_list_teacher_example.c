#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    struct node *next;
};

int length_ll(struct node* ll){
    struct node* walker = ll;
    int counter = 0;
    while(walker != NULL){
        counter++;
        walker = walker->next;
    }
    return counter;
}

void print_ll(struct node* ll){
    struct node* walker = ll;
    printf("Linked List Values: ");
    while(walker != NULL){
        printf("%d ", walker->data);
        walker = walker->next;
    }
    printf("\n");
}

struct node* search_value(struct node* ll, int data){
    struct node* walker = ll;
    while(walker != NULL){
        if(walker->data == data){
            return walker;
        }
        walker = walker->next;
    }
    return walker;
}

struct node* delete_node(struct node* ll, int data){
    
}

struct node* insert_node(struct node* ll, int data){
    if(ll == NULL){
        ll = malloc(sizeof(struct node));
        ll->data = data;
        ll->next = NULL;
        return ll;
    }

    struct node* walker = ll;
    while(walker->next != NULL){
        walker = walker->next;
    }
    walker->next = malloc(sizeof(struct node));
    walker = walker->next;
    walker->data = data;
    walker->next = NULL;
    return ll;
}

struct node* cleanup_ll(struct node* ll){
    struct node* walker = ll;
    while(ll != NULL){
        ll = ll->next;
        free(walker);
        walker = ll;
    }
    return NULL;
}

int main(int argc, char **argv){
    struct node *main_ll_pointer = NULL;
    main_ll_pointer = insert_node(main_ll_pointer, 8);
    main_ll_pointer = insert_node(main_ll_pointer, 10);
    main_ll_pointer = insert_node(main_ll_pointer, 5);
    main_ll_pointer = insert_node(main_ll_pointer, 2);

    print_ll(main_ll_pointer);
    printf("Length of the list: %d\n", length_ll(main_ll_pointer));

    struct node* n = search_value(main_ll_pointer, 2);
    if(n != NULL){
        printf("The value was found! (%d)\n", n->data);
    }
    else{
        printf("The value was not found!\n");
    }



    main_ll_pointer = cleanup_ll(main_ll_pointer);
    printf("linked list is cleaned up\n");

    return 0;
}