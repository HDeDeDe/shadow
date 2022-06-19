CC = g++ -fdiagnostics-color=always

compile:
	${CC} -g -std=c++17 \src\*.cpp