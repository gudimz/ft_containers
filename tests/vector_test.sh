#! /bin/zsh

clang++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 vector_test.cpp -o run && ./run

#leaks --atExit -- ./run

rm -rf ./run