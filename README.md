# Extern-Constexpr
A basic test to gain an understanding of the `extern` keyword's interactions (or lack of) with the `constexpr` keyword 

## TLDR
- A const variable can be intialised with constexpr
- A constexpr function can be forward declared but usage is not constexpr

Expected commands are:
- `cmake -B build -S .` from repo source dir
- `cmake --build build` from same dir
- `./build/constexpr_test || echo $?` or `build\Release\constexpr_test.exe || echo %ErrorLevel%`

Testing done on:
- gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
- msvc (Cl: 19.29.30159 for x64)

## Why is this of value?
- Old libs need to constexpr all the things too, however we don't want to remove functionality for people using previous versions of the language.
- We can add a config file and macros to make things only that can be constexpr in this C++ version and if not we can mark it as inline
- This produces two issues:
    + Lots of macros
    + We perhaps don't want to inline all the things (e.g. virtual functions)  

## Results/discussion/notes
- The ability of the constexpr function to be constexpr seems to be similar to that of the regular execution of a forward declared inline function
  + See [inline specifier](https://en.cppreference.com/w/cpp/language/inline)
  + [constexpr specifier](https://en.cppreference.com/w/cpp/language/constexpr) does not contain similar wordings
- It should be possible for the function to be executed at complie time if WPO is enabled since the expansion happens after AST generation
  + This is moot as code that only works with WPO on sounds terrible

