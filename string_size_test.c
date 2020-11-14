#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // rewrite the string without spaces
    int i;
    char str[] = "this is a test string to tokenize", *ptr, result[40] = "";
    char *str2 = "this is another dud for tokenizing", *ptr2, result2[40] = "";
    char *str3 = "this is yet another dummy for tokenizing", *result3;
    char *str4 = "destruction test string";

    // part1
    ptr = strtok(str, " ");
    while(ptr != NULL){
        strcat(result, ptr);
        ptr = strtok(NULL, " ");
    }
    printf("strtok with string variable (char array) declaration: \n%s\n\n", result);

    // part2
    ptr2 = result2;
    while(*str2 != '\0'){
        if(*str2 == ' ') str2++;
        *ptr2++ = *str2++;
    }
    printf("const string pointer declaration:\n%s\n\n", result2);

    // part3
    result3 = (char*)malloc(40*sizeof(char));
    i = 0;
    while(*str3 != '\0'){
        if(*str3 == ' ') str3++;
        *(result3+(i++)) = *str3++;
    }
    printf("malloc pointer declaration:\n%s\n\n", result3);

    // part4
    printf("const string destruction test\nbefore: %s\n", str4);
    str4[5] = 'x';
    printf("after: %s\n", str4);
    
    return 0;
}