# Libft
**My very first library in C, made for 42 School.**

This repository contains a collection of functions that replicate some of the standard C library functions as well as introduce additional utility functions. The library is primarily intended for use within the 42 School curriculum.

## Introduction
The **Libft** library provides a range of functions to perform various operations on strings, files, and linked lists. It serves as a foundational toolset for C programming, aiding in tasks such as memory manipulation, string processing, and data structure management. Some functions are optimized for performance, while others provide essential utilities.

## Usage
To use the **Libft** library, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the repository's root directory.
3. Run `make` to compile the library.

A compiled library named `libft.a` will be generated. You can link this library with your C programs to access the provided functions.

## Functions
### String Functions
- `ft_substr`: Allocates and returns a substring of a given string.
- `ft_strjoin`: Concatenates two strings and returns the result.
- `ft_strtrim`: Creates a new string by removing specified characters from the start and end.
- `ft_split`: Splits a string into an array of substrings using a delimiter.
- `ft_itoa`: Converts an integer into a string.
- `ft_strmapi`: Applies a function to each character of a string to create a new string.

### File Writing Functions
- `ft_putchar_fd`: Writes a character to a file descriptor.
- `ft_putstr_fd`: Writes a string to a file descriptor.
- `ft_putendl_fd`: Writes a string followed by a newline to a file descriptor.
- `ft_putnbr_fd`: Writes an integer to a file descriptor.

### Linked List Functions
- `ft_lstnew`: Creates a new list element.
- `ft_lstadd_front`: Adds an element to the beginning of a list.
- `ft_lstadd_back`: Adds an element to the end of a list.
- `ft_lstsize`: Counts the number of elements in a list.
- `ft_lstlast`: Retrieves the last element of a list.
- `ft_lstdelone`: Deletes a list element and applies a function to its content.
- `ft_lstclear`: Deletes all elements in a list, applying a function to each content.
- `ft_lstiter`: Iterates through a list and applies a function to each element.
- `ft_lstmap`: Creates a new list by applying a function to each element of an existing list.

## Additional Functions

- `get_next_line`: Reads a line from a file descriptor<sup>[[1]](https://github.com/vinicius507/get_next_line)</sup>.

## References

1. [Get Next Line](https://github.com/vinicius507/get_next_line).
