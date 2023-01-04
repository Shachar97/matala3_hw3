/*LIBS & INPURTS*/
#include "isort.h"
#include <stdio.h>

/*CONSTANTS*/
#define LEN 50

/*~DEBUGERS~*/
// #define DEBUGER_SWAP //print adrresses and value before and after swap
// #define DEBUGER_SHIFT //print array before and after shift
// #define DEBUGER_INSERT //print array in all the variation until it sort


/* ~MAIN~
*Using Insertion-Sort-Algorithm,
The program get from the user list of integers numbers and print the sort list.
O(LEN^2)
*/
int main(){
    int my_arr[LEN];
    int input;
    int index=0;

    //get all the integer number from the user //O(LEN)
    while(index<LEN){
        scanf("%d[ \t]",&input);
        *(my_arr+index)=input;
        index++;
    }

    insertion_sort(my_arr, LEN);//sort the list //O(LEN^2)

    //print the Sort list //O(LEN)
    for (size_t i = 0; i < LEN-1; i++){
        printf("%d,",*(my_arr+i));
    }
    printf("%d\n",*(my_arr + (LEN-1)));
    return 0;
}

/*in the Array arr, swap the value of the index a & b*/
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

/*from adrress 'arr' to adrress 'arr+(i-1)' move the values one step to the right,
 the value in 'arr+i' move to adrress 'arr'
 O(i) */
void shift_element(int* arr, int i){
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

    //go through all the int adrresses arr to i:
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

/*Insertion-Sort-Algorithm- in given ARR Adrress and LEN of Array, return the Array Sorted low to high
 Run Time Calculation- 
    (1) if in any interaction in the loop we use shift_element to all the sub array: O(n)+O(1+2+...+n)= O(n^2)
    (2) if we dont use the shift_element at all: O(n)
*/
void insertion_sort(int* arr , int len){
    
    if (len==1) {return;}//not need to Sort.
    
    #ifdef DEBUGER_INSERT
        printf("~~~in insertion_sort function:~~~~\n");
        printf("\tthe array befor sort: [");
        for (size_t i = 0; i < len; i++){
            printf("%d ",*(arr+i));
        }
        printf("]\n");
    #endif

    //go through the Array:
    for (size_t i = 1; i < len; i++){

        //is the new number (i) is not his place in the sub-array?
        if (*(arr+i) < *(arr+(i-1))){
            int j = 0;
            //find where to put the new number
            while ( (j < i) && ( *(arr+j) < *(arr+i) )){
                j++;
            }

            int shifts = i-j;//how shifts
            shift_element(arr+j,shifts);//sort the sub array with the new number in his place.
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
