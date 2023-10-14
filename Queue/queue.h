#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue{
    struct node *front_queue;
    struct node *back_queue;
};

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct queue *enqueue(struct queue *q, int data);

struct queue *dequeue(struct queue *q);

int front(struct queue *q);

#endif