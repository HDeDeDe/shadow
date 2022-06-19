CWIN = g++ -fdiagnostics-color=always
COSX = g++-11 -fdiagnostics-color=always

WIN32compile:
	${CWIN} -g -std=c++17 \src\*.cpp