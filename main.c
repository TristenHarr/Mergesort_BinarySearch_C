#include "Header.h"

int main(void){

    int size, index;
    FILE *fp = fopen("employee.csv", "r"); // open file
    if (fp){
        fscanf(fp,"%d\n", &size);
    }
    else {
        printf("Cannot find the file\n"); // error checking
        return -1;
    }

    Employee** array = (Employee**)malloc(sizeof(Employee*)*size);
    if (array == NULL){ // error check for malloc
        printf("Allocating memory failed\n");
        return -1;
    }

    // read data into array
    for (int i = 0; i < size; i++){
        array[i] = readRecord(fp);
    }
    fclose(fp);

    // sort array based on employee's ages in descending order
    mergesort((void**)array,0,size-1);

    Employee query;
    // search for employee with age 20
    query.age = 20;
    index = binarySearch((void**)array, 0, size-1, &query);
    printResult(array,index,&query);

    // search for employee with age 35
    query.age = 35;
    index = binarySearch((void**)array, 0, size-1, &query);
    printResult(array,index,&query);

    // search for employee with age 5
    query.age = 5;
    index = binarySearch((void**)array, 0, size-1, &query);
    printResult(array,index,&query);

    // free all memories
    for (int i = 0; i < size; i++){
        free(array[i]);
    }
    free(array);

    return 0;
}
