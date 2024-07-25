TARGET=exe
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
ALLEGRO=-lallegro -lallegro_main -lallegro_audio -lallegro_dialog -lallegro_ttf -lallegro_image -lallegro_color -lallegro_memfile -lallegro_acodec -lallegro_primitives -lallegro_font
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(ALLEGRO)
LD=gcc
OBJS= alegro.o automato.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CCFLAGS)
	@rm *.o

alegro.o: alegro.c
	$(CC) -c $(CCFLAGS) alegro.c -o alegro.o

automato.o: automato.c
	@gcc automato.c -c -Wall 