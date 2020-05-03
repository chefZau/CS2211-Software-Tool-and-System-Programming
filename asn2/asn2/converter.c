/**
 *
 * student name: MingCong, Zhou
 * student number: 250945414
 * student account: mzhou272
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


/**
 * This function is the conversion between km and mile
 * @return an integer. the correct conversion
 */
int kilometerMile(){


    //declaration of two variables
    //direction: will take the user's prefer direction in this case is 'K' and 'M'
    //inputvalue: will take the value that the user want to convert
    int inputvalue;
    char direction;

    //formally ask once. if the input is invalid then go through the while loop
    printf("K for conversion from Kilometer to Mile, \n"
           "M for conversion from Mile to Kilometer \n"
           "enter the direction plz: ");
    scanf("%c", &direction);
    getchar(); //getchar to handle the "return"

    //while loop if the input is invalid
    while( direction!='K' && direction !='M'){
        printf("K for conversion from Kilometer to Mile, \n"
               "M for conversion from Mile to Kilometer \n"
               "enter the direction plz: ");
        scanf("%c", &direction);
        getchar();
    }

    //user input value scanned
    printf("what is your input value:");
    scanf("%d",&inputvalue);
    getchar();

    //divide into two cases to convert, different direction
    //uses different formula, print out when done
    if(direction == 'K'){
        double b = 0.621 *inputvalue;
        printf("The Value is: %f \n",b);

    }else if (direction == 'M'){
        double b = 1.609 *inputvalue;
        printf("The Value is: %f \n",b);
    }

}

/**
 * This function is the conversion between meter and feet
 * @return an integer. the correct conversion
 */
int meterFeet(){

    //declaration of two variables
    //direction: will take the user's prefer direction in this case is 'M' and 'F'
    //inputvalue: will take the value that the user want to convert
    int inputvalue;
    char direction;

    //formally ask once. if the input is invalid then go through the while loop
    printf("M for conversion from Meter to Feet\n"
           "F for conversion from Feet to Meter\n"
           "Enter your direction plz: ");
    scanf("%c", &direction);
    getchar();

    //while loop if the input is invalid
    while(direction!='M' && direction!='F'){
        printf("M for conversion from Meter to Feet\n"
               "F for conversion from Feet to Meter\n"
               "Enter your direction plz: ");
        scanf("%c", &direction);
        getchar();
    }

    printf("what is your input value:");
    scanf("%d",&inputvalue);
    getchar();

    //divide into two cases to convert, different direction
    //uses different formula, print out when done
    if(direction == 'M'){

        double b = 3.281 * inputvalue;
        printf("The Value is: %f \n",b);

    }else if (direction == 'F'){

        double b = 0.325 * inputvalue;
        printf("The Value is: %f \n",b);
    }

}

/**
 * This function is the conversion between cm and inch
 * @return an integer. the correct conversion
 */
int cmInch(){

    //declaration of two variables
    //direction: will take the user's prefer direction in this case is 'C' and 'I'
    //inputvalue: will take the value that the user want to convert
    int inputvalue;
    char direction;

    //formally ask once. if the input is invalid then go through the while loop
    printf("C for conversion from Centimetre to Inch\n"
           "I for conversion from Inch to Centimetre\n"
           "Enter your direction plz: ");
    scanf("%c", &direction);
    getchar();

    //while loop if the input is invalid
    while(direction!='C' && direction!='I'){

        printf("C for conversion from Centimetre to Inch\n"
               "I for conversion from Inch to Centimetre\n"
               "Enter your direction plz: ");
        scanf("%c", &direction);
        getchar();
    }

    printf("what is your input value:");
    scanf("%d",&inputvalue);
    getchar();

    //divide into two cases to convert, different direction
    //uses different formula, print out when done
    if(direction == 'C'){

        double b = 0.394 *inputvalue;
        printf("The Value is: %f \n",b);

    }else if (direction == 'I'){

        double b = 2.54 *inputvalue;
        printf("The Value is: %f \n",b);
    }
}

/**
 * This function is the conversion between celsius and fahrenheit
 * @return an integer. the correct conversion
 */
int cF(){

    //declaration of two variables
    //direction: will take the user's prefer direction in this case is 'C' and 'F'
    //inputvalue: will take the value that the user want to convert
    int inputvalue;
    char direction;

    //formally ask once. if the input is invalid then go through the while loop
    printf("C for conversion from Celsius to Fahrenheit\n"
           "F for conversion from Fahrenheit to Celsius\n"
           "Enter your direction plz: ");
    scanf("%c", &direction);
    getchar();          //getchar to handle the "return"

    //while loop if the input is invalid
    while(direction!='C' && direction!='F'){

        printf("C for conversion from Celsius to Fahrenheit\n"
               "F for conversion from Fahrenheit to Celsius\n"
               "Enter your direction plz: ");
        scanf("%c", &direction);
        getchar();
    }

    printf("what is your input value:");
    scanf("%d",&inputvalue);
    getchar();   //getchar to handle the "return"


    //divide into two cases to convert, different direction
    //uses different formula, print out when done
    if(direction == 'C'){

        float b = ((float)inputvalue*9/5)+32;
        printf("The Value is: %f \n",b);

    }else if (direction == 'F'){

        float b = ((float)inputvalue-32)*5/9;
        printf("The Value is: %f \n",b);
    }

}

int main() {

    // declaration of variable, userWants will take "1-5"
    char userWants;

    // use a do-while loop to handle improper input
    do{

        printf("• 1 for conversion between Kilometer and Mile\n"
               "• 2 for conversion between Meter and Feet\n"
               "• 3 for conversion between Centimetre and Inch\n"
               "• 4 for conversion between Celsius and Fahrenheit\n"
               "• 5 for quit\n"
               "Please enter:");
        scanf("%c", &userWants);
        getchar();   //getchar to handle the "return"

    }while(userWants!='1' && userWants!='2' &&
    userWants!='3'&& userWants!='4'&& userWants!='5');

    //if is '5' exit immediately, different cases has different function to match
    if (userWants == '5'){
        exit(EXIT_SUCCESS);
    } else if (userWants == '1'){
        return kilometerMile();
    } else if(userWants == '2'){
        return meterFeet();
    } else if (userWants == '3'){
        return cmInch();
    } else if (userWants == '4'){
        return cF();
    } else {
        printf("invalid in this moment \n");
    }

}






