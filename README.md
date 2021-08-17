# 42cursus - ft_printf

![](https://github.com/hanshazairi/42-ft_printf/workflows/norminette/badge.svg)
![](https://img.shields.io/tokei/lines/github/hanshazairi/42-ft_printf?style=plastic?color=blue)

## Project Information

### About

The purpose of this project is to re-code `libc`'s [`printf`](https://man7.org/linux/man-pages/man3/printf.3.html).

### Mandatory

- Manage `diuxXcsp%` type conversions

### Bonus

- Manage `# +` flag conversions
- Manage `0-` flag & precision with width conversions

## Usage

1. Clone repo including [`libft`](../../../42-libft) submodule via `git clone --recursive https://github.com/hanshazairi/42-ft_printf.git`.
2. Change directory to repo.
3. Compile files into `libftprintf.a` static library via `make`.
4. Link `libftprintf.a` static library to your own `main.c` via `gcc main.c -L. -lftprintf`.
5. Run executable via `./a.out`.
