compiler_flags = -I "C:\\Program Files (x86)\\sfml\\include" -L "C:\\Program Files (x86)\\sfml\\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: main.o game.o board.o bubble.o pencil.o player.o menu.o
	g++ main.o game.o board.o bubble.o pencil.o player.o menu.o ${compiler_flags} -o game.exe && .\game.exe

clear:
	del *.o

main.o: main.cpp
	g++ main.cpp -c ${compiler_flags}

game.o: game/game.cpp game/game.hpp
	g++ game/game.cpp -c ${compiler_flags}

board.o: board/board.cpp board/board.hpp
	g++ board/board.cpp -c ${compiler_flags}

bubble.o: bubble/bubble.cpp bubble/bubble.hpp
	g++ bubble/bubble.cpp -c ${compiler_flags}

pencil.o: pencil/pencil.cpp pencil/pencil.hpp
	g++ pencil/pencil.cpp -c ${compiler_flags}

player.o: player/player.cpp player/player.hpp
	g++ player/player.cpp -c ${compiler_flags}

menu.o: menu/menu.cpp menu/menu.hpp
	g++ menu/menu.cpp -c ${compiler_flags}
