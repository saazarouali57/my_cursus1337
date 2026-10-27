*This project has been created as part of the 42 curriculum by sazaroua.*

# Libft

## Description

**Libft** is the first library project of the 42 curriculum. The goal is to re-implement, in C, a set of standard library functions (`<string.h>`, `<ctype.h>`, `<stdlib.h>`, `<unistd.h>`) plus a collection of additional utility functions, and to package them into a static library (`libft.a`) that can be reused in all future 42 projects.

Writing these functions from scratch builds a rigorous understanding of memory management, pointers, string handling, linked lists, and the C standard's edge-case behavior, all under the constraints of the 42 Norm (no `for` loops, 25 lines per function, no global variables, etc.).

The library is split into three parts:

### Part 1: Libc functions

Re-implementations of standard functions, with the same prototypes and behavior (prefixed with `ft_`):

| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

### Part 2: Additional functions

Functions that are not in libc or that exist in a different form:

| Function | Description |
|----------|-------------|
| `ft_substr` | Returns a substring of a string, allocated with `malloc`. |
| `ft_strjoin` | Concatenates two strings into a new allocated string. |
| `ft_strtrim` | Trims a given set of characters from both ends of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter character. |
| `ft_itoa` | Converts an integer to an allocated string. |
| `ft_strmapi` | Applies a function to each character, returning a new string. |
| `ft_striteri` | Applies a function to each character (with its index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3: Linked list functions

Functions to manipulate singly linked lists using the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees a single node using a delete function. |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Builds a new list by applying a function to each node's content. |

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar`

### Compilation

From the root of the repository:

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

All files are compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header in your source file and link against the library:

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, 42!", 1);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

### Testing

The functions were tested with my own `main.c` files, covering normal cases and edge cases (empty strings, `NULL` pointers, `INT_MIN`, overlapping buffers, etc.).

## Resources

### References

- [`man` pages](https://man7.org/linux/man-pages/): `man 3 strlen`, `man 3 memmove`, etc., the reference for the expected behavior of each libc function
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), Kernighan & Ritchie
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [42 Norm](https://github.com/42School/norminette), official Norminette repository
- [cppreference: C standard library](https://en.cppreference.com/w/c)
- Hassan Bahi's linked list playlist, used to understand how linked lists work

### Use of AI

AI was used only to help me understand concepts (for example, how linked lists, `memmove`, and memory allocation work). I wrote all the code myself.
