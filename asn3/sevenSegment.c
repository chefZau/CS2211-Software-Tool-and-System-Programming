/**
 *  This program display the integer in seven segment.
 *
 *  @author MingCong, Zhou
 *  @studentNumber 250945414
 *  @studentAccount mzhou272
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

//Function Prototypes
void sevenSegment(int input);
int getDigitLen(unsigned x);

//three dimensional array of characters to store the 10 digits
const char segments[10][3][3] = {
        {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},        //0
        {{' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' '}},        //1
        {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},        //2
        {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},        //3
        {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},        //4
        {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},        //5
        {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},        //6
        {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},        //7
        {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},        //8
        {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}},        //9
};

/**
 * That is the main function of the program
 * It will keep asking the value if the user do not want to quit
 * @return 0
 */
int main() {
    int input;
    char stop = 'Y';
    while (stop == 'Y') {
        printf("Enter the integer that you want to convert to\n"
               "seven segment display please: \n");
        scanf(" %d", &input);
        getchar();
        sevenSegment(input);  //through it into the function that display integer

        printf("Do you want to continue?\n" "Y for yes, N for No: \n");
        scanf(" %c", &stop);
    }
    printf("( ･᷄ὢ･᷅ )：Thank you for using our app\n"
           "have a wonderful day my dear (⁎⁍̴̛ᴗ⁍̴̛⁎)");

    return 0;
}

/**
 * This function display the seven segment
 * using array as a buffer and for loop for print
 * @param input the user input which is int
 */
void sevenSegment(int input) {

    //on gaul the header of each line would influence the display
    //I create some new line in here to avoid the movement
    printf("Your input is:%d\n\n\n\n", input);

    //if the input is negative, that is not we want
    //negative value is not require on the instruction
    //therefore simply convert it to positive.
    if (input>0){
        input = abs(input);
    }


    //The length of the user input is calculated,
    //then it will use to create a new array as the size
    //Additionally, a new three dimensions array is created to store the output
//    int nDigits = floor(log10(abs(input))) + 1;
    int nDigits = getDigitLen(input);
    int array[nDigits];
    char display[nDigits][3][3];

    //insert each digits on the input,
    // to the array
    int i;
    for (i = nDigits; i --;){
        array[i] = input%10;
        input = input/10;
    }

    //use segments as reference and assign them to the
    for(int i = 0;i<nDigits;i++){
        for(int row = 0;row<3;row++){
            for(int column = 0; column <3;column++){
                display[i][row][column] = segments[array[i]][row][column];
            }
        }
    }

    for(int row = 0;row<3;row++){
        for(int digit = 0; digit<nDigits;digit++){
            for(int column = 0; column<3;column++){
                printf("%c",display[digit][row][column]);
            }
        }
        //this line is important if it does not exist the
        //output will be output in the same line
        printf(" \n");
    }
}

int getDigitLen(unsigned x) {
    if(x >= 100000) {
        if(x >= 10000000) {
            if(x >= 1000000000) return 10;
            if(x >= 100000000) return 9;
            return 8;
        }
        if(x >= 1000000) return 7;
        return 6;
    } else {
        if(x >= 1000) {
            if(x >= 10000) return 5;
            return 4;
        } else {
            if(x >= 100) return 3;
            if(x >= 10) return 2;
            return 1;
        }
    }
}



