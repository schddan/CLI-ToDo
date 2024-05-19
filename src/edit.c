#include <stdio.h>
#include <stdlib.h>
#include "edit.h"
#include "io.h"
#include "consts.h"
#include "buffer.h"

void editTask(taskBuffer *current, taskBuffer *start, taskBuffer *currentAux){
    int taskNum, i;
    char c[CHAR_LIMIT], msgAux[CHAR_LIMIT];
    FILE * fileReadMode = fopen(STORAGE_ARCHIVE, "r");
    printf("Type the task number: ");
    scanf("%i", &taskNum);
    cleanStdinBuffer();
    i = 1;
    while((fgets(c, CHAR_LIMIT, fileReadMode)) != NULL){
        if (i == 1){
            i++;
            start = createOnHeap(c); 
            current = start; 
        }else{
            current -> nextTask = createOnHeap(c);
            current = current -> nextTask;
        }
    }
    fclose(fileReadMode);
    current = start;
    for(i = 2; i <= taskNum; i++){
        current = current -> nextTask;
    }
    printf("Edit: \n");
    fgets(msgAux, CHAR_LIMIT, stdin);
    current -> task = msgAux;
    FILE * fileWriteMode = fopen("STORAGE_ARCHIVE", "w");
    current = start;
    for(;current != NULL; current = current -> nextTask){
        fprintf(fileWriteMode, "%s", current -> task);
    }
    fclose(fileWriteMode);
}