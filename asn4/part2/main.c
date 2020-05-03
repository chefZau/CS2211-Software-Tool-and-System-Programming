/**
 * This program will approximate the Pi
 * @author MingCong,ZHOU
 * @studentNumber: 250945414
 * @studentAccount: mzhou272
 */

#include <stdio.h>

//prototype of the two funciton
long long n_Calculator(double e);
double pi_Calculator(long long n);


/**
 *  This is the main function of the program
 * @return 0 nothing
 */
int main() {

    //Creatning varibale to catch the
    //  the user input
    double t;
    printf("how precise do you want: ");

    scanf(" %lf",&t);
    getchar();  //handle the return key

    //call functions
    long long n = n_Calculator(t);
    double pi = pi_Calculator(n);

    printf("the Pi is:  %lf\n",pi);

    return 0;
}

/**
 * This function is use to calculate the n
 * the n is the times that we need to
 * approximate the summation
 *
 * @param e is the input that we ask for the user
 *      simply mean the precision of the Pi
 * @return
 */
long long n_Calculator(double e){

    long long n = 1;
    double approximate = 0;

    //By the formula of 4/2(n+1)-1 < than the user input
    //need to be call once before the while loop
    // or it will not be initialized
    approximate = 4.0/(2.0*(n+1.0)-1.0);

    while(approximate>=e){
        approximate = 4.0/(double)(2.0*(n+1.0)-1.0);
        n++; //approximating
    }


    return n+1;  //return n, is not that precise, therefore I
                //purposely add one looks more precise
}
/**
 * That is the funciton that I create
 * to calculate the Pi after we get the n
 * which is the times that we approximate.
 * @param n times that we approximate the infinite series
 * @return  the value of Pi
 */
double pi_Calculator(long long n){

    double pi = 0.0;

    //approaching n
    for(long long i = 1;i<=n;i++){

        //By the definition of the series
        //the sign is alternating,
        //odd 1 even -1
        int sign;
        if (i % 2 == 0) {
            sign = -1;
        } else {
            sign = 1;
        }
        //approximating
        double terms = 4.0/((double)2.0*i-1.0);

        //sum every therm up
        pi += sign*terms;
    }
    return pi;
}

