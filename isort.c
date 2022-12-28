#include "isort.h"
#include <stdio.h>
// #define DEBUGER_SWAP
#define DEBUGER_SHIFT
#define DEBUGER_INSERT

void swap(int* arr, int a, int b){//O(1)
#ifdef DEBUGER_SWAP
    printf("in swap function:\n\tadrress of array: %p\n\tadrress of array[a]: %p his value is: %d\n\tadrress of array[b]: %p his value is: %d",arr,(arr+a),*(arr+a),(arr+b),*(arr+b) );
#endif
    int temp =*(arr+a);
    *(arr+a)= *(arr+b);
    *(arr+b)= temp;
#ifdef DEBUGER_SWAP
    printf("\n\tadrress of array: %p\n\tadrress of array[a]: %p his value is: %d\n\tadrress of array[b]: %p his value is: %d",arr,(arr+a),*(arr+a),(arr+b),*(arr+b) );
#endif

    return;
}

void shift_element(int* arr, int i){//O(i)
#ifdef DEBUGER_SHIFT
    printf("in shift_element");
#endif
    int j = 0;
    while (j<i)
    {
        swap(arr ,*(arr+j),*(arr+(i)));
        j++;
    }

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
