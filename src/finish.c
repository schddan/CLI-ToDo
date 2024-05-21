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
    i = 1;
    if(fgetc(fileReadMode) == -1){
        printf("Task doesn't exist\n");
        return;
    }
    while((fgets(line, CHAR_LIMIT, fileReadMode)) != NULL){
        if (i == 1){
            i++;
            start = createOnHeap(line);
            current = start; 
        }else{
            i++;
            printf("%i", i); //Arrumar
            if(taskNum > i + 1|| taskNum < 1){
                printf("This task doesn't exist\n");
                return;
            }
            current -> nextTask = createOnHeap(line); 
            current = current -> nextTask;
        }
    }


    if (taskNum == 1){
        current = start -> nextTask;
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