INC=-I./ -I../../Libraries/minilua 
LIB=-static-libgcc -static-libstdc++ -pthread
DEF=-DLUA_IMPL 

CFLAGS=-std=c99 LDFLAGS=-Wl,--no-as-needed 
CPPFLAGS=
lua-test: main.o 
	g++ -o "lua-test"  -g main.o  $(LIB)

main.o: ../../Sources/main.c
	gcc  -g $(INC) $(DEF) $(CFLAGS) -c ../../Sources/main.c -o main.o
