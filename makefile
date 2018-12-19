CC = g++
FLAGS =  -lncurses
PROGNAME = casse-briques
SOURCES = bille.cpp briques.cpp highScore.cpp joueur.cpp options.cpp platf.cpp tableauBriques.cpp test-piece.cpp window.cpp
VERSION = 'eval\ date\ +%d_%m_%Y'


all : $(PROGNAME)
$(PROGNAME): $(SOURCES:.cpp=.o)
	$(CC) $^ -o $@ $(FLAGS)
%.o : %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY : clean mrproper

clean :
	@rm $(SOURCES:.cpp=.o) -rvf
mrproper : clean
	@rm $(PROGNAME) -rvf
