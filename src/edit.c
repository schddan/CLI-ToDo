#include <stdio.h>
#include <stdlib.h>
#include "edit.h"
#include "io.h"
#include "consts.h"
#include "buffer.h"

void editTask(taskBuffer *current, taskBuffer *start, taskBuffer *currentAux){
    int taskNum, i;
    char line[CHAR_LIMIT], msgAux[CHAR_LIMIT];
    FILE * fileReadMode = fopen(STORAGE_ARCHIVE, "r");
    printf("Type the task number: ");
    scanf("%i", &taskNum);
    cleanStdinBuffer();
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

    fclose(fileReadMode);
    
    current = start;
    for(i = 2; i <= taskNum; i++){
        current = current -> nextTask;
    }
    printf("Edit: \n");
    fgets(msgAux, CHAR_LIMIT, stdin);
    current -> task = msgAux;
    FILE * fileWriteMode = fopen(STORAGE_ARCHIVE, "w");
    current = start;
    for(;current != NULL; current = current -> nextTask){
        fprintf(fileWriteMode, "%s", current -> task);
    }
    fclose(fileWriteMode);
}