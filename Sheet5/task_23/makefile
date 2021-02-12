invoke:	invoke.c
	gcc -m32 invoke.c -o invoke

run: invoke
	./invoke

clean: invoke
	rm invoke

gdb:	invoke
	gdb ./invoke