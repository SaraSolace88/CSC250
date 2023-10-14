#include "queue2.h"

void enqueue(struct queue *q, int data){
    if(q->max_len -1 == q->queue_len){
        q->max_len = q->max_len * 2;
        q->queue = realloc(q->queue, sizeof(int)* q->max_len);
    }

    q->queue_len++;
    q->queue[q->queue_len] = data;
};

void dequeue(struct queue *q){
    if(q->queue_len != -1){
        int counter = 0;
        while(q->queue_len != counter){
            q->queue[counter] = q->queue[counter + 1];
            counter++;
        }
        q->queue_len--;
    }
};

int front(struct queue *q){
    if(q->queue_len == -1){
        return INT_MIN;
    }
    return q->queue[0];
};