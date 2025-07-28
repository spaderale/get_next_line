![get_next_line](images/gnl.png)


Project developed for [42](https://www.42.fr/) with the goal of implementing a C function capable of reading one line at a time from a file descriptor (that is, a file or standard input like the keyboard). Here you'll find a function called `get_next_line` which can be called repeatedly, and on each call, returns the next complete line from the file until everything is read.

## Objective 🎯

The idea is to create an efficient and safe function, tackling the main challenges of C programming, such as:

- **File manipulation** using the low-level `read()` function;
- **Dynamic memory management** with `malloc` and `free`, ensuring no memory leaks or double frees;
- **Use of static variables** to keep state between function calls;
- **Support for multiple file descriptors** at the same time (in the bonus part);
- **Avoiding forbidden functions**: no `lseek()`, `printf()`, or your own `libft`;
- **Adaptability to BUFFER_SIZE**, which can be 1, 42, 10000, or any value, completely changing the reading logic.

Additionally, the function must behave correctly in cases such as:

- Very large files;
- Files that do not end with `\n`;
- Empty files;
- Standard input (stdin);
- And it must not read the whole file at once — it must read line by line.

## Why is this project important? 🤷‍♂️

42 uses get_next_line to make you truly understand how file reading works in C, with no high-level magic. Some fundamental points:

- **Training in dynamic memory management**: this concept will appear in almost every future project;
- **Modular thinking**: separating the main logic (`get_next_line.c`) from auxiliary functions (`get_next_line_utils.c`);
- **Handling errors and edge cases**: essential in any software project;
- **Concepts of buffers, static variables, flow control, and manual testing**.

For many students, this is the first "real" project at 42. You'll need to make complex technical decisions, think about code efficiency, and ensure nothing breaks. When you finish this project with everything working (including the bonus), your understanding of C will be far beyond just knowing how to use `printf` and `scanf`.

## Project Structure 📁

- `get_next_line.c`: main logic implementation.
- `get_next_line_utils.c`: auxiliary functions.

## How to compile 🔧

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## How to use 📌

Include the function in your project and call it like this:

```c
char *line;
int fd = open("file.txt", O_RDONLY);

while ((line = get_next_line(fd)) != NULL)
{
    // do something with the line
    free(line);
}
close(fd);
```

## Rules and Restrictions 🤖

- Do not use forbidden functions (`lseek`, `printf`, `libft`, etc).
- Must handle multiple file descriptors (bonus part).
- Must be efficient with different BUFFER_SIZE values.
- Must free all allocated memory correctly.

## Bonus 🛸

- Support for multiple file descriptors simultaneously.

## References

- [read function manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [open function manual](https://man7.org/linux/man-pages/man2/open.2.html)

---
Made by [spaderale](https://github.com/spaderale) ☕
---
