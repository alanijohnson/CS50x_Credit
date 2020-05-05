#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool checkSum(long CardNo, int cardNoLength);

int main(void){

    //Initialize card type as invalid. Card type will be changed to Amex, mastercard, or visa
    string CardType = "INVALID\n";

    //get card number as input from user
    long cardNumber = get_long("Enter Credit Card Number: ");

    //determine metadata about card number (i.e. Length of Card Number and the first 2 digits)
    int cardNoLength = log10(cardNumber) + 1;
    long first2Digits = cardNumber / pow(10,(cardNoLength - 2));

    //use checkSum/Luhns algorithm to determine if card number is valid and assign card types
    if (checkSum( cardNumber, cardNoLength)){
        //Determine card type based on:
        //  a. Card Length
        //  b. Digit Prefix
        if (cardNoLength == 15 && (first2Digits == 34 || first2Digits == 37)){
            //AMEX
            CardType = "AMEX\n";
        } else if (cardNoLength == 16 && (first2Digits >= 51 && first2Digits <=55 )) {
            //MasterCard
            CardType = "MASTERCARD\n";
        } else if ((cardNoLength == 13 || cardNoLength == 16) && first2Digits / 10 == 4) {
            //Visa
            CardType = "VISA\n";
        }
    }

    //output
    printf("%s",CardType);
}

//Method for Luhn's Algorithm
bool checkSum(long cardNo, int cardNoLength){

    //initialize variables
    long num = cardNo;
    int sum = 0;
    int digitNum = 1;
    int digit;

    //sum digits according to Luhn's Algorithm
    //https://cs50.harvard.edu/x/2020/psets/1/credit/
    do {
        digit = num % 10;
        if (digitNum % 2 == 0){
            //even digits - multiply digits by 2 and then sum the indiviudal digits of the product
            sum += ( digit*2 < 10 ? digit*2 : (digit*2 % 10 + 1) );
        } else{
            //odd digits - just add the digit
            sum += digit;
        }

        //printf("%i, %i, %i\n",digit, digitNum % 2, sum);

        digitNum++;
        num = num / 10;

    } while (digitNum <= cardNoLength);


    //results - if last digit of sum is 0, then card number is valid
    if (sum % 10 == 0){
        return true;
    } else {
        return false;
    }

}