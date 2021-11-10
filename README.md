# PSU_my_printf_2019

This is a tiny printf implementation.
Absolutely **NO dependencies** are required, *printf.c* brings all necessary routines, even its own fast `ftoa` (floating point), `ntoa` (decimal) conversion.


## Usage

Usage is like the according stdio.h library version:
```C
int printf(const char* format, ...);
```

## Format Specifiers

A format specifier follows this prototype: `%[flags][width][.precision][length]type`
The following format specifiers are supported:


### Supported Types

| Type   | Output |
|--------|--------|
| d or i | Signed decimal integer |
| u      | Unsigned decimal integer	|
| o      | Unsigned octal |
| x      | Unsigned hexadecimal integer (lowercase) |
| X      | Unsigned hexadecimal integer (uppercase) |
| c      | Single character |
| s      | String of characters |
| p      | Pointer address |
| %      | A % followed by another % character will write a single % |


### Supported Flags

| Flags | Description |
|-------|-------------|
| (space) | If no sign is going to be written, a blank space is inserted before the value. |
| #     | Used with o, b, x or X specifiers the value is preceded with 0, 0b, 0x or 0X respectively for values different than zero.<br>Used with f, F it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |


