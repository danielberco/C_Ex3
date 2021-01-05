//
// Created by bercod on 05/01/2021.
//
#include <stdio.h>
#define AR_SIZE 50

void shift_element(int* arr, int i) {
    while ( i != 0) {
        *(arr+i) = *(arr+i-1);
        i = i - 1;
    }
}

void insertion_sort(int* arr , int len) {
    for (int i = 1; i < len; i++) {
        int key = *(arr+i);
        int pre = i-1;
        int j =0 ;

        while (key < *(arr + pre) && pre !=-1) {
            j++;
            pre--;
        }

        if (j>0) {
            shift_element((arr+i-j), j);
            *(arr+i-j) = key;
        }
    }
}

void print (int *a) {
    int i =0;
    for (i=0;i<AR_SIZE-1;i++) {
        printf("%d,", *(a+i));
    }
    printf("%d\n", *(a+i));
}

int main() {
    printf("Insert 50 numberes :\n");
    int num[AR_SIZE];
    int i=0;
    while (i <AR_SIZE) {
        if (scanf("%d", (num+i)) == 1) {
            i++;
        }
    }
    insertion_sort(num,AR_SIZE);
    print(num);
    return 0;
}




