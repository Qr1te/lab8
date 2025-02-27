
#include "funcs.h"
#include "tasks.h"

int main(int n_arg, char *arg[]) {

    char *filename = "file", *filename1 = "file1";
    nameFile( &filename, &filename1, n_arg, arg);
    srand(time(0));
    int ans;
    do {
        system("cls");
        fflush(stdin);
        puts("What task you want to test?");
        setNumber(&ans);
        fflush(stdin);
        switch(ans) {
            case 1:  task1(filename); break;
            case 2:  task2(filename); break;
            case 3:task3(filename, filename1); break;
            case 4:task4(filename, filename1); break;
            default: puts("Task number must be from 1 to 4!"); break;
        }
        puts("Do you want to try again?(y/n)");
        ans = Try_answer();
    }while (ans != 'n' && ans != 'N');

    free(filename);
    remove(filename);

    return 0;
}

