/*
 * Number base conversion class for cpp
 * 
 * Author: Nuri Melih Sensoy
 * File: "base_conversion.cpp"
*/
#include "base_conversion.h"

/** <PRIVATE> **/

int Base_Conversion::strlen(char* number){
    int len=0;
    while(number[len] != '\0'){
        len++;
    }
    return len;
}

int Base_Conversion::pow(int x, unsigned int y) {
    int temp; 
    if( y == 0) 
        return 1; 

    temp = pow(x, y/2); 

    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 

int* Base_Conversion::convert_dec_to(int decimal, int base){
    int *arr = (int*)malloc(sizeof(int)*10);
    int size = 1;
    do{
        int remain = decimal%base;
        decimal /= base;      
        	
        *(arr+size) = remain;
        size++;
        arr = (int*)realloc(arr, sizeof(int)*(size));
    }while(decimal > base-1);

    *(arr+0) = size;
    *(arr+size) = decimal;

    return arr;
}

/** </PRIVATE> **/
/** <PUBLIC> **/

int Base_Conversion::countDigit(int number){
    if(number == 0)
        return 0;

    return 1 + countDigit(number/10);
}

int Base_Conversion::toDecimal(int number, int base){
    int digitC = 0,
        sum = 0;

    digitC = countDigit(number);

    for(int i=digitC; i>0; i--){
        int remain = number%10;
        number /= 10;
        sum += pow(base, digitC-i)*remain;
    }

    return sum;
}

int Base_Conversion::toDecimal(char* number, int base){
    int digitC = 0,
        sum = 0,
        i = 0;
    
    digitC = strlen(number);

    if(number[0] == '0' and number[1] == 'x'){
        i = 2;
    }

    for(i; i<digitC;i++){
        char current = number[i];
        if(current >= 'A' and current<='F'){
			current = (int)(current-16)+9;
		}else if(current >= 'a' and current<='f'){
            current = (int)(current-48)+9;
        }

        int ct = current - '0';
        sum += pow(base, digitC-i-1)*ct;
    }

    return sum;
}

char* Base_Conversion::decimalTo(int decimal, int base){
    int *arr = convert_dec_to(decimal, base);
    int size = *(arr+0);

    char *arrC = (char*)malloc(sizeof(char)*size);

    for(int i=size; i>0; i--){
        int &current = *(arr+i);
        if(current>9)
            current = (char)((current-10) + 'a');
        else
            current = (char)current + '0';

        *(arrC+size-i) = current;
    }

    free(arr);
    return arrC;
}

int Base_Conversion::decimalToInt(int decimal, int base){
    int *arr = convert_dec_to(decimal, base);
    int size = *(arr+0);
    int sum = 0;

    *(arr+0) = 0;
    for(int i=size; i>0; --i){
        int &current = *(arr+i);
            sum += pow(10, i-1)*current;
    }
    free(arr);

    return sum;
}   

int Base_Conversion::base2Base(int number, int base, int convert_base){
    return decimalToInt(toDecimal(number, base), convert_base);
}   

char* Base_Conversion::dec2Hex(int decimal){
    return decimalTo(decimal, 16);
}

int Base_Conversion::hex2Dec(char* hexadecimal){
    return toDecimal(hexadecimal, 16);
}

int Base_Conversion::dec2Bin(int decimal){
    return decimalToInt(decimal, 2);
}

int Base_Conversion::bin2Dec(int binary){
    return toDecimal(binary, 2);
}

int Base_Conversion::dec2Oct(int decimal){
    return decimalToInt(decimal, 8);
}

int Base_Conversion::oct2Dec(int octal){
    return toDecimal(octal, 8);
}    

/** </PUBLIC> **/