#include "isort.h"
#include <stdio.h>
// #define DEBUGER_SWAP
// #define DEBUGER_SHIFT
// #define DEBUGER_INSERT

void swap(int* arr, int a, int b){//O(1)
#ifdef DEBUGER_SWAP
    printf("~~~in swap function:~~~~\n\tadrress of array: %p\n\tadrress of array[a]: %p his value is: %d\n\tadrress of array[b]: %p his value is: %d",arr,(arr+a),*(arr+a),(arr+b),*(arr+b) );
#endif
    int temp =*(arr+a);
    *(arr+a)= *(arr+b);
    *(arr+b)= temp;
#ifdef DEBUGER_SWAP
    printf("\n\tadrress of array: %p\n\tadrress of array[a]: %p his value is: %d\n\tadrress of array[b]: %p his value is: %d",arr,(arr+a),*(arr+a),(arr+b),*(arr+b) );
    printf("\n~~~~~~~~~~~~~~~~\n");
#endif

    return;
}

void shift_element(int* arr, int i){//O(i)
    #ifdef DEBUGER_SHIFT
        printf("~~~~in shift_element:~~~~\n\tthe array from the pointer to i: [");
        int counter = 1;
        int* adr = arr;
        while(counter<=i){
            printf("%d ",*(adr));
            adr = arr+counter;
            counter++;
        }
        printf("]");
        printf("\n\tthe array after shift element:\t[");
    #endif

    int j = 0;

    while (j<i)
    {
        swap(arr ,j,i);

        #ifdef DEBUGER_SHIFT
            printf("%d ", *(arr+j));
        #endif

        j++;
    }

    #ifdef DEBUGER_SHIFT
        printf("]\n");
        printf("~~~~~~~~~~~~~~~~\n");
    #endif

    return;
}

void insertion_sort(int* arr , int len){//if in any interaction in the loop we will do shift_element- O(1+2+...+n)-> O(n^2)
    
    if (len==1) {return;}//array is orgenized
    
    #ifdef DEBUGER_INSERT
        printf("~~~in insertion_sort function:~~~~\n");
        printf("\tthe array befor sort: [");
        for (size_t i = 0; i < len; i++){
            printf("%d ",*(arr+i));
        }
        printf("]\n");
    #endif

    for (size_t i = 1; i < len; i++){
        int j = 0;
        while ( (j < i) && ( *(arr+j) < *(arr+i) )){

            j++;
        }

        if ( *(arr+j) >= *(arr+i) ){

            int shifts = i-j;
            shift_element(arr+j,shifts);
        }
        #ifdef DEBUGER_INSERT
            printf("\tthe array after sort: [");
            for (size_t i = 0; i < len; i++){
                printf("%d ",*(arr+i));
            }
            printf("]\n");
            printf("~~~~~~~~~~~\n");
        #endif
    }
    return;    
}
