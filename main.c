#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"


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
int main() {
    t_queue generalQueue, priorityQueue;
    create_queue(&generalQueue);
    create_queue(&priorityQueue);

    char input[110]; 
    char* namesAttended[200];
    int attended_count = 0, p_count = 0;

    while (1) {
        printf("Enter command (e.g., 'p Luana' or 's' or 'f'): ");
        fgets(input, sizeof(input), stdin);  
        input[strcspn(input, "\n")] = 0;  

        if (strcmp(input, "f") == 0) { 
            break;
        } else if (strcmp(input, "s") == 0) { 
            attendCustomer(&priorityQueue, &generalQueue, &p_count, namesAttended, &attended_count);
        } else { 
            registerCustomer(&priorityQueue, &generalQueue, input);
        }
    }

    printAndFreeAttendedNames(namesAttended, attended_count);
    return 0;
}

