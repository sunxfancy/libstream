main : main.cpp stream.hpp
	clang++ -std=c++11 main.cpp -o main

.PHONY:
clean :
	-rm main
