#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    t_queue generalQueue, priorityQueue;
    createQueue(&generalQueue);
    createQueue(&priorityQueue);

    char input[110]; 
    char* customersAttended[200];
    int attendedCounter = 0, priorityCounter = 0;

    while (1) {
        printf("Insira o comando (exemplo: 'p Luana' ou 's' ou 'f'): ");
        fgets(input, sizeof(input), stdin);  
        input[strcspn(input, "\n")] = 0;  

        if (strcmp(input, "f") == 0) { 
            break;
        } else if (strcmp(input, "s") == 0) { 
            attendCustomer(&priorityQueue, &generalQueue, &priorityCounter, customersAttended, &attendedCounter);
        } else { 
            selectQueue(&priorityQueue, &generalQueue, input);
        }
    }

    freeCashier(customersAttended, attendedCounter);
    return 0;
}