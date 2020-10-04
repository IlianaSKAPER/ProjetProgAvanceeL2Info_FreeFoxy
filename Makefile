CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g 
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES =  constantes.h affichage_SDL.h -I./SDL2_ttf
EXEC = main
SRC = main.c affichage_SDL.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)
