
prog: main.o charather1.o
	gcc main.o charather1.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g


main.o: main.c charather1.h
	gcc -c main.c -g


charathere1.o: charather1.c charather1.h
	gcc -c charathere1.c -g


clean:
	rm -f *.o prog

