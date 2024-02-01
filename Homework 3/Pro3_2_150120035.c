//Omer Deligoz 150120035
#include <stdio.h>
int sumOfDigits(int number);
void printRepeatedNumber(int n, int number);

int main() {
    int number, repetitionFactor, super_Digit, i;

    //Take the number and repetition factor from user
    printf("Please enter a number (n=) : ");
    scanf("%d", &number);
    printf("Please enter repetition factor (k=) : ");
    scanf("%d", &repetitionFactor);

    printRepeatedNumber(repetitionFactor, number);

    //Calculate the super digit value
    super_Digit = repetitionFactor * sumOfDigits(number);

    //If the super digit has more than one digit, run the method until it has a single digit
    while(super_Digit >= 10){
        super_Digit = sumOfDigits(super_Digit);
    }

    printf(" is %d.", super_Digit);
    return 0;
}
//This method prints the given number recursively n times.
void printRepeatedNumber(int n, int number) {
    //Base case
    if(n == 1){
        printf("Super digit of number %d",number);
    }
        //Recursive step
    else{
        printRepeatedNumber((n-1), number);
        printf("%d",number);
    }
}

//This method sums the numbers in each digit of the given number
int sumOfDigits(int number) {
    int sum =0;
    //Base case
    if (number < 10) {
        sum += number;
    }
        //Recursive step
    else {
        sum += ((number % 10) + sumOfDigits(number / 10));
    }
    return sum;
}