CC = g++
FLAGS =  -lncurses
PROGNAME = casse-briques
SOURCES = bille.cpp briques.cpp highScore.cpp joueur.cpp options.cpp platf.cpp tableauBriques.cpp test-piece.cpp window.cpp
VERSION = 'eval\ date\ +%d_%m_%Y'

DEFAULT_GOAL = $(PROGRAME)
all : $(PROGNAME)
$(PROGNAME): $(SOURCES:.cpp=.o)
	$(CC) $^ -o $@ $(FLAGS)
%.o : %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY : clean mrproper

clean :
	@rm $(SOURCES:.cpp=.o) -rvf
	@rm highScore.txt
mrproper : clean
	@rm $(PROGNAME) -rvf
