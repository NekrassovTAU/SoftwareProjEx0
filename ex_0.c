#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void baseConversion();

int baseInput(char *string);

void errorMessage(char *string);

int numInput(char *msg, int base);

int con();

int convertNumber(int number, int baseOriginal, int baseDesired);

int convertToDecimal(char c, int baseOriginal);

void convertToDesiredBase(int number, int baseDesired);

void clearInputBuffer();

int main()
{
    baseConversion();
    return 0;
}

void baseConversion() {
    int baseOriginal, baseDesired, number = 0;
    char c;
    baseOriginal = baseInput("> Please enter the numbers base:");
    if (baseOriginal < 2 || baseOriginal > 16) {
        errorMessage("> Invalid input base");
    }
    baseDesired = baseInput("> Please enter the desired base:");
    if (baseDesired < 2 || baseDesired > 16) {
        errorMessage("> Invalid desired base");
    }

    printf("Please enter a number in base %d :", baseOriginal);
    clearInputBuffer();

    if ((c = getchar()) != EOF) {
        number += convertToDecimal(c, baseOriginal);
    }

    while ((c = getchar()) != EOF && c != '\n'){

        number = (number * baseOriginal) + convertToDecimal(c, baseOriginal);
    }

    printf("The number is : %d \n" ,number);
    // convert number to desired base
    convertToDesiredBase(number, baseDesired);

    exit(0);
}

void clearInputBuffer() {
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void convertToDesiredBase(int number, int baseDesired){
    int tmp;
    char c;
    if (number == 0){
        printf("0");
    }
    while(number != 0){
        tmp = number % baseDesired;
        number /= baseDesired;
        if(tmp < 10){
            printf("%d ",tmp);
        }
        else{
            c = tmp + 'W';
            printf("%c ", c);
        //    printf(tmp + 'W');
        }
    }
}

int convertToDecimal(char c, int baseOriginal) {
    int num = c - '0';
    if(num < 10){
        if (num >= 0 && num < baseOriginal) {
            return num;
        }
    }
    else {
        num = c - 'W';
        if(num >= 0 && num < baseOriginal){
            return num;
        }
    }

    errorMessage("Invalid number!");
}

int numInput(char *msg, int base) {
    int tmp;
    printf("%s %d:", msg, base);
    scanf("%d", &tmp);
    return tmp;
}

void errorMessage(char *msg) {
    printf("%s", msg);
    exit(0);
}

int baseInput(char *msg) {
    int tmp;
    printf("%s", msg);
    scanf("%d", &tmp);
    return tmp;
}

/*
int con(){
    int c;
    while ((c = getchar()) != EOF || c != '\n') {
        printf(" \nCharacter we put is:");
        putchar(c);
        if (c == '\n') {
            printf("YEET");
        }
    }
    return 0;
}
*/