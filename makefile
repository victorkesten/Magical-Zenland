all: 
	g++ -std=c++11 -g -fno-inline -fno-omit-frame-pointer -m32 main.cpp game.cpp parser.cpp player.cpp Room/room.cpp Room/gardens.cpp Room/headquarters.cpp Room/forest.cpp Room/traproom.cpp Room/victory.cpp Item/item.cpp Item/backpack.cpp Actor/actor.cpp -o game

