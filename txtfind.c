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
/*The function receives a string (character by character) from the input standard and saves it in the string s. The function will return
the amount of characters actually received.
 The line size is fixed in the program 256 LINE define#
 A line will always end with the character 'n\'
 in scanf If a reading error happens or the end-of-file is reached while reading, the proper indicator is set (feof or ferror)
 . And, if either happens before any data could be successfully read, EOF is returned(https://cplusplus.com/reference/cstdio/scanf/?kw=scanf).
*/
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
/*The function receives a string (character by character) from the standard input and saves it in the string w. The function
will return the amount of characters actually received.
 The size of the word is fixed in the program 30 WORD define#
 A word will always end with one of the characters '', '\t', '\n'*/
   
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
/*The function receives two strings str1 and str2 and checks whether str2 is contained in str1). ) substring
The function will return 1 if yes and 0 if not
strcmp is a utility function that checks whether the string is exactly equal*/
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
/*The function will receive two strings t s and a number n. The function will check if it is possible to get from the string S to the string t
By omitting n characters.
For identical strings and the number 0 the program will return 1 only if the two strings are identical.*/
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
/*The function receives the desired string for search, receives the lines of text, and prints the lines in them
appears
.the string, using the relevant functions defined above*/
void print_lines(char * str){
    char line[LINE]={0};

    while(ggetline(line)!=0){
        if(substring(line,str)){
            printf("%s\n",line);
        }
    }
}
/*The function receives the desired string for search, captures the words of the text and prints the words
similar to string
The search up to the omission of one letter from the words appearing in the text (including words identical to the string).
the search
The function will use the relevant functions defined above*/
void print_similar_words(char * str){
    char word[WORD]={0};

    while(getword(word)!=0){
        if(similar(word,str,1)){
            printf("%s\n",word);
        }
    }
}

