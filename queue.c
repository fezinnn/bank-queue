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

void attendCustomer(t_queue *priorityQueue, t_queue *generalQueue, int *p_count, char **namesAttended, int *attended_count) {
    t_elem customer;
    if (!is_empty(priorityQueue) && *p_count < 3) {
        out(priorityQueue, &customer);
        (*p_count)++;
    } else if (!is_empty(generalQueue)) {
        out(generalQueue, &customer);
        *p_count = 0; 
    } else if (!is_empty(priorityQueue)) {
        out(priorityQueue, &customer);
        (*p_count)++;
    }
    namesAttended[*attended_count] = malloc(strlen(customer) + 1);
    strcpy(namesAttended[(*attended_count)++], customer);
}

void registerCustomer(t_queue *priorityQueue, t_queue *generalQueue, char *input) {
    t_elem customer;
    char queueType = input[0];  
    char *name = input + 2;     

    strcpy(customer, name);
    if (queueType == 'p') {
        in(priorityQueue, customer);
    } else if (queueType == 'g') {
        in(generalQueue, customer);
    }
}

void printAndFreeAttendedNames(char **namesAttended, int attended_count) {
    for (int i = 0; i < attended_count; i++) {
        printf("%s\n", namesAttended[i]);
        free(namesAttended[i]); 
    }
}