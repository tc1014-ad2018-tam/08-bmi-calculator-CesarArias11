/* This program will calculate de BMI of a persona based on his/her weight and height.
 * The user can decide whether using imperial or metric system.
 * If he/she decides to use imperial, it will automatically convert the variables into metric metric.
 * If will also state the user's classification.
 * Author: Cesar Alejandro Arias Perales
 * Date: September 13th, 2018
 * Email: a01411995@itesm.mx
 */

#include <stdio.h>
#include <math.h>

// Conversion from imperial to metric and calculation of BMI
void iBmi (double h, double w, double* BMI) {
    w = w * 0.453592;
    h = h * 0.3048;
    *BMI = w / pow (h,2);
}
// Calculation of BMI in metric.
void nBmi (double h, double w, double* BMI) {
    *BMI =  (w / pow (h,2));
}
// Classification depending on BMI.
void classification (double BMI) {
    if (BMI < 18.5) {
        printf ("Underweight.");
    } else if (BMI >= 18.5 && BMI <= 24.9){
        printf ("Normal weight.");
    } else if (BMI >= 25 && BMI <= 29.99  ) {
        printf ("Overweight.");
    } else if (BMI >= 30) {
        printf ("Obese.");
    }

}

int main() {
    // Variables for main function
    int options;
    double weight = 0.0;
    double height = 0.0;
    double BMI = 0.0;


    printf ("If you want to use imperial system: Type 1.\n");printf ("If you want to use the metric system: Type 2.\n");
    printf ("Which one did you choose?");
    scanf ("%i", &options);

// The menu options
    switch (options){
        case 1:
            printf ("What is your weight in pounds?\n");
            scanf ("%lf", &weight);
            printf ("What is your height in feet?\n");
            scanf ("%lf", &height);
            iBmi (height, weight, &BMI);
            break;
        case 2:
            printf ("What is your weight in kilograms?\n");
            scanf ("%lf", &weight);
            printf ("What is your height in meters?\n");
            scanf ("%lf", &height);
            nBmi (height, weight, &BMI);
            break;
        default:
            printf ("ERROR. Please select one of the options.");
            return 0;
    }
// Give the results to the user.
    printf ("Your BMI is: %lf \n", BMI);
    classification (BMI);


    return 0;
}