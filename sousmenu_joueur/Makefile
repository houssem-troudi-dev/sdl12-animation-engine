prog: main.o sousmenu_joueur.o
	gcc  main.o sousmenu_joueur.o -o prog -lSDL -g -lSDL_image -lSDL_ttf -lSDL_mixer
menu.o:sousmenu_joueur.c
	gcc -c sousmenu_joueur.c -g
main.o:main.c
	gcc -c main.c -g

