/*
 * student name: MingCong,Zhou
 * student number: 250945414
 * student account: mzhou272
 */

#include <stdio.h>
#include <math.h>

/**
 * This is a recursive function in logarithmic time in
 * terms of absolute value of the exponent inputted
 * @param base is simply the base which is always positive when calling the function
 * @param exponent is simply the exponent
 * @return float the math answer
 */
float expCalculator(float base, int exponent) {

    if (exponent == 0){
        return 1;    //when exponent is equal to 0, by math should return one.
    }

    //divide into two cases one is positive, one is negative
    if (exponent > 0) {
        if (exponent == 1) {
            return base;//by math when exponent is 1, = itself
        } else if (exponent % 2 == 0) {
            return (expCalculator(base * base, exponent / 2.0));  // in the case of exponent = even
        } else {            // in the case of odd
            return base * (expCalculator(base * base, (exponent - 1) / 2.0));
        }
    }else{
        //-exponent will change to positive to solve the problem, and 1/ will change
        //it to negative exponent value
        return 1/expCalculator(base,-exponent);
    }
}

/**
 * That is the main function of this program
 * @return the correct answer
 */

int main() {

    // declaration of two variables
    float base;
    int exponent;

    //a do while loop to handle the negative base
    do{
        printf("what is your base? :");
        scanf("%f", &base);
        getchar();
    }while (base < 0);

    //ask for exponent.
    printf("what is your exponent? :");
    scanf("%d", &exponent);
    getchar();

    //call function
    printf("Your result is:\n"
           "%f",expCalculator(base,exponent));

    //type int, need to return a int value.
    return 0;

}