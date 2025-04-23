prog: main.o source.o serie.o
	gcc main.o source.o serie.o -o prog -lSDL -lSDL_ttf -lSDL_image -g

main.o: main.c
	gcc -c main.c -g

source.o: source.c
	gcc -c source.c -g

serie.o: serie.c serie.h
	gcc -c serie.c -g

clean:
	rm -f *.o prog
