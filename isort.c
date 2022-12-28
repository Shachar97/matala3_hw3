#include "isort.h"
#include <stdio.h>
// #define DEBUGER_SWAP
#define DEBUGER_SHIFT
#define DEBUGER_INSERT

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
    while(counter<=i)
    {
        printf("%d ",*(adr));
        adr = arr+counter;
        counter++;
    }
    printf("]");
    
#endif

    int j = 0;

    #ifdef DEBUGER_SHIFT
        printf("\n\tthe array after shift element:\t[");
    #endif

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

void insertion_sort(int* arr , int len){
    
    if (len==1) {return;}
    
    for (size_t i = 0; i < len-1; i++){

       for (size_t j = i+1; i < len; j++){

            int temp = 0;
            while ( (temp < j) && ( *(arr+temp) < *(arr+j) )){

                temp++;
            }

            if ( *(arr+temp) > *(arr+j) ){

                int shifts = j-temp;
                shift_element(arr+temp,shifts);
            }
            
       }
       
    }
    return;    
}
