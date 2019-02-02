/*
 * Number base conversion class for cpp
 * 
 * Author: Nuri Melih Sensoy
 * File: "base_conversion.h"
*/

#include <iostream>
#include <stdlib.h>

class Base_Conversion{
    private:
        /*
         * Clone of a strlen function from string.h
        */
        int strlen(char* number);
        
        /*
         * Clone of a pow function from math.h
        */
        int pow(int x, unsigned int y);

        /*
         * Converts decimal number to desired base
         * First argument is decimal number and second is a desired base
         * 
         * Returns integer array and first element is a size of the array
         * convert_dec_to[0] = *(convert_dec_to+0) = Array size
        */
        int* convert_dec_to(int decimal, int base);

    public:
        /*
         * Counts digits of a number 
        */
        int countDigit(int number);

        /*
         * Converts any base numbers to decimal
         * First argument is a number and seconds is a number base
         * 
        */
        int toDecimal(int number, int base);
        int toDecimal(char* hex, int base);
        
        /*
         * Converts decimal number to desired base
         * First argument is a number and seconds is a desired base
         * 
         * Returns char array so it can be printed with std::cout directly
         * 
        */
        char* decimalTo(int decimal, int base);

        /*
         * Converts decimal number to desired base
         * First argument is a number and seconds is a desired base
         * 
         * Returns integer so suitable for arithmetic operations
         * 
        */
        int decimalToInt(int decimal, int base);
        
        /*
         * Converts any base to any base
         * First argument is a number, second is a number base, third is a desired base
         * 
         * Returns integer
         * 
        */
        int base2Base(int number, int base, int convert_base);    

        /*
         * Shortcuts for a most used bases
        */
        char* dec2Hex(int decimal);
        int hex2Dec(char* hexadecimal);
        int dec2Bin(int decimal);
        int bin2Dec(int binary); 
        int dec2Oct(int decimal);
        int oct2Dec(int octal);              
};