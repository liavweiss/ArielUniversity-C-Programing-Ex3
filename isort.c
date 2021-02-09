#include "isort.h"
#define size_array 50

int main()
{
    int i=0;
    int r [size_array]={0};
    for (int j = 0; j < size_array; ++j) {
        scanf("%d", &i);
        *(r+j)=i;
    }
    insertion_sort(r, size_array);
    for (int k = 0; k <size_array ; ++k) {
        if (k== size_array - 1) {
            printf("%d", *(r + k));
        } else {
            printf("%d", *(r + k));
            printf(",");
        }
    }
    return 0;
}

void shift_element(int* arr, int i){
    for(int j=0 ; j<i ; j++){
        *(arr+i-j) = *(arr+i-j-1);
    }
}

void insertion_sort(int* arr , int len){
    for(int i=1 ; i<len ; i++){
        int j = i;
        int counter = 0;
        while(j>0 && *(arr+i)<*(arr+j-1)){
            j--;
            counter++;
        }
        int current = *(arr+i);
        shift_element(arr+i-counter,counter);
        *(arr+i-counter) = current;
    }
}


