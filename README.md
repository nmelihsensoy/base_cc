# Base Conversion Library
A simple library for convert number bases

## Installation
```
#include "base_conversion.h"
```

## Initialization
```
Base_Conversion *base;
```

## Usage

```
base->dec2Hex(78)   // '4e'
base->hex2Dec("4e") // 78
base->dec2Bin(10)   // 1010  
base->bin2Dec(1010) // 10
base->dec2Oct(235)  // 353
base->oct2Dec(353)  // 235
```

### How to convert any number base to decimal?
```
int b = base->toDecimal(3422, 5);  //487
int c = base->toDecimal("4e", 16); //78
int d = base->toDecimal("0x4e");   //78
```

### How to convert decimal number to any base?
```
char* e = base->decimalTo(78, 16);   //'4e'
int f = base->decimalToInt(487, 5);  //3422
```

### How to convert any base to desired base?
```
int g = base->base2Base(45, 13, 6);
```

### How to count digits of a number?
```
int a = base->countDigit(187567); //6
```

## Documentation

* **(_int_) countDigit(_int_ number)**  : Counts digits of a number
* **(_int_) toDecimal(_int_ number, _int_ base)**  : Converts any base to decimal
* **(_int_) toDecimal(_char*_ number, _int_ base)**  
* **(_char*_) decimalTo(_int_ number, _int_ base)**  : Converts decimal number to desired base
* **(_int_) decimalToInt(_int_ number, _int_ base)**  : Converts decimal number to desired base
* **(_int_) base2Base(_int_ number, _int_ number_base, _int_ desired_base)**  : Converts any base to desired base
* **(_char*_) dec2Hex(_int_ number)**  : Converts decimal to hexadecimal
* **(_int_) hex2Dec(_char*_ number)**  : Converts hexadecimal to decimal
* **(_int_) dec2Bin(_int_ number)**  : Converts decimal to binary
* **(_int_) bin2Dec(_int_ number)**  : Converts binary to decimal
* **(_int_) dec2Oct(_int_ number)**  : Converts binary octadecimal
* **(_int_) oct2Dec(_int_ number)**  : Converts octadecimal to decimal
