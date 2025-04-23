prog: main.o source.o
	gcc main.o source.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

source.o: source.c header.h  # Add all headers source.c includes
	gcc -c source.c -g

main.o: main.c header.h      # Add all headers main.c includes
	gcc -c main.c -g

clean:
	rm -f *.o prog