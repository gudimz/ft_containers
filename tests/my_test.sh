#! /bin/zsh

clang++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 vector_test.cpp -o run && ./run
rm -rf ./run

clang++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 stack_test.cpp -o run && ./run
rm -rf ./run

clang++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 map_test.cpp -o run && ./run
rm -rf ./run

clang++ -Wall -Wextra -Werror -fsanitize=address -std=c++98 set_test.cpp -o run && ./run
rm -rf ./run


# leaks --atExit -- ./run