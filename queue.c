#include <stdio.h>
#include <string.h>
#include "queue.h"

void create_queue(t_queue *q) {
    q->max = 30;
    q->inicio = 0;
    q->fim = 0;
    q->n = 0;
}

int is_empty(t_queue *q) {
    return q->n == 0;
}

int is_full(t_queue *q) {
    return q->n == q->max;
}

int in(t_queue *q, t_elem x) {
    if (is_full(q)) return 0;
    strcpy(q->items[q->fim], x);
    q->fim = (q->fim + 1) % q->max;
    q->n++;
    return 1;
}

int out(t_queue *q, t_elem *x) {
    if (is_empty(q)) return 0;
    strcpy(*x, q->items[q->inicio]); 
    q->inicio = (q->inicio + 1) % q->max;
    q->n--;
    return 1;
}
