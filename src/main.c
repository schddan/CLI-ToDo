#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"
#include "io.h"
#include "consts.h"
#include "edit.h"
#include "finish.h"
#include "add.h"
#include "list.h"

int main(int argc, char * argv[]){
    char c[CHAR_LIMIT];
    int taskNum, i, p;
    taskBuffer *start, *current, *currentAux;
    if(argc == 1){
        printf(
            "toDo <command>\n\tadd -> adds a new task\n\tlist -> lists the current tasks\n\tfinish -> finishes a task\n\tedit -> edits a task\n"
        );
        return 0;
    }
    if(!strcmp(argv[1], "list")){
        printAlign("My To dos", 50, '-');
        printFile(STORAGE_ARCHIVE);
        return 0;
    }

    if(!strcmp(argv[1], "add")){
        printf("Type the new task:\n");
        readToFile(STORAGE_ARCHIVE);
        printf("Now these are your tasks:\n");
        printFile(STORAGE_ARCHIVE);
        return 0;
    }

    if(!strcmp(argv[1], "edit")){
        editTask(current, start, currentAux);
        return 0;
    }

    if(!strcmp(argv[1], "finish")){
        finishTask(current, start, currentAux);
        return 0;
    }
    
}
