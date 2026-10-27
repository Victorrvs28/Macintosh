# Pish

pish is a small Python interpreter that transpiles to **bash** and **batch**.
Write your automation once and run it on Linux, macOS and Windows,
with no interpreter to install on the target machine.

> Status: early development. Developed for Linux first.

## Why not just use Python?

Python isn't installed by default on Windows or on some Unix-like systems.
Macintosh generates plain `.sh` / `.bat` scripts that already run everywhere.

## Example

    contador = 42

## Build

    cmake -B build && cmake --build build
    ./build/macintosh

## Roadmap

- [x] Lexer
- [ ] Parser (in progress: variable assignment)
- [ ] Bash transpiler
- [ ] Batch transpiler

## Credits

- [gustavo-devy](https://github.com/gustavo-devy): lexer
- [victorrvs28](https://github.com/victorrvs28): parser
