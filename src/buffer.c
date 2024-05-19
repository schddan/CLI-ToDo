#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

taskBuffer* createOnHeap(char *task){
    struct taskBuffer *buffer = malloc(sizeof(taskBuffer));
    buffer -> task = strdup(task);
    buffer -> nextTask = NULL;
    return buffer;
}

void cleanHeap(taskBuffer *start){
    if (start -> task){
        free(start -> task);
    }
    if (start -> nextTask){
        cleanHeap(start -> nextTask);
    }
    free(start);
}
