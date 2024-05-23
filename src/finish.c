#include <stdio.h>
#include <stdlib.h>
#include "edit.h"
#include "io.h"
#include "consts.h"
#include "buffer.h"


void finishTask(taskBuffer *current, taskBuffer *start, taskBuffer *currentAux){
    int taskNum, i;
    char line[CHAR_LIMIT];
    printFile(STORAGE_ARCHIVE);
    printf("Type the task number: ");
    scanf("%i", &taskNum);
    cleanStdinBuffer();
    FILE *fileReadMode = fopen(STORAGE_ARCHIVE, "r");
    i = 0;
    if(taskNum < 1){
        printf("Task doesn't exist\n");
        return;
    }
    while((fgets(line, CHAR_LIMIT, fileReadMode)) != NULL){
        i++;
        if (i == 1){
            start = createOnHeap(line);
            current = start; 
            continue;
        }
        current -> nextTask = createOnHeap(line); 
        current = current -> nextTask;
    }
    if(taskNum > i || i==0){
        printf("Task doesn't exist\n");
        return;
    }

    if (taskNum == 1){
        current = start -> nextTask;
        printf("Finished task: %s", start -> task);
        if(start->nextTask != NULL){
            free(start -> task); 
        }
        free(start); 
        start = current;
    } else {
        current = start;
        for (int i = 2; i <= taskNum - 1; i++){
            current = current -> nextTask;
            
        }
        currentAux = current -> nextTask;
        printf("Finished task: %s", current -> nextTask -> task);
        free(current -> nextTask -> task);
        currentAux = currentAux -> nextTask;
        free(current -> nextTask);
        current -> nextTask = currentAux;
        
        fclose(fileReadMode);
    }

    FILE *fileWriteMode = fopen(STORAGE_ARCHIVE, "w");
    current = start;
    for(;current != NULL; current = current -> nextTask){
        fprintf(fileWriteMode, "%s", current -> task);
    }
    fclose(fileWriteMode);
    cleanHeap(start);
}