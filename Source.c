#include "Header.h"

void printResult(Employee** array,int index, Employee* query){
    if (index == -1){
        printf("Age %d doesn't exist in array\n", query->age);
    }
    else {
        printf("Age %d exists in the following record: ID: %d, Salary: %.2f, Age: %d\n", query->age,array[index]->ID,array[index]->salary,array[index]->age);
    }
}

int comparison(void *a, void *b){
    int alpha = ((Employee *) a)->age;
    int beta = ((Employee *) b)->age;
    if (alpha > beta) {
        return -1;
    } else if (alpha == beta) {
        return 0;
    } else {
        return 1;
    }
}

int binarySearch(void **arr, int first, int last, void *key){
    //Edge Case, compares last value to the key
    if (comparison(arr[last], key) == 0){
        return last;
    }
    if (last > first){
        int middle = (first + (last - 1))/2;
        if (comparison(arr[middle], key) == 0){
            return middle;
        }
        // Edge Case: If the middle gets to index zero, and the item is not at index 0 (See above comparison) return -1
        // Prevents middle value being incremented to -1
        if (middle == 0){
            return -1;
        }
        if (comparison(arr[middle], key) == 1){
            return binarySearch(arr, first, middle - 1, key);
        }
        if (comparison(arr[middle], key) == -1){
            return binarySearch(arr, middle + 1, last, key);
        }
    }
    return -1;
}

void merge(void **arr, int left, int middle, int right){
    // siz1 is the size of the "left" array (+1 because 0 indexed)
    int siz1 = middle - left + 1;
    // siz2 is the size of the "right" array
    int siz2 = right - middle;
    void **arr1 = malloc(sizeof(void *)*siz1);
    void **arr2 = malloc(sizeof(void *)*siz2);
    for (int x = 0; x < siz1; x++){
        // Fill the left array with the data
        arr1[x] = arr[left + x];
    }
    for (int y = 0; y < siz2; y++){
        // Fill the right array with the data
        arr2[y] = arr[middle+1+y];
    }
    int x = 0;
    int y = 0;
    int z = left;
    while (x < siz1 && y < siz2){
        if (comparison(arr1[x], arr2[y]) <= 0){
            arr[z] = arr1[x];
            x++;
        } else {
            arr[z] = arr2[y];
            y++;
        }
        z++;
    }

    while (x < siz1){
        arr[z] = arr1[x];
        z++;
        x++;
    }

    while (y < siz2){
        arr[z] = arr2[y];
        z++;
        y++;
    }
    free(arr1);
    free(arr2);
}

Employee *readRecord(FILE *employees){
    Employee *emps = malloc(sizeof(Employee));
    if (emps == NULL){
        return NULL;
    }
    int id;
    int age;
    float salary;
    fscanf(employees, "%d, %f, %d", &id, &salary, &age);
    emps->ID = id;
    emps->salary = salary;
    emps->age = age;
    return emps;
}

void mergesort(void **arr, int left, int right){
    if (left < right){
        int middle = (left + (right-1))/2;
        mergesort(arr, left, middle);
        mergesort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}