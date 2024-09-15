#include<stdio.h>
 
int main() 

{
    char number[10];
    printf("Enter a number: ");
    fgets(number, sizeof(number), stdin);
    printf("- %c - %c - %c\n", number[0], number[0], number[0]);
    printf("%c | %c | %c\n", number[0], number[0], number[0]);
    printf("- %c - %c - %c\n", number[0], number[0], number[0]);

    return 0;
}

