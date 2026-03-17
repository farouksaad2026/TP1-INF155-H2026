CC = g++
CFLAGS = -Wall -Wextra

SRCS = main.cpp utilitaires.cpp winconsole.cpp grille_chiffres.cpp liste_couples.cpp affichages.cpp gestion_jeu.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = NumberMatch

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
