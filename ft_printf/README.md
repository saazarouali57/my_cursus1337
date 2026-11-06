*This project has been created as part of the 42 curriculum by mochoubi.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C (functions
that accept a variable number of arguments) and to write clean, well-structured and
extensible code.

The project produces a static library, `libftprintf.a`, that contains the function:

```c
int ft_printf(const char *format, ...);
```

It behaves like the original `printf()`: it writes the formatted text to the standard
output and returns the number of characters printed.

### Supported conversions (mandatory part)

| Conversion | Output |
|---|---|
| `%c` | A single character |
| `%s` | A string (prints `(null)` if the pointer is `NULL`) |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (prints `(nil)` for `NULL`) |
| `%d` | A signed decimal number (base 10) |
| `%i` | A signed integer (base 10) |
| `%u` | An unsigned decimal number (base 10) |
| `%x` | A number in hexadecimal, lowercase |
| `%X` | A number in hexadecimal, uppercase |
| `%%` | A percent sign |

Only the mandatory part is implemented. The bonus (flags `-0.# +` and field width)
is not part of this version.

### Project structure

```
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h          header: prototypes of ft_printf and its helpers
└── src/
    ├── ft_printf.c      main function: walks the format string, counts characters
    ├── ft_dispatch.c    chooses the right function for each conversion letter
    ├── ft_print_char.c  %c and %%
    ├── ft_print_str.c   %s
    ├── ft_print_nbr.c   %d, %i, %u
    ├── ft_print_base.c  number printing in any base, %x and %X
    └── ft_print_ptr.c   %p
```

## Instructions

### Compilation

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean, then all
```

The Makefile compiles with `cc -Wall -Wextra -Werror` and creates `libftprintf.a`
at the root of the repository with the `ar` command. Running `make` again without any
change does not relink anything.

### Usage

Write a program that includes the header:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s, you are %d years old (0x%x)\n", "Mo", 20, 255);
	ft_printf("%d characters were printed\n", count);
	return (0);
}
```

Compile it and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o test
./test
```

Expected output:

```
Hello Mo, you are 20 years old (0xff)
38 characters were printed
```

### Testing

The function is meant to be compared against the original `printf()`. The tests I used
call both functions with the same format and arguments, capture what each one writes
and compare the output and the return value. The cases include `INT_MIN`, `INT_MAX`,
`UINT_MAX`, `0`, negative values with `%x` and `%u`, `NULL` for `%s` and `%p`,
`%c` with the value `0`, consecutive `%%`, and mixed formats. The code was also checked
with `valgrind` and with the sanitizers (`-fsanitize=address,undefined`).

## Algorithm and data structure

### Overview

`ft_printf` is organised in three layers, each with a single responsibility:

1. **The main loop** (`ft_printf.c`) starts the argument list with `va_start`, walks
   the format string character by character, prints normal characters directly, and
   when it finds a `%` it reads the next character and sends it to the dispatcher.
   It adds up the value returned by every print function and returns the total.
2. **The dispatcher** (`ft_dispatch.c`) receives the conversion letter and the
   `va_list`. According to the letter, it reads the next argument with `va_arg` using
   the correct type and calls the matching print function.
3. **The print functions** (one small function per kind of output) write to the
   standard output with `write` and **always return the number of characters they
   printed**. This is the key design decision: because every function reports what
   it wrote, the total returned by `ft_printf` is simply the sum of these values, and
   no global counter or shared state is needed.

### Printing numbers in any base

The conversions `%d`, `%i`, `%u`, `%x`, `%X` and `%p` all do the same job with a
different base, so they share one function, `ft_print_base(n, base)`. The base is given
as a string of digits (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`),
so its length is the base and each digit is found by indexing the string.

The algorithm:

1. Find the largest power of the base that is not greater than `n`
   (`div = 1`, then `div *= base` while `div <= n / base`).
2. While `div > 0`: print the digit `base[n / div]`, then `n = n % div` and
   `div = div / base`.

Example for `255` in base 16: `div` becomes `16`; then `255 / 16 = 15` prints `f`,
`n` becomes `15`, `div` becomes `1`; then `15 / 1 = 15` prints `f`, and `div` becomes `0`.
The result is `ff`.

**Why this approach:**

- **No memory allocation.** The digits are printed from the most significant to the
  least significant one directly, so there is no buffer to reverse and no `malloc`
  (an `itoa`-style approach would need to allocate and free a string, with the risk of
  leaks and failed allocations). The project therefore cannot leak memory.
- **No recursion.** The loop uses a fixed amount of memory and does not depend on the
  number of digits.
- **No overflow.** The test `div <= n / base` is used instead of `div * base <= n`,
  because multiplying could overflow for very large values such as `ULONG_MAX`.
- **One function for every base.** Adding a new base (for example octal for `%o`) only
  needs a new digit string, which keeps the code extensible.

### Data structures

No data structure of my own is needed. The only structures involved are the `va_list`
used to walk through the arguments, and the constant digit strings used as alphabets.
This keeps the project simple, and it follows the subject, which asks not to
implement the buffer management of the original `printf()`: every character goes
straight to `write`.

### Limits

As with the original function, the behaviour is undefined when the format does not
match the arguments (for example a missing argument, or `%x` with a string).

## Resources

### References

- [Variadic functions in C (GeeksforGeeks)](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- `man stdarg`: `va_list`, `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 3 printf`: behaviour of the original function, used as the reference for the comparisons
- `man 2 write`: writing to a file descriptor and its return value
- `man ar`: creating a static library

### Use of AI

AI was used as a helper to understand more.

- **Understanding:** to explain the concepts, such as variadic functions (`va_list`,
  `va_start`, `va_arg`, `va_end`).
