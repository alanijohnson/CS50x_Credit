#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    long cardNo = get_long("Enter Credit Card Number: ");

    long num = cardNo;
    int sum = 0;
    int digitNum = 1;
    int digit;
    int cardNoLength = log10(cardNo) + 1;
    do {
        digit = num % 10;
        //printf("%i, %i\n",digit, digitNum % 2);
        if (digitNum % 2 == 0){
            //even digits
            sum += ( digit*2 < 10 ? digit*2 : (digit*2 % 10 + 1) );
        } else{
            //odd digits
            sum += digit;
        }

        printf("%i, %i, %i\n",digit, digitNum % 2, sum);

        digitNum++;
        num = num / 10;

    } while (digitNum <= cardNoLength);


}