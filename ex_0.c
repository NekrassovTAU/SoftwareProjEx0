#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void baseConversion();

int baseInput(char *string);

void errorMessage(char *string);

int numInput(char *msg, int base);

int convertNumber(int number, int baseOriginal, int baseDesired);

int convertToDecimal(char c, int original);

void convertToDesiredBase(int number, int baseDesired);

int main()
{
    baseConversion();
    return 0;
}

void baseConversion() {
    int baseOriginal, baseDesired, number, output;
    char c;
    baseOriginal = baseInput("> Please enter the numbers base:");
    if (baseOriginal < 2 || baseOriginal > 16) {
        errorMessage("> Invalid input base");
    }
    baseDesired = baseInput("> Please enter the desired base:");
    if (baseDesired < 2 || baseDesired > 16) {
        errorMessage("> Invalid desired base");
    }
    //number = numInput("> Please enter a number in base ", baseOriginal);
    printf("Please enter a number in base ", baseOriginal);

    c = getchar();
    if (c != EOF) {
        number += convertToDecimal(c, baseOriginal);
        c = getchar();
    }

    while (c != EOF){
        number = (number * baseOriginal) + convertToDecimal(c, baseOriginal);
        c = getchar();
    }

    // convert number to desired base
    convertToDesiredBase(number, baseDesired);


/*
    if (number != 0){
     }
     */
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
