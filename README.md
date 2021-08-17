# 42cursus - ft_printf

![](https://github.com/hanshazairi/42-ft_printf/workflows/norminette/badge.svg)
![](https://img.shields.io/tokei/lines/github/hanshazairi/42-ft_printf?style=plastic?color=blue)

## Project Information

### About

The purpose of this project is to learn about *variadic functions* by recoding `libc`'s [`printf`](https://man7.org/linux/man-pages/man3/printf.3.html).

### Mandatory

- Manage `diuxXcsp%` type conversions

### Bonus

- Manage `# +` flag conversions
- Manage `0-` flag & precision with width conversions

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`va_start, va_arg, va_end & va_copy`](https://man7.org/linux/man-pages/man3/stdarg.3.html)

## Compilation

1. Clone repo including [`libft`](../../../42-libft) submodule via `git clone --recursive https://github.com/hanshazairi/42-ft_printf.git`.
2. Compile files into `libftprintf.a` static library via `make -C 42-ft_printf`.
3. Link `libftprintf.a` to your own `file.c` via `gcc file.c -L42-ft_printf -lftprintf`.
