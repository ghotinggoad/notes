/*
    Introduction
    When you mix scanf and fgets, inputs are sometimes skipped and you need to flush stdin buffer for the logic flow to be correct.
    This program is used to find out when you need to use scanf("\n") ensure no input is skipped.
    Input methods used are scanf and fgets (stdin), sscanf and gets are not tested here.

    Notes
    Use scanf(" %c") instead of scanf("%c") or else \n isn't flushed before the scanf for characters.
    \ <- this character ignores special characters that use '\' character in strings.
    % <- this character ignores special characters that use '%' character in strings.
    ie. printf("scanf(\"\\n\");"); outputs "scanf("\n")";
    ie. printf("printf("%%c");"); outputs "printf("%c")";
    
    Conclusion
    You need to use scanf("\n") when transitioning from scanf to fgets. -ghotinggoad
    
    Reference
*/

#include <stdio.h>
#include <string.h>

void scanf_int_to_scanf_int();
void scanf_char_to_scanf_char();
void scanf_string_to_scanf_string();
void fgets_string_to_fgets_string();
void scanf_int_to_scanf_char();
void scanf_char_to_scanf_int();
void scanf_int_to_scanf_string();
void scanf_string_to_scanf_int();
void scanf_char_to_scanf_string();
void scanf_string_to_scanf_char();
void scanf_int_to_fgets_string();
void fgets_string_to_scanf_int();
void scanf_char_to_fgets_string();
void fgets_string_to_scanf_char();

int main(){
    int choice;
    printf("This program is used to test when you need to use scanf(\"\\n\");\n");

    while(choice < 1 || choice > 15){
        printf("Select a test case to find out if scanf(\"\\n\") is needed to prevent input skipping.\n");
        printf("1\tscanf int to scanf int\n");
        printf("2\tscanf char to scanf char\n");
        printf("3\tscanf string to scanf string\n");
        printf("4\tfgets string to fgets string\n");
        printf("5\tscanf int to scanf char\n");
        printf("6\tscanf char to scanf int\n");
        printf("7\tscanf int to scanf string\n");
        printf("8\tscanf string to scanf int\n");
        printf("9\tscanf char to scanf string\n");
        printf("10\tscanf string to scanf char\n");
        printf("11\tscanf int to fgets string\n");
        printf("12\tfgets string to scanf int\n");
        printf("13\tscanf char to fgets string\n");
        printf("14\tfgets string to scanf char\n");
        printf("15\tconclusion\n\n");
        printf("Test case: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                scanf_int_to_scanf_int();
                break;
            case 2:
                scanf_char_to_scanf_char();
                break;
            case 3:
                scanf_string_to_scanf_string();
                break;
            case 4:
                fgets_string_to_fgets_string();
                break;
            case 5:
                scanf_int_to_scanf_char();
                break;
            case 6:
                scanf_char_to_scanf_int();
                break;
            case 7:
                scanf_int_to_scanf_string();
                break;
            case 8:
                scanf_string_to_scanf_int();
                break;
            case 9:
                scanf_char_to_scanf_string();
                break;
            case 10:
                scanf_string_to_scanf_char();
                break;
            case 11:
                scanf_int_to_fgets_string();
                break;
            case 12:
                fgets_string_to_scanf_int();
                break;
            case 13:
                scanf_char_to_fgets_string();
                break;
            case 14:
                fgets_string_to_scanf_char();
                break;
            case 15:
                printf("You need to use scanf(\"\\n\") when transitioning from scanf to fgets.\n");
                break;
            default:
                printf("Invalid input, please try again.\n\n");
                break;
        }
    }
    return 0;
}

void scanf_int_to_scanf_int(){
    int num1, num2;
    printf("scanf int to scanf int\n");
    printf("Enter an int: ");
    scanf("%d", &num1);
    printf("Enter another int: ");
    scanf("%d", &num2);
    printf("Result: %d, %d\nNo input skip observed.\n\n", num1, num2);
}

void scanf_char_to_scanf_char(){
    char alpha1, alpha2;
    printf("scanf char to scanf char\n");
    printf("Enter a char: ");
    scanf(" %c", &alpha1);
    printf("Enter another char: ");
    scanf(" %c", &alpha2);
    printf("Result: %c, %c\nNo input skip observed.\n", alpha1, alpha2);
    printf("*** Use scanf(\" %%c\") instead of scanf(\"%%c\").\n\n");
}

void scanf_string_to_scanf_string(){
    char string1[100], string2[100];
    printf("scanf string to scanf string\n");
    printf("Enter a string: ");
    scanf("%s", string1);
    printf("Enter another string: ");
    scanf("%s", string2);
    printf("Result: %s, %s\nNo input skip observed.\n\n", string1, string2);
}

