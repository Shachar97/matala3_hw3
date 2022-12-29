#include <stdio.h>
//#include "isort.h"
#include <string.h>

// #define DEBUGER_SWAP
//#define DEBUGER_SHIFT
// #define DEBUGER_SUBSTRING
#define LINE 256

int ggetline(char s[]){
    int index = 0 ;
    char input = '1';
    while(input != '\n'){
        scanf("%c", &input);
        s[index]=input;
    }
    return 0;
}
// int getword(char w[])
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
    
#ifdef DEBUGER_SUBSTRING
#endif
}


// int similar (char *s, char *t, int n)
// void print_lines(char * str)
// void print_similar_words(char * str)


int main (){

    char ch1[]="fwayabcdefagjafafaykde";
    char ch2[]="fay";
    char str[LINE];
    int ans = ggetline(str);
    printf("the get line return: %s",str);

    int x=0;
    x=substring(ch1,ch2);
    printf("%d\n", x);
    return 0;
}