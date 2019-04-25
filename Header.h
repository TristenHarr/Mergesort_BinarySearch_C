#ifndef LAB12_2050_HEADER_H
#define LAB12_2050_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int ID;
    float salary;
    int age;
}Employee;

Employee* readRecord(FILE*);
int comparison(void*,void*);
int binarySearch(void**,int,int,void*);
void mergesort(void**,int,int);
void merge(void**,int,int,int);
void printResult(Employee**,int,Employee*);

#endif //LAB12_2050_HEADER_H
