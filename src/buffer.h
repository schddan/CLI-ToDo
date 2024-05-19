#ifndef BUFFER_H
#define BUFFER_H

typedef struct taskBuffer{
    char *task;
    struct taskBuffer *nextTask;
}taskBuffer;

taskBuffer* createOnHeap(char *task);
void cleanHeap(taskBuffer *start);

#endif