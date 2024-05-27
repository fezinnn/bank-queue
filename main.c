#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(){
    t_queue generalQueue, priorityQueue;
    create_queue(&generalQueue);
    create_queue(&priorityQueue);

    char string[100];
    printf("\nescreva:\n");
    fgets(string, 100, stdin);
    in(&generalQueue, string);
    puts(string);


    return 0;
}