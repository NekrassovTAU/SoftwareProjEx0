#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void baseConversion();

int baseInput(char *string);

void errorMessage(char *string);

int numInput(char *msg, int base);

int main()
{
    baseConversion();
    return 0;
}

void baseConversion() {
    int baseOriginal, baseDesired, number, output;
    baseOriginal = baseInput("> Please enter the numbers base:");
    if (baseOriginal < 2 || baseOriginal > 16){
        errorMessage("> Invalid input base");
    }
    baseDesired = baseInput("> Please enter the desired base:");
    if (baseDesired < 2 || baseDesired > 16){
        errorMessage("> Invalid desired base");
    }
    number = numInput("> Please enter a number in base ", baseOriginal);
    if (number != 0){
        output =
    }
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
