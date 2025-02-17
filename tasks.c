//
// Created by Asus Tuf on 16.02.2025.
//
#include "funcs.h"
#include "tasks.h"
void task1(char *filename){
    fillFile(filename);
}
void task2(char *filename){

    fillFile(filename);
    countNumbers(filename);

}
void task3(){
    const char *filename1 = "data.bin";
    const char *filename2 = "data1.bin";
    fillFile(filename1);
    fillFile(filename2);
    sortBinaryFile(filename1);
    sortBinaryFile(filename2);

}
void task4(){
    const char *filename1 = "data.bin";
    const char *filename2 = "data1.bin";
    fillFile(filename1);
    fillFile(filename2);
    sortBinaryFile(filename1);
    sortBinaryFile(filename2);
    mergeTheFile(filename1, filename2);

}