void fgets_string_to_fgets_string(){
    char *p, string1[100], string2[100];
    printf("fgets string to fgets string\n");
    printf("Enter a string: ");
    fgets(string1, 100, stdin);
    if(p = strchr(string1, '\n')) *p = '\0';
    printf("Enter another string: ");
    fgets(string2, 100, stdin);
    if(p = strchr(string2, '\n')) *p = '\0';
    printf("Result: %s, %s\nOne input skip observed.\n", string1, string2);
    printf("*** Use scanf(\"\\n\") before the first fgets() to clear '\\n' from the stdin buffer.\n\n");
}

void scanf_int_to_scanf_char(){
    int num1;
    char alpha2;
    printf("scanf int to scanf char\n");
    printf("Enter an int: ");
    scanf("%d", &num1);
    printf("Enter a char: ");
    scanf(" %c", &alpha2);
    printf("Result: %d, %c\nNo input skip observed.\n", num1, alpha2);
    printf("*** Use scanf(\" %%c\") instead of scanf(\"%%c\").\n\n");
}

void scanf_char_to_scanf_int(){
    char alpha1;
    int num2;
    printf("scanf char to scanf int\n");
    printf("Enter a char: ");
    scanf(" %c", &alpha1);
    printf("Enter an int: ");
    scanf("%d", &num2);
    printf("Result: %c, %d\nNo input skip observed.\n", alpha1, num2);
    printf("*** Use scanf(\" %%c\") instead of scanf(\"%%c\").\n\n");
}

void scanf_int_to_scanf_string(){
    int num1;
    char string2[100];
    printf("scanf int to scanf string\n");
    printf("Enter an int: ");
    scanf("%d", &num1);
    printf("Enter a string: ");
    scanf("%s", string2);
    printf("Result: %d, %s\nNo input skip observed.\n\n", num1, string2);
}

void scanf_string_to_scanf_int(){
    char string1[100];
    int num2;
    printf("scanf string to scanf int\n");
    printf("Enter a string: ");
    scanf("%s", string1);
    printf("Enter an int: ");
    scanf("%d", &num2);
    printf("Result: %s, %d\nNo input skip observed.\n\n", string1, num2);
}

void scanf_char_to_scanf_string(){
    char alpha1, string2[100];
    printf("scanf char to scanf string\n");
    printf("Enter a char: ");
    scanf(" %c", &alpha1);
    printf("Enter a string: ");
    scanf("%s", string2);
    printf("Result: %c, %s\nNo input skip observed.\n\n", alpha1, string2);
}

void scanf_string_to_scanf_char(){
    char string1[100], alpha2;
    printf("scanf string to scanf char\n");
    printf("Enter a string: ");
    scanf("%s", string1);
    printf("Enter a char: ");
    scanf(" %c", &alpha2);
    printf("Result: %s, %c\nNo input skip observed.\n\n", string1, alpha2);
}

void scanf_int_to_fgets_string(){
    int num1;
    char *p, string2[100];
    printf("scanf int to fgets string\n");
    printf("Enter an int: ");
    scanf("%d", &num1);
    printf("Enter a string: ");
    fgets(string2, 100, stdin);
    if(p = strchr(string2, '\n')) *p = '\0';
    printf("Result: %d, %s\nOne input skip observed.\n", num1, string2);
    printf("*** Use scanf(\"\\n\") before the first fgets() to clear '\\n' from the stdin buffer.\n\n");
}

void fgets_string_to_scanf_int(){
    char *p, string1[100];
    int num2;
    printf("fgets string to scanf int\n");
    printf("Enter a string: ");
    fgets(string1, 100, stdin);
    if(p = strchr(string1, '\n')) *p = '\0';
    printf("Enter an int: ");
    scanf("%d", &num2);
    printf("Result: %s, %d\nOne input skip observed.\n", string1, num2);
    printf("*** Use scanf(\"\\n\") before the first fgets() to clear '\\n' from the stdin buffer.\n\n");
}

void scanf_char_to_fgets_string(){
    char *p, alpha1, string2[100];
    printf("scanf char to fgets string\n");
    printf("Enter a char: ");
    scanf(" %c", &alpha1);
    printf("Enter a string: ");
    fgets(string2, 100, stdin);
    if(p = strchr(string2, '\n')) *p = '\0';
    printf("Result: %c, %s\nOne input skip observed.\n", alpha1, string2);
    printf("*** Use scanf(\"\\n\") before the first fgets() to clear '\\n' from the stdin buffer.\n\n");
}

void fgets_string_to_scanf_char(){
    char *p, string1[100], alpha2;
    printf("fgets string to scanf char\n");
    printf("Enter a string: ");
    fgets(string1, 100, stdin);
    if(p = strchr(string1, '\n')) *p = '\0';
    printf("Enter an char: ");
    scanf(" %c", &alpha2);
    printf("Result: %s, %c\nOne input skip observed.\n", string1, alpha2);
    printf("*** Use scanf(\"\\n\") before the first fgets() to clear '\\n' from the stdin buffer.\n\n");
}
