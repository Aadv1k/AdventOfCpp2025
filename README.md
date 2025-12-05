# Advent of C++ 2025

It's that time of the year again! The goal is to get through all the 12 days this time.

| Days | Part A | Part B |
| :---:  | :---: | :---: | 
| [Day 1](./solutions/day01.cpp) | ★ | ☆ |
| [Day 2](./solutions/day02.cpp) | ★ | ★ |
| [Day 3](./solutions/day03.cpp) | ★ | ★ |

> Note:
> ★ = completed the solution
> ☆ = had to get help


## Setup

```shell
make 
DYLD_LIBRARY_PATH=./bin/shared ./bin/main <day00> </path/to/input>
```

> I decided to over-engineer how each solution is loaded and built; essentially each solution is built as a `.so` file in `./bin/shared`, then main code uses `dlopen` to dynamically load and execute the function.

## Logs

### Day 2

I took a short break from AoC, slept on Day 2 and got it working eventually. Honestly, Day 2 was def easier than Day 1, the main lesson learnt here was using the appropriate type conversion functions, given the input. 

So I was reading the input into a string buffer, and then casting it to a `size_t` through `atoi(buffer)`, this worked for the sample, but undershot for the actual input. I then tried using `strtoul` and that OVERSHOT when I cast it to a `size_t`. Finally what worked was `std::stoul()`. It is truly a mystery where these functions are named so cryptically. Onto day 3!

### 


## Previous Attempts

- [AdventOfGo2023](https://github.com/Aadv1k/AdventOfGo2023)
- [AdventOfC2022](https://github.com/Aadv1k/AdventOfC2022)
- [AdventOfLua2021](https://github.com/Aadv1k/AdventOfLua2021)
