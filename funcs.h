//
// Created by Asus Tuf on 15.02.2025.
//

#ifndef UNTITLED2_FUNCS_H
#define UNTITLED2_FUNCS_H

#endif //UNTITLED2_FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char Try_answer();
void setNumber(int *number);
void nameFile(char **filename, int n_arg, char *arg[]);
void fillFile(char *filename);
void countNumbers(const char *filename);
void readNum(FILE **file, int pos, int *num);
void writeNum(FILE **file, int pos, int *num);
void swapInFile(FILE *file, int i, int j);
int fileSize(FILE *file);
void sortBinaryFile(const char *filename);
void mergeTheFile(const char *filename1, const char *filename2);