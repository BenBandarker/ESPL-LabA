
# all : main.o numbers.o encoder.o add.o
# 	gcc -m32 -g -Wall -o main main.o numbers.o encoder.o add.o

# main.o : main.c 
# 	gcc -m32 -g -Wall -c -o main.o main.c

# numbers.o : numbers.c 
# 	gcc -m32 -g -Wall -c -o numbers.o numbers.c

# encoder.o : encoder.c 
# 	gcc -m32 -g -Wall -c -o encoder.o encoder.c

# add.o : add.s 
# 	nasm -g -f elf -w+all -o add.o add.s

all :encoder.o
	gcc -m32 -g -Wall -o encoder encoder.o

encoder.o : encoder.c 
	gcc -m32 -g -Wall -c -o encoder.o encoder.c

.PHONY: clean

clean : 
	rm -f *.o encoder