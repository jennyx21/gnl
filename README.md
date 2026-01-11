This project has been created as a part of the 42 curriculum by jtruckse.

Dscription:

get_next_line is a C function that reads and returns a single line from a file descriptor, no matter how long that line is. The project's 
main goal is to teach efficient file reading and dynamic memory management in C. Each call to get_next_line() returns the next line from 
the file, until the end of the file is reached.
this project helps you to get a deeper knowleg in: 

File operations in C
Static variables
Dynamic memory allocation and careful memory management
Edge cases like empty files, missing newlines, or very long lines

The implementation must be robust enough to handle different scenarios while avoiding memory leaks and ensuring optimal performance 
regardless of the chosen buffer size.


instructions 

to compile thid project you must run the following command with the usual Flags and your own main.c file:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

The Number of he BUFFER_SIZE can be changed. 


Resources

https://www.codequoi.com/en/malloc-allocating-memory-in-c/
https://www.codequoi.com/en/local-global-static-variables-in-c/
https://www.geeksforgeeks.org/c/memory-layout-of-c-program/
https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
https://github.com/mauricelorenz/get_next_line/blob/main/get_next_line.c
and Help by peers  <3

AI Usage

-Help with READ me structure
-Help with subtopics
	>e.g. memory Management 


Algorithm Explaination & Justification

core concept:
Uses a static array Buffer (static char buffer[BUFFER_SIZE + 1]) that keeps the value between funktion calls.
how it works: 
> check buffer for left over datat from previous read.
> If data is left in the Buffer, it handels the rest of it. 
> Read BUFFER_SIZE bytes form file into Buffer
>find new line 
		>Found -> extrackt the line, shift the remaining data to buffer start.
		>Not found -> append the data from buffer, clear the buffer and read more from file.
> Return: complete line or NULL at EOF


why this design?

static array: 
>No malloc/free for buffer itself 
>Simpler Memory management
>automatic lifetime handeling

read_line() funktion has 3 return values: 

1 = complete line found
2 = keep raeding
0 = EOF

