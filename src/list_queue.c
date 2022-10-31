#include "list_queue.h"

#include <stdio.h>

#include "assert.h"

void init_queue(queue *q) {
    // Add your init_queue
    // creating a queue
    q->front = NULL;
    q->back = NULL;

    // size of queue is 0
    q->size = 0;
}

int empty(queue *q) {
    // Add your empty function
    // if/ else statement to check wheter queue is empty. If size is bigger then 0, then not, otherwise yes. 
    if (q->size == 0) {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int x) {
    // Add your enqueue function
    // First we need to use mallcom to create place for new node
    qnode *backNew = (qnode *)malloc(sizeof(qnode));

    backNew->data = x;
    backNew->next = NULL;

    if (empty(q) == 1) {
        // if q is empty then backNew is the front and back
        q->front = backNew;
    } else {
        // If q is not empty it needs to point to backNew
        q->back->next = backNew;
    }
    q->back = backNew;
    q->size = q->size + 1;
}

int dequeue(queue *q) {
    // Add your dequeue function

    // assert to check q is not empty
    assert(empty(q) == 0);

    // we save the data in temp
    int temp = q->front->data;

    // before we update the front we save it in formerFront
    qnode *formerFront = q->front;

    // update front to next element in queue
    q->front = q->front->next;
    free(formerFront);

    // update size
    q->size = q->size - 1;

    // and return temp
    return temp;
}
