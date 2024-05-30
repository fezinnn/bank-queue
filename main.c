#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

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