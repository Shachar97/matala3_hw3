#include <stdio.h>
#include "txtfind.h"
#include <string.h>

// #define DEBUGER_SWAP
// #define DEBUGER_SHIFT
// #define DEBUGER_SUBSTRING

#define MAIN
#define GETLINE
#define LINE 256
#define WORD 30


int main() {
    char word[WORD];
    char select;

    getword(word);
    scanf(" %c\n", &select);
    //printf("%s\n",word);

    if (select == 'a'){
        print_lines(word);
    }
    else if (select == 'b'){
        print_similar_words(word);
    }
    return 0;
}

int ggetline(char str[]){
    #ifdef GETLINE
    #endif
    int index = 0 ;
    char input = '1';//reset

    while(index < LINE){
        int ans=scanf("%c", &input);
        
        if ( ans== EOF)
        {
            str[index] = '\0';
            break;
        }
        if (input == '\n')
        {
            
            str[index] = '\0';
            break;
        }
        str[index]=input;
        index++;
    }
    if(index==LINE){
        index--;
        str[index] = '\0';
    }
    return strlen(str);
}

   
    int getword(char str[]){

    int index = 0 ;
    char input = '1';//reset

    while(index < WORD){
        int ans=scanf("%c", &input);
        if(ans==EOF){
            str[index]='\0';
            break;
        }
        if (input == '\n' || input == '\t' || input == ' ' )
        {
            str[index]='\0';
            break;
        }
        str[index]=input;
        index++;
    }
    if(index==WORD){
        index--;
        str[index] = '\0';
    }
    return strlen(str);
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
        
    }   
    return 0;
}

//s -> t
int similar (char *s, char *t, int n){
    for(int i=0;i<=n;i++){
        while (*s && *t && *s == *t) {
        s++;
        t++;
        }
        if(*t==0 &&*s==0){
            return 1;
        }
        s++;
    }
    return 0;
}
void print_lines(char * str){
    char line[LINE]={0};

    while(ggetline(line)!=0){
        if(substring(line,str)){
            printf("%s\n",line);
        }
    }
}
void print_similar_words(char * str){
    char word[WORD]={0};

    while(getword(word)!=0){
        if(similar(word,str,1)){
            printf("%s\n",word);
        }
    }
}

