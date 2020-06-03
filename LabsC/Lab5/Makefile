all: build
build: Lab5.c Stack.c
	gcc -Wall -O0 -g3 -DDEBUG -std=c89 Lab5.c Stack.c -o program.exe
	
run: program.exe
	./program.exe
	
clean: 
	rm -rf *.o program