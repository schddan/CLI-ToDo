#include "io.h"
#include <stdio.h>
#include <string.h>
#include "consts.h"

void strScan(char *msg, char *var, int tam){
    printf("%s", msg);
    fgets(var, tam, stdin);
    var[strlen(var) - 1] = '\0';
    fflush(stdin);
}

void printAlign(char *msg, int columns, char charac){
    int qnt;
    qnt = columns - strlen(msg);
    for(int i = 0; i < qnt/2; i++){ 
        printf("%c", charac);
    }
    printf("%s",msg);
    for(int i = 0; i < qnt/2; i++){
        printf("%c", charac);
    }
    printf("\n");
}

void readToFile(char *fileName){
    FILE *file = fopen(fileName, "a");
    char buffer[1024];
    fgets(buffer, 1024, stdin);
    fprintf(file, "%s", buffer);
    fclose(file); 
}

void printFile(char *fileName){
    FILE *file = fopen(fileName, "r");
    char line[1024];
    int count = 1;
    if (file != NULL){
        while (fgets(line, CHAR_LIMIT, file)){
            printf("[%i] ", count);
            printf("%s", line);
            count++;
        }
        fclose(file);
    }else{
        printf("Error reading the file\n");
    }
}

void cleanStdinBuffer(){
    int p;
    while ( (p = getchar() ) != '\n'){};
}
