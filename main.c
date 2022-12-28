#include <stdio.h>
#include "isort.h"
// #define TESTER
#define LEN 50
int main(){

    #ifdef TESTER
        int arr1[3] = {1,2,3};
        swap(arr1,0,2);

        int arr2[] = {1,2,3,4,5,6,7,8,9};//
        shift_element((arr2+2), 4); // arr= {1,2,4,5,6,7,3,8,9}

        int arr3[] = {9,1,8,2,7,3,6,4,5};//
        insertion_sort(arr3, 9); // arr= {1,2,4,5,6,7,3,8,9}
    #endif

    int my_arr[LEN];
    int input;
    int index=0;
    while(index<LEN){
        scanf("%d[ \t]",&input);
        *(my_arr+index)=input;
        index++;
    }
    insertion_sort(my_arr, LEN);
    for (size_t i = 0; i < LEN-1; i++){
        printf("%d,",*(my_arr+i));
    }
    printf("%d\n",*(my_arr + (LEN-1)));
    return 0;
}