# Base Conversion Library
A simple library for convert number bases

## Installation
```cpp
#include "base_conversion.h"
```

## Initialization
```cpp
Base_Conversion *base;
```

## Usage

```cpp
int a = base->dec2Hex(78);   // '4e'
int a = base->hex2Dec("4e"); // 78
int a = base->dec2Bin(10);   // 1010  
int a = base->bin2Dec(1010); // 10
int a = base->dec2Oct(235);  // 353
int a = base->oct2Dec(353);  // 235
```

### How to convert any number base to decimal?
```cpp
int b = base->toDecimal(3422, 5);    //487
int c = base->toDecimal("4e", 16);   //78
int d = base->toDecimal("0x4e", 16); //78
```

### How to convert decimal number to any base?
```cpp
char* e = base->decimalTo(78, 16);   //'4e'
int f = base->decimalToInt(487, 5);  //3422
```

### How to convert any base to desired base?
```cpp
int g = base->base2Base(45, 13, 6); //133
```

### How to count digits of a number?
```cpp
int a = base->countDigit(487123456781); //12
```

## Documentation

* __(_int_) countDigit(_int_ number)__  : Counts digits of a number
* __(_int_) toDecimal(_int_ number, _int_ base)__  : Converts any base to decimal
* __(_int_) toDecimal(_char*_ number, _int_ base)__  
* __(_char*_) decimalTo(_int_ number, _int_ base)__  : Converts decimal number to desired base
* __(_int_) decimalToInt(_int_ number, _int_ base)__  : Converts decimal number to desired base
* __(_int_) base2Base(_int_ number, _int_ number_base, _int_ desired_base)__  : Converts any base to desired base
* __(_char*_) dec2Hex(_int_ number)__  : Converts decimal to hexadecimal
* __(_int_) hex2Dec(_char*_ number)__  : Converts hexadecimal to decimal
* __(_int_) dec2Bin(_int_ number)__  : Converts decimal to binary
* __(_int_) bin2Dec(_int_ number)__  : Converts binary to decimal
* __(_int_) dec2Oct(_int_ number)__  : Converts binary octadecimal
* __(_int_) oct2Dec(_int_ number)__  : Converts octadecimal to decimal
