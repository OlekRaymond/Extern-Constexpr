# Extern-Constexpr
A basic test to gain an understanding of the `extern` keyword's interactions (or lack of) with the `constexpr` keyword 

## TLDR
- A const variable can be intialised with constexpr
- A constexpr function can be forward declared but usage is not constexpr

Expected commands are:
- `cmake -B build -S .` from repo source dir
- `cmake --build build` from same dir
- `./build/constexpr_test || echo $?`

Testing done on:
- gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0

