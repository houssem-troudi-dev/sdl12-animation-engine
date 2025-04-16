prog: main.o menu.o
	gcc  main.o menu.o -o prog -lSDL -g -lSDL_image -lSDL_ttf -lSDL_mixer
menu.o:menu.c
	gcc -c menu.c -g
main.o:main.c
	gcc -c main.c -g

