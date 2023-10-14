#include "queue2.h"

int main(){
    struct queue *q = malloc(sizeof(struct queue));
    q->queue = malloc(sizeof(int));
    q->max_len = 1;
    q->queue_len = -1;

    dequeue(q);

    printf("Front: %d\n", front(q));
    enqueue(q, 1);
    printf("Front: %d\n", front(q));
    enqueue(q, 2);
    printf("Front: %d\n", front(q));
    enqueue(q, 3);
    printf("Front: %d\n", front(q));
    enqueue(q, 4);
    printf("Front: %d\n", front(q));

    dequeue(q);
    printf("aFront: %d\n", front(q));
    dequeue(q);
    printf("Front: %d\n", front(q));
    dequeue(q);
    printf("Front: %d\n", front(q));
    dequeue(q);
    printf("Front: %d\n", front(q));
    dequeue(q);
    printf("Front: %d\n", front(q));
}