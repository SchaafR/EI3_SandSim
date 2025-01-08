
# Nom de l'exécutable final
EXEC = sand_sim

# Compilateur
CC = gcc

# Options pour pkg-config pour SDL2
PKG_CONFIG_FLAGS = $(shell pkg-config --cflags sdl2) -I/opt/homebrew/include -I/opt/homebrew/include/SDL2
PKG_LIBS = $(shell pkg-config --libs sdl2) -L/opt/homebrew/lib -lSDL2

# Options de compilation
CFLAGS = -Werror -Wall -D_THREAD_SAFE $(PKG_CONFIG_FLAGS)

# Options de liaison
LDFLAGS = $(PKG_LIBS)

# Liste des fichiers sources
SRCS = main_simuSand.c init_Matrix.c process.c window.c

# Générer les noms d'objets correspondants
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(EXEC)

# Règle pour l'exécutable
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) $(LDFLAGS)

# Règle pour les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers temporaires
clean:
	rm -f $(OBJS) $(EXEC)

re: clean all
	

# Nettoyer tout (objets et exécutable)
mrproper: clean
	rm -f $(EXEC)
