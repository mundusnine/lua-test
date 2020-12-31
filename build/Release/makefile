INC=-I./ -I../../Libraries/minilua 
LIB=-static-libgcc -static-libstdc++ -pthread
DEF=-DLUA_IMPL 

CFLAGS=-std=c99 
CPPFLAGS=
lua-test: main.o 
	g++ -o "lua-test"  -O2 main.o  $(LIB)

main.o: ../../Sources/main.c
	gcc  -O2 $(INC) $(DEF) $(CFLAGS) -c ../../Sources/main.c -o main.o
