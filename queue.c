#include <stdio.h>
#include <string.h>
#include "queue.h"

void createQueue(t_queue *q) {
    q->max = 30;
    q->start = 0;
    q->end = 0;
    q->size = 0;
}

int isEmpty(t_queue *q) {
    return q->size == 0;
}

int isFull(t_queue *q) {
    return q->size == q->max;
}

int enterQueue(t_queue *q, t_elem x) {
    if (isFull(q)) return 0;
    strcpy(q->items[q->end], x);
    q->end = (q->end + 1) % q->max;
    q->size++;
    return 1;
}

int exitQueue(t_queue *q, t_elem *x) {
    if (isEmpty(q)) return 0;
    strcpy(*x, q->items[q->start]); 
    q->start = (q->start + 1) % q->max;
    q->size--;
    return 1;
}

void attendCustomer(t_queue *priorityQueue, t_queue *generalQueue, int *priorityCounter, char **customersAttended, int *attendedCounter) {
    t_elem customer;
    if (!isEmpty(priorityQueue) && *priorityCounter < 3) {
        exitQueue(priorityQueue, &customer);
        (*priorityCounter)++;
    } else if (!isEmpty(generalQueue)) {
        exitQueue(generalQueue, &customer);
        *priorityCounter = 0; 
    } else if (!isEmpty(priorityQueue)) {
        exitQueue(priorityQueue, &customer);
        (*priorityCounter)++;
    }
    customersAttended[*attendedCounter] = malloc(strlen(customer) + 1);
    strcpy(customersAttended[(*attendedCounter)++], customer);
}

void selectQueue(t_queue *priorityQueue, t_queue *generalQueue, char *input) {
    t_elem customer;
    char queueType = input[0];  
    char *name = input + 2;     

    strcpy(customer, name);
    if (queueType == 'p') {
        enterQueue(priorityQueue, customer);
    } else if (queueType == 'g') {
        enterQueue(generalQueue, customer);
    }
}

void freeCashier(char **customersAttended, int attendedCounter) {
    for (int i = 0; i < attendedCounter; i++) {
        printf("%s\n", customersAttended[i]);
        free(customersAttended[i]); 
    }
}