# ssMultiPrint
Prints multiple values to the stream.


Вывод списка значений в поток. 
Принимает произвольное число параметров и рекурсивно выводит их в указанный поток,
используя стандартный метод `print` потока. 

**ВАЖНО!** Для успешной сборки неодходимо, чтобы у компилятора была включена поддержка 
диалекта `C++17`. Для этого находим файл `platform.txt`, который обычно
лежит по пути `...packages/arduino/hardware/avr/1.8.6/`. В этом файле находим параметр
`compiler.cpp.flags=` и в списке его значений меняем установленное значение на 
`-std=gnu++17` (или `-std=c++17`). При этом надо понимать, что
при обновлении платформы этот параметр может быть изменен автоматически. Так что при 
появлении ошибок компиляции вида `Compilation error: use of 'auto' in parameter declaration only available with -std=c++1z or -std=gnu++1z`
необходимо проверить текущее значение этого параметра и при необходиости его изменить.

> Кроме того, понятно, что весь функционал стандартного `print` работать не будет.
Например, задать основание при выводе целых чисел или точность при выводе вещественных
возможности не будет. 


```cpp
template <typename T, typename ... Rest>
void ssMultiPrint(Print &p, T first, Rest ... rest);
```

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, с который будет производиться вывод. Должен реализовывать метод `print`.|
|...|`...`|Произвольное число выводимых параметров|


```cpp
template <typename ... Args>
void ssMultiPrintln(Print &p, Args ... args);
```

|Prarm|Type|Description|
|:---:|:---|:---|
|p|`Print`|Поток, с который будет производиться вывод. Должен реализовывать методы `print` и `println`.|
|...|`...`|Произвольное число выводимых параметров|


```cpp
#include <ssMultiPrint.h>

void setup() {
  Serial.begin(9600);
  ssMultiPrintln(Serial, F("Some String and numbers: "), 10, 42, " and more string");
}

void loop() {
}
```