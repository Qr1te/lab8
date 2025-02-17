#include "funcs.h"


void setNumber(int* number)
{
    int i = 0;
    *number = 0;
    char digits[256];
    scanf("%s", digits);
    do {
        if (digits[i] < '0' || digits[i] > '9') {
            puts("Invalid input. Try again");
            fflush(stdin); setNumber(number);  break;
        }
        else { *number = *number * 10 + digits[i] - '0'; }
    } while(digits[++i] != 0);

}
char Try_answer() {
    char answer;
    scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin);
        puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}
void nameFile(char **filename, int n_arg, char *arg[])
{
    char bin[5] = ".bin" ; bin[4] ='\0';
    if (n_arg > 1){
       *filename = (char*)malloc(sizeof(arg[1]));
        *filename = arg[1];
    }
    else {
        *filename = (char*)malloc(sizeof(char)*24);

        printf("Enter file name: ");
        if (!fgets(*filename, 20, stdin)){
            printf("\nWrong file name");
            exit(1);
        }
        (*filename)[strlen(*filename)-1] = '\0';
    }
    *filename = strcat(*filename,bin);
}

void fillFile(char *filename){
    FILE *fp = fopen(filename, "wb");

    int n = 0;
    int *s = (int *)malloc(sizeof(int));
    if(s == NULL){printf("cannot malloc memory\n");exit(1);}
    puts("Enter file (press 0 to end input)");
    while (1) {
        setNumber(&s[n]);
        if (s[n] == 0) break;
        n++;
        s = (int *)realloc(s, (n + 1) * sizeof(int));
    }

    fwrite(s, sizeof(int),n,fp);

    free(s);
    fclose(fp);
    printf("File has been written\n");

    fopen(filename, "rb");
    int array[n];
    fread(array, sizeof(int),n,fp);
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);

    }
    printf("\n");
}
void countNumbers(const char *filename){

    FILE *fp = fopen(filename, "rb");
    int n = 1;
    int *array = (int *)malloc(n * sizeof(int));

    while(fread(array, sizeof(int), n, fp) != 0){
    fread(array, sizeof(int), n, fp);
    array = (int*) realloc(array, ++n * sizeof(int));
    }

    fclose(fp);

    int count = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
        if (array[i+1] > sum ) count++;
    }

    printf("%d \n", count);
    free(array);
}
void readNum(FILE **file, int pos, int *num)
{
    fseek(*file, pos * (int)sizeof(int) , SEEK_SET);
    fread(num, sizeof(int), 1, *file);
}
void writeNum(FILE **file, int pos, int *num)
{
    fseek(*file, pos * (int)sizeof(int) , SEEK_SET);
    fwrite(num, sizeof(int), 1, *file);
}
void swapInFile(FILE *file, int i, int j) {
    int num1, num2;

    readNum(&file, i, &num1);
    readNum(&file, j, &num2);

    writeNum(&file, i, &num2);
    writeNum(&file, j, &num1);
}

int fileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    int size = (int)ftell(file) / (int)sizeof(int);
    rewind(file);
    return size;
}

void sortBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "r+b");

    int  n = fileSize(file);
    int num1;
    int num2;
    for(int i = 0;i < n-1; ++i)
    {
        for(int j = i + 1; j<n; ++j)
        {
            readNum(&file, i, &num1);
            readNum(&file, j, &num2);
            if(num1 < num2){ swapInFile(file,i,j);}
        }
    }

    int *h = (int*) malloc(n *sizeof(int));
    rewind(file);
    fread(h, sizeof(int),n, file);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\n");
    free(h);


    fclose(file);
}

void mergeTheFile(const char *filename1, const char *filename2){
    FILE *file1 = fopen(filename1, "r+b");
    FILE *file2 = fopen(filename2, "r+b");
    FILE  *fileBoth = fopen("data2.bin", "w+b");

    int size1 = fileSize(file1), size2 = fileSize(file2), size = size1 + size2;

    if (file1 != NULL && file2 != NULL && fileBoth != NULL) {
        int input1, input2;
        fread(&input1, sizeof(int), 1, file1);
        fread(&input2, sizeof(int), 1, file2);
        for(int i = 0, j = 0; i < size1 || j < size2;) {
            if (i < size && (input1 > input2 || j == size2)) {
                fwrite(&input1, sizeof(int), 1, fileBoth);
                fread(&input1, sizeof(int), 1, file1);
                i++;
            }
            else if (j != size) {
                fwrite(&input2, sizeof(int), 1, fileBoth);
                fread(&input2, sizeof(int), 1, file2);
                j++;
            }
        }

        fseek(fileBoth, 0, SEEK_SET);
        for (int i = 0; i < size; ++i) {
            int input;
            fread(&input, sizeof(int), 1, fileBoth);
            printf("%d ", input);
        }
        puts("");
    } else
        puts("Error! File wasn't open.");
}












