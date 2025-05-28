# ssMultiPrint
Prints multiple values to different output devices.


## Table of contents
* [Print a variable argument list](#Print-a-variable-argument-list)
* [Print an array of values](#Print-an-array-of-values)
* [Print a hexadecimal array with specific separator and prefix](#Print-a-hexadecimal-array-with-specific-separator-and-prefix)
* [Print a single hexadecimal value](#Print-a-single-hexadecimal-value)
* [Print a fixed point value](#Print-a-fixed-point-value)
* [Print a unicode symbol](#Print-a-unicode-symbol)
* [Calculate string length for integer value](#Calculate-string-length-for-integer-value)
* [Print an aligned integer value](#Print-an-aligned-integer-value)
* [Example](#Example)
* [History](#history)

## Print a variable argument list

```cpp
template <typename T, typename ... Rest>
void ssMultiPrint(Print &p, T first, Rest ... rest);

template <typename ... Args>
void ssMultiPrintln(Print &p, Args ... args);
```

Takes a variable argument list and prints them recursively using standard `print` function.


>*Note. You can use any printable values, but you cannot specify the output format. 
For example, You can call `ssMultiPrint(Serial, 255)` and get the results equal 
to `Serial.print(255)`. But You cannot get results equal to `Serial.print(255, HEX)`.*

See [Example](#Example).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` and `println` functions|
|...|`...`|The variable argument list|



## Print an array of values

```cpp
template <typename T, typename ST>
void ssArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC);
void ssArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC);
```

Prints an array of printable values with specific separator and base.

See [Example](#Example).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` and `println` functions|
|arr|`printable`|Array of printable values|
|size|`integer`|Number of elements in the array|
|separator|`char`|Elements separator. **Default: `" "` (space)**|
|base|`uint8_t`|The base. **Default: `DEC`**|


## Print an hexadecimal array with specific separator and prefix

```cpp
template <typename T, typename ST>
void ssHexArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true);
void ssHexArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true);
```

Print a hexadecimal array with specific separator and prefix.

See [Example](#Example).


|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` and `println` functions|
|arr|`integer`|Array to print|
|size|`integer`|Number of elements in the array|
|separator|`char`|Elements separator. **Default: `" "` (space)**|
|use_prefix|`uint8_t`|Whether to print (`true`) or not (`false`) the `0x` prefix before each element. **Default: `true`**|


## Print a single hexadecimal value

```cpp
template <typename T>
void ssHexPrint(Print& p, T val, const uint8_t use_prefix = true);
void ssHexPrintln(Print& p, T val, const uint8_t use_prefix = true);
```

Prints a single hexadecimal value

See [Example](#Example).


|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` and `println` functions|
|val|`integer`|Value to print|
|use_prefix|`uint8_t`|Whether to print (`true`) or not (`false`) the `0x` prefix before value. **Default: `true`**|


## Print a fixed point value

```cpp
template <typename T>
void ssFixedPrint(Print &p, T val, T scale = 10);
void ssFixedPrintln(Print &p, T val, T scale = 10);
```

Prints a fixed-point value. Use the `scale` parameter to specify the number of decimal 
places to use. For example, to print `-42.17`, use `val=-4217` and `scale=100`. 
To print `36.6`, use `val=366` and `scale=10`.

See [Example](#Example).


|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` and `println` functions|
|val|`integer`|Value to print multiplied by `scale`.|
|scale|`unsigned interger`|Parameter to specify the number of decimal places to use. **Default: `10`**|


## Print a unicode symbol

```cpp
void ssUnicodeCharPrint(Print &p, const uint32_t code);
```

Prints a Unicode character to a UTF-8 compatible stream. 
You can use 8, 16 or 32-bit symbol number. 
See [https://symbl.cc/](https://symbl.cc/) for unicode symbols and its numbers.

For example, to print the `Red Pushpin` symbol ("📌") use `128204 (0x1F4CC)` code. 

See [Example](#Example).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` function|
|code|`uint32_t`|The Unicode Number. See [https://symbl.cc/](https://symbl.cc/) for details|


## Calculate string length for integer value

```cpp
template <typename T>
uint8_t ssGetCharCount(T val, uint8_t radix);
```

Returns the size (in chars) of the string representing an integer value in selected radix.


See [Example](#Example).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` function|
|val|`integer`|The value to calculate the string representation of|
|radix|`uint8_t`|The base of the number system. Can be 10, 16, 8 or 2. **Default: `10`**|


## Print an aligned integer value

```cpp
template <typename T>
void ssAlignPrint(Print &p, T val, const uint8_t size, ssAlign align = ALIGN_RIGHT, char fill = ' ');
void ssAlignPrintln(Print &p, T val, const uint8_t size, ssAlign align = ALIGN_RIGHT, char fill = ' ');

```

Prints an aligned integer value with the specified block size.
* For left-aligned values, the right side of the block will be filled with the `fill` character.
* For right-aligned values, the left side of the block will be filled with the `fill` character.
* For center-aligned values, the left and right sides of the block will be filled with the `fill` character.

See [Example](#Example).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|The `Print` class for output. It must implement the `print` function|
|val|`integer`|The value to be printed|
|size|`uint8_t`|The size of the block (in chars)|
|align|`ssAlign`|The alignment. Can be `ALIGN_LEFT`, `ALIGN_RIGHT` or `ALIGN_CENTER`. **Default: `ALIGN_RIGHT`**|
|fill|`char`|The fill symbol. This symbol will be printed on the free space of the block. **Default: ` `(space)**|

## Example
```cpp
#include <ssMultiPrint.h>

uint8_t arr[] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  Serial.begin(9600);
  ssMultiPrintln(Serial, F("Some String and numbers: "), 10, ',', 42, " and more string"); // Some String and numbers: 10,42 and more string
  ssHexArrayPrintln(Serial, arr, 4, ':'); // 0xDE:0xAD:0xBE:0xEF
  ssHexArrayPrintln(Serial, arr, 4, ':', false); // DE:AD:BE:EF
  ssArrayPrintln(Serial, arr, 4); // 222 173 190 239
  ssFixedPrintln(Serial, -4288, 100); // -42.88
  ssFixedPrintln(Serial, 366); // 36.6
  ssUnicodeCharPrint(Serial, 0x1F4CC); // the red pushpin symbol "📌"
  Serial.println(ssGetCharCount(2147483648, 10)); // 10
  ssAlignPrintln(Serial, 42, 10); // "        42"
  ssAlignPrintln(Serial, 42, 10, ALIGN_LEFT); // "42        "
  ssAlignPrintln(Serial, 42, 10, ALIGN_CENTER); // "    42    "

}

void loop() {
}
```

## History

* 10.02.2025 - The First stable release
* 27.05.2025 - `ssUnicodeCharPrint` function added.
* 28.05.2025 - `ssGetCharCount`, `ssAlignPrint` functions added.