#include <stdio.h>
//#include "isort.h"
#include <string.h>

// #define DEBUGER_SWAP
// #define DEBUGER_SHIFT
// #define DEBUGER_SUBSTRING
#define MAIN
#define GETLINE
#define LINE 256

int ggetline(char str[]){
    #ifdef GETLINE
    #endif
    int index = 0 ;
    char input = '1';

    while(index < LINE){
        scanf("%c", &input);
        if (input == '\n')
        {
            return strlen(str);
        }
        str[index]=input;
        index++;
    }
    return strlen(str);
}

int getword(char w[]){

    return 0;
}

int strcmp1(char *str1, char *str2)
{
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    if(*str2==0){
        return 1;
    }
    return 0;
}
int substring( char * str1, char * str2){

    while(*str1){
        while(*str1&& *str1!=*str2){
            str1++;
        }

        if(*str1==0){
        return 0;
        }
        if(strcmp1( str1, str2)){
            return 1;
        }
        str1++;
        printf("%c ",str1[0]);
    }   
    return 0;
}

//s -> t
int similar (char *s, char *t, int n){
    for(int i=0;i<n;i++){
        while (*s && *t && *s == *t) {
        s++;
        t++;
        }
        if(*t==0){
            return 1;
        }
        s++;

    }
    return 0;
}
// void print_lines(char * str)
// void print_similar_words(char * str)

#ifdef MAIN
    int main (){

        // char ch1[]="fwayabcdefagjafafaykde";
        // char ch2[]="fay";
    //     char str[LINE];
    //     ggetline(str);
    //     printf("the get line return: \n%s",str);

    // char ch1[]="swsystems";
    // char ch2[]="ssysems";
    char str[LINE];
    int ans = ggetline(str);
    printf("the get line return: %s\nthe lenghth is: %d\n",str, ans);
    printf("strlen(str)= %ld",strlen(str));

    // int x=0;
    // x=substring(ch1,ch2);
    // printf("%d\n", x);
    

        // int x=0;
        // x=substring(ch1,ch2);
        // printf("%d\n", x);
        return 0;
    }
#endif
