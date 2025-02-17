
#include "funcs.h"
#include "tasks.h"
void task1(char *filename){
    fillFile(filename);
}
void task2(char *filename){
    fillFile(filename);
    countNumbers(filename);
}
void task3(char *filename1, char *filename2){

    fillFile(filename1);
    fillFile(filename2);
    sortBinaryFile(filename1);
    sortBinaryFile(filename2);

}
void task4(char *filename1, char *filename2){
    fillFile(filename1);
    fillFile(filename2);
    sortBinaryFile(filename1);
    sortBinaryFile(filename2);
    mergeTheFile(filename1, filename2);

}