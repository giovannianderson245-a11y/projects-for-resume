/*
Giovanni Anderson
8-26-25
Lab 2
Currency Converter
*/
#include<stdio.h>
int main() {
    float amount = 0;
    
	/*US Dollar Conversion*/
	const float USD_TO_GBP = 0.74;
    const float USD_TO_EUR = 0.86;
    const float USD_TO_RUR = 80.50;
    const float USD_TO_JPY = 147.28;
    const float USD_TO_CNY = 7.15;
    
	/*Pound Sterling Conversion*/
	const float GBP_TO_USD = 1.35;
    const float GBP_TO_EUR = 1.16;
    const float GBP_TO_RUR = 108.50;
    const float GBP_TO_JPY = 198.53;
    const float GBP_TO_CNY = 9.64;
    
    /*Euro Conversion*/
    const float EUR_TO_USD = 1.16;
    const float EUR_TO_GBP = 0.86;
    const float EUR_TO_RUR = 93.76;
    const float EUR_TO_JPY = 171.59;
    const float EUR_TO_CNY = 8.33;
    
    /*Russian Ruble Conversion*/
    const float RUR_TO_USD = 0.012;
    const float RUR_TO_GBP = 0.0092;
    const float RUR_TO_EUR = 0.011;
    const float RUR_TO_JPY = 1.83;
    const float RUR_TO_CNY = 0.089;
    
    /*Japanese Yen Conversion*/
    const float JPY_TO_USD = 0.0068;
    const float JPY_TO_GBP = 0.0050;
    const float JPY_TO_EUR = 0.0058;
    const float JPY_TO_RUR = 0.55;
    const float JPY_TO_CNY = 0.049;
    
    /*Chinese Yuan Conversion*/
    const float CNY_TO_USD = 0.14;
    const float CNY_TO_GBP = 0.10;
    const float CNY_TO_EUR = 0.12;
    const float CNY_TO_RUR = 11.25;
    const float CNY_TO_JPY = 20.59;
    

    /*Exchange table*/
    printf("Input the amount you want to convert: ");
    scanf("%f", &amount);
    printf("\n the amount you entered is: %f", amount);
    
    printf("\n    | USD       | GBP        | EUR        | RUR       | JPY       | CNY \n");
    printf("USD |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount, amount * USD_TO_GBP, amount * USD_TO_EUR, 
	amount * USD_TO_RUR, amount * USD_TO_JPY, amount * USD_TO_CNY);
    printf("GBP |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount * GBP_TO_USD, amount, amount * GBP_TO_EUR, 
	amount * GBP_TO_RUR, amount * GBP_TO_JPY, amount * GBP_TO_CNY);
	printf("EUR |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount * EUR_TO_USD, amount * EUR_TO_GBP, amount, 
	amount * EUR_TO_RUR, amount * EUR_TO_JPY, amount * EUR_TO_CNY);
	printf("RUR |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount * RUR_TO_USD, amount * RUR_TO_GBP, amount * RUR_TO_EUR, 
	amount, amount * RUR_TO_JPY, amount * RUR_TO_CNY);
	printf("JPY |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount * JPY_TO_USD, amount * JPY_TO_GBP, amount * JPY_TO_EUR, 
	amount * JPY_TO_RUR, amount, amount * JPY_TO_CNY);
	printf("CNY |%10.2f |%10.2f  |%10.2f  |%10.2f |%10.2f |%10.2f\n", amount * CNY_TO_USD, amount * CNY_TO_GBP, amount * CNY_TO_EUR, 
	amount * CNY_TO_RUR, amount * CNY_TO_JPY, amount);

    return 0;
}