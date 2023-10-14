#include "queue.h"



struct queue *enqueue(struct queue *q, int data){
    
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;

    if(q->front_queue == NULL){
        q->front_queue = tmp;
        q->front_queue->prev = NULL;
        q->back_queue = tmp;
        q->back_queue->next = NULL;
    }else if(q->front_queue->prev == NULL){
        q->back_queue = tmp;
        q->front_queue->prev = q->back_queue;
        q->back_queue->next = q->front_queue;
    }else{
        struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
        tmp2 = q->back_queue;
        q->back_queue = tmp;
        q->back_queue->next = tmp2;
    }
    return q;
}



struct queue *dequeue(struct queue *q){
    if(q->front_queue == NULL){
        q->back_queue = NULL;
    }else if(q->front_queue->prev == NULL){
        free(q->front_queue);
        q->back_queue = NULL;
        q->front_queue = NULL;
    }else{
        struct node *tmp = (struct node*)malloc(sizeof(struct node));
        tmp = q->front_queue;
        q->front_queue = q->front_queue->prev;
        free(tmp);
    }
    return q;
}



int front(struct queue *q){
    if(q->back_queue == NULL){
        return INT_MIN;
    }else{
        return q->front_queue->data;
    }
}


