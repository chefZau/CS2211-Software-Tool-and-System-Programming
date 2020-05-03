/**
 *  This program is a simple calculator. you enter a simple arithmetic expression,
 *  this program would give you the answer
 *
 *  @author MingCong, Zhou
 *  @studentNumber 250945414
 *  @studentAccount mzhou272
 *
 */

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
float getNum();
char getOp();
float m_exp(float sub_exp, char op);
float s_exp(float sub_exp, char op);

/**
 * That is the main function of this program.
 * The while loop will keep asking the user to enter the input
 * until they wanna stop
 * @return the calculation
 */
int main() {
    //when stop is not equal to Y
    //the while loop stop
    char stop = 'Y';
    while (stop == 'Y') {

        printf("Enter your simple arithmetic expression please: ");
        float value = s_exp(0, '+');    //run s exp() function as s exp(0, ’+’);
        printf("The value is: \n");
        printf("%f\n\n\n", value);

        printf("You wanna keep calculating?\n"
               "Y for yes, and"
               " N for No:\n");
        scanf(" %c", &stop);

    }
    printf("( ･᷄ὢ･᷅ )：Thank you for using our app\n"
           "have a wonderful day my dear (⁎⁍̴̛ᴗ⁍̴̛⁎)");

    return 0;
}

/**
 * Input: none, read from stdin
 * Effect: get the next numeric value of the expression
 * @return  return the next numeric value of the expression.
 */
float getNum() {
    float val;
    scanf(" %f", &val);
    return val;
}

/**
 * Input: none, read from stdin
 * Effect: get the next operator of the expression，this operator can be +, -, *, /, or ’\n’
 * ’\n’ indicates the end of the expression input
 * leading spaces should skipped
 * @return the next operator of the expression.
 */
char getOp() {
    char val;
    scanf("%c", &val);
    //while there are empty space
    //loop through the next one
    while (val == ' ') {
        scanf("%c", &val);
    }
    return val;
}


/**
 * Deal with the * and /
 * @param sub_exp the value of the current sub m_expression
 * to the left of ’op’ location in stdin.
 * @param op an operator, ’*’ or ’/’. ’op’ could also be
 * ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
 * "+’, ’-’, or ’\n’ should be pushed back to stdin
 * the rest of the m_expression will be read in from stdin
 * @return this function returns the value of the current m_expression
 */
float m_exp(float sub_exp, char op) {

    //check if it is the end of m_exp
    if (op == '+' || op == '-' || op == '\n') {
        //if yes,push back and return sub_exp
        ungetc(op, stdin);
        return sub_exp;
    } else {

        //get next num of m_exp from stdin: save in f1
        //get next op of m_exp from stdin: save in op1
        float f1 = getNum();
        char op1 = getOp();
        if (op == '*') {
            f1 = sub_exp * f1;
        } else if (op == '/') {
            f1 = sub_exp / f1;
        } else {
            printf("The operator you are typing is wrong.\n");
            exit(EXIT_FAILURE);
        }
        return m_exp(f1, op1);
    }
}

/**
 * Effect: the whole s_expression is evaluated using recursion:
 * get next_num with m_exp() and then get next_op with get_op()
 * use ’sub_exp op next_num’ and ’next_op’ to do recursive call
 *
 * @param sub_exp   the value of the sub s_expression to the left of ’op’ location in stdin.
 * @param op   an operator, ’+’ or ’-’. ’op’ could also be ’\n’ indicating the end of the s_expression
 * the rest of the expression will be read in from stdin
 * @return  this function returns the value of the s_expression
 */
float s_exp(float sub_exp, char op) {
    //check if it is the end of m_exp
    if (op == '\n') {
        return sub_exp;
    } else {

        //get next num of m_exp from stdin: save in f1
        //get next op of m_exp from stdin: save in op1
        float f1 = getNum();
        char op1 = getOp();
        //through in mexp to make sure if that is * or /
        f1 = m_exp(f1, op1);
        //if do not get the next op the program would skip the op
        //and return the last num. that end up a wrong number
        op1 = getOp();

        if (op == '+') {
            f1 = sub_exp + f1;
        } else if (op == '-') {
            f1 = sub_exp - f1;
        }

        return s_exp(f1, op1);
    }
}



