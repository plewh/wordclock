all: *.cpp
	clang++ -Wall -g *.cpp -o wclock -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
	ctags -R *
