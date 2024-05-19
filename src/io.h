#ifndef IO_H
#define IO_H

void strScan(char *msg, char *var, int tam);
void printAlign(char *msg, int columns, char charac);
void readToFile(char *fileName);
void printFile(char *fileName);
void cleanStdinBuffer();

#endif