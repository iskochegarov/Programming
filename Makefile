test: main.o strings.o 
    gcc -o test main.o strings.o 

main.o: main.c
    gcc -c main.c 

strings.o: strings.c
    gcc -c strings.c 

.PHONY: clean
clean:
    rm -f test *.o
