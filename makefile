carlist.out : base.o main.o extra.o
	gcc -o carlist.out base.o main.o extra.o

base.o : base.c
	gcc -c -o base.o base.c

main.o : main.c
	gcc -c -o main.o main.c

extra.o : extra.c
	gcc -c -o extra.o extra.c

clean :
	rm carlist.out base.o main.o extra.o 
