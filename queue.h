#ifndef QUEUE_H
#define QUEUE_H

typedef char t_elem[70];

typedef struct{
    int max;
    int inicio;
    int fim;
    int n;
    t_elem items[30];
} t_queue;

void create_queue(t_queue *q);
int is_empty(t_queue *q);
int is_full(t_queue *q);
int in(t_queue *q, t_elem x);
int out(t_queue *q, t_elem x);

#endif
