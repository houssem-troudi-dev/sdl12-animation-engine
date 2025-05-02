
prog: main.o charather3.o
	gcc main.o charather3.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g


main.o: main.c charather3.h
	gcc -c main.c -g


charathere1.o: charather3.c charather3.h
	gcc -c charathere1.c -g


clean:
	rm -f *.o prog

