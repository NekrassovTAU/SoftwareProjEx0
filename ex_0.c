#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void baseConversion();

int baseInput(char *string);

void errorMessage(char *string);

int numInput(char *msg, int base);

int convertNumber(int number, int baseOriginal, int baseDesired);

int convertToDecimal(char c, int original);

void convertToDesiredBase(int number, int baseDesired);

void clearInputBuffer();

int main()
{
    baseConversion();
    return 0;
}

void baseConversion() {
    int baseOriginal, baseDesired, number = 0, output;
    int c;
    baseOriginal = baseInput("> Please enter the numbers base:");
    if (baseOriginal < 2 || baseOriginal > 16) {
        errorMessage("> Invalid input base");
    }
    baseDesired = baseInput("> Please enter the desired base:");
    if (baseDesired < 2 || baseDesired > 16) {
        errorMessage("> Invalid desired base");
    }
    //number = numInput("> Please enter a number in base ", baseOriginal);
    printf("Please enter a number in base %d :", baseOriginal);
    clearInputBuffer();

    if ((c = getchar()) != EOF) {
        printf(" \nCharacter we put is:");
        putchar(c);
        //number += convertToDecimal(c, baseOriginal);
    }

    while ((c = getchar()) != EOF || c != '\n'){
        printf(" \nCharacter we put is:");
        putchar(c);
        if (c == '\n'){
            printf("YEET");
        }
        //number = (number * baseOriginal) + convertToDecimal(c, baseOriginal);
    }

    // convert number to desired base
    //convertToDesiredBase(number, baseDesired);

    exit(0);

/*
    if (number != 0){
     }
     */
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
    if (number == 0){
        printf("0");
    }
    while(number != 0){
        tmp = number % baseDesired;
        number /= baseDesired;
        if(tmp < 10){
            printf(tmp);
        }
        else{
            printf(tmp + 'W');
        }
    }

}

int convertToDecimal(char c, int baseOriginal) {
    int num = c - '0';
    if(num >= 0 && num < baseOriginal){
        return num;
    }
    printf("Didn't reach here");
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