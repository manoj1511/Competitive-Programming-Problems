CXX = g++
STD = c++11
FLAGS = -pedantic -Wall -Werror

all:		main main2

main:		main.cpp
		$(CXX) --std=$(STD) -o main.exe main.cpp $(FLAGS)

main2:		main2.cpp FindIndex.cpp FindIndex.h
		$(CXX) --std=$(STD) -o main_with_class.exe main2.cpp FindIndex.cpp $(FLAGS)

clean:
		rm -f *.exe
