#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef enum State{
    NewWord,
    Rubbish,
    Number
} State; 

bool is_NewWord (char symbol) {
    return (symbol == '\n' || symbol == '\t' || symbol == ',' || symbol == ' ') ? true : false;
}

bool is_Number (char symbol) {
    return ((symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'F')) ? true : false;
}

bool is_Rubbish (char symbol) {
    return (!is_Number(symbol) && !is_NewWord(symbol)) ? true : false;
}

bool is_PlusMinus (char symbol) {
    return (symbol == '+' || symbol == '-') ? true : false;
}

void printArray (int size, char array [size]) {
    for (int i = 0; i < size; i++) {
        printf("%c", array [i]);
    }
    if (size == 0) {
        return;
    }
    printf("\n");
}

int main () {
    assert(is_Rubbish('a') == true);
    assert(is_Rubbish('@') == true);
    assert(is_Rubbish('0') == false);
    assert(is_NewWord('\n') == true);
    assert(is_NewWord('\t') == true);
    assert(is_NewWord('i') == false);
    assert(is_PlusMinus('+') == true);
    assert(is_PlusMinus('a') == false);
    assert(is_Number('0') == true);
    assert(is_Number('a') == false);
    State state = NewWord;
    char symbol, *number1, *number2;
    int length = 0, max_length = 100, firstZero = 0, print_length = 0;
    number1 = (char *) malloc(max_length * sizeof(char));
    number2 = (char *) malloc(max_length * sizeof(char));
    number1 [0] = ' ';
    bool flag = true, printed = false;
    while ((symbol = getchar()) != EOF) {
        switch (state) {
            case NewWord:
                if (is_NewWord(symbol)) {
                    break;
                }
                if (is_PlusMinus(symbol)) {
                    state = Number;
                    break;
                }
                if (is_Number(symbol)) {
                    state = Number;
                    firstZero = symbol - '0';
                    if (firstZero == 0) {
                        break;
                    }
                    else {
                        flag = false;
                    }
                    number2 [length] = symbol;
                    length++;
                    break;
                }
                state = Rubbish;
                break;
            case Rubbish:
                if (is_NewWord(symbol)) {
                    state = NewWord;
                }
                break;
            case Number:
                if (is_Number(symbol)) {
                    if (flag) {
                        firstZero = symbol - '0';
                        if (firstZero == 0) {
                            flag = true;
                            break;
                        }
                        else {
                            flag = false;
                        }
                    }
                    if (length >= max_length) {
                        max_length *= 2;
                        number1 = (char *) realloc(number1, max_length * sizeof(char));
                        number2 = (char *) realloc(number2, max_length * sizeof(char));
                    }
                    number2 [length] = symbol;
                    length++;
                    break;
                }
                else if (is_NewWord(symbol)) {
                    state = NewWord;
                    if (length == 0) {
                        number2 [0] = '0';
                    }
                    if (symbol == '\n') {
                        printArray(print_length, number1);
                        break;
                    }
                    strcpy(number1, number2);
                    print_length = length;
                    length = 0;
                }
                else {
                    state = Rubbish;
                }
                length = 0;
                flag = true;
                firstZero = 0;
                break;
        }
    }
    if (strcmp(number1, number2)) {
        printf("\n");
        printArray(print_length, number1);
    }
    return 0;
}
