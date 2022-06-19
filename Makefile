CWIN = g++ -fdiagnostics-color=always -g -std=c++17
COSX = g++-11 -fdiagnostics-color=always -g -std=c++17

WIN32compile:
	${CWIN} \src\*.cpp