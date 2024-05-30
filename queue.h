#ifndef QUEUE_H
#define QUEUE_H

typedef char t_elem[70];

typedef struct{
    int max;
    int start;
    int end;
    int size;
    t_elem items[30];
} t_queue;

void createQueue(t_queue *q);
int isEmpty(t_queue *q);
int isFull(t_queue *q);
int enterQueue(t_queue *q, t_elem x);
int exitQueue(t_queue *q, t_elem *x);
void attendCustomer(t_queue *priorityQueue, t_queue *generalQueue, int *priorityCounter, char **customersAttended, int *attendedCounter);
void selectQueue(t_queue *priorityQueue, t_queue *generalQueue, char *input);
void freeCashier(char **customersAttended, int attendedCounter);

#endif