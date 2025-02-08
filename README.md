# ssMultiPrint
Prints multiple values to the stream.


## Вывод списка значений в поток. 

Принимает произвольное число параметров и рекурсивно выводит их в указанный поток,
используя стандартный метод `print` потока. 

**ВАЖНО!** Для успешной сборки неодходимо, чтобы у компилятора была включена поддержка 
диалекта `C++17`. Для этого находим файл `platform.txt`, который обычно
лежит по пути `...packages/arduino/hardware/avr/1.8.6/`. В этом файле находим параметр
`compiler.cpp.flags=` и в списке его значений меняем установленное значение на 
`-std=gnu++17` (или `-std=c++17`). При этом надо понимать, что
при обновлении платформы этот параметр может быть изменен автоматически. Так что при 
появлении предупреждений компиляции вида `warning: 'if constexpr' only available with -std=c++1z or -std=gnu++1z`
необходимо проверить текущее значение этого параметра и при необходиости его изменить.

> Кроме того, понятно, что весь функционал стандартного `print` работать не будет.
Например, задать основание при выводе целых чисел или точность при выводе вещественных
возможности не будет. 


```cpp
template <typename T, typename ... Rest>
void ssMultiPrint(Print &p, T first, Rest ... rest);

template <typename ... Args>
void ssMultiPrintln(Print &p, Args ... args);
```

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, в который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|...|`...`|Произвольное число выводимых параметров|



## Вывод массива в поток

```cpp
template <typename T, typename ST>
void ssArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC);
void ssArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t base = DEC);
```
Вывод массива в поток (с последующим переводом строки).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, в который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|arr|`printable`|Массив выводимых значений|
|size|`integer`|Количество элементов в массиве|
|separator|`char`|Разделитель выводимых значений. **По умолчанию `" "` (пробел)**|
|base|`uint8_t`|Основание для вывода значений. **По умолчанию `DEC`** Возможные варианты `DEC`, `BIN`, `OCT`, `HEX`|


## Вывод шестнадцатиричного массива в поток

```cpp
template <typename T, typename ST>
void ssHexArrayPrint(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true);
void ssHexArrayPrintln(Print &p, T arr[], ST size, const char separator = ' ', const uint8_t use_prefix = true);
```
Вывод шестнадцатиричного массива в поток (с последующим переводом строки). 

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, в который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|arr|`integer`|Массив выводимых значений|
|size|`integer`|Количество элементов в массиве|
|separator|`char`|Разделитель выводимых значений. **По умолчанию `" "` (пробел)**|
|use_prefix|`uint8_t`|Выводить (`true`) или нет (`false`) префикс `0x` перед значениями. **По умолчанию `true`**|


## Вывод шестнадцатиричного значения в поток

```cpp
template <typename T>
void ssHexPrint(Print& p, T val, const uint8_t use_prefix = true);
void ssHexPrintln(Print& p, T val, const uint8_t use_prefix = true);
```
Вывод шестнадцатиричного значения (с последующим переводом строки).

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, в который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|val|`integer`|Выводимое значение|
|use_prefix|`uint8_t`|Выводить (`true`) или нет (`false`) префикс `0x` перед значением. **По умолчанию `true`**|



## Вывод значения с фиксированной точкой

```cpp
template <typename T>
void ssFixedPrint(Print &p, T val, T scale = 10);
void ssFixedPrintln(Print &p, T val, T scale = 10);
```
Выводит значение с фиксированной точкой (с последующим переводом строки). Положение точки задается 
параметром `scale`. Так, для того, чтобы вывести `-42.17` необходимо передать в качестве параметра 
`val` значение `-4217`, а `scale` установить в значение `100`. Для вывода `36.6`: `val = 366`, 
`scale = 10`.

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, в который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|val|`integer`|Выводимое значение, предварительно умноженное на величину `scale`|
|scale|`unsigned interger`|Масштабный коэффицинет, задающий положение фиксированной точки. **По умолчанию `10`**|


## Пример
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
}

void loop() {
}
```