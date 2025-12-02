# Advent of C++ 2025

It's that time of the year again! The goal is to get through all the 12 days this time.

| Days | Part A | Part B |
| :---:  | :---: | :---: | 
| [Day 1](./solutions/day01.cpp) | ★ | ☆ |

> ★ = completed the solution
> ☆ = had to get help

## Setup

```shell
make 
DYLD_LIBRARY_PATH=./bin/shared ./bin/main <day00> </path/to/input>
```

> I decided to over-engineer how each solution is loaded and built; essentially each solution is built as a `.so` file in `./bin/shared`, then main code uses `dlopen` to dynamically load and execute the function.

## Previous Attempts

- [AdventOfGo2023](https://github.com/Aadv1k/AdventOfGo2023)
- [AdventOfC2022](https://github.com/Aadv1k/AdventOfC2022)
- [AdventOfLua2021](https://github.com/Aadv1k/AdventOfLua2021)
