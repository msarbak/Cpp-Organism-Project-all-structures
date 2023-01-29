INC = -I ./include/ -o
OBJ = ./lib/Hucre.o ./lib/Radix.o ./lib/Doku.o ./lib/Array.o ./lib/Queue.o ./lib/Dugum.o ./lib/BST.o ./lib/Organ.o ./lib/Sistem.o ./lib/Organizma.o ./lib/Kontrol.o

All: derle bagla calistir

derle:
	g++ $(INC) ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ $(INC) ./lib/Doku.o -c ./src/Doku.cpp
	g++ $(INC) ./lib/Array.o -c ./src/Array.cpp
	g++ $(INC) ./lib/Queue.o -c ./src/Queue.cpp
	g++ $(INC) ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ $(INC) ./lib/BST.o -c ./src/BST.cpp
	g++ $(INC) ./lib/Radix.o -c ./src/Radix.cpp
	g++ $(INC) ./lib/Organ.o -c ./src/Organ.cpp
	g++ $(INC) ./lib/Sistem.o -c ./src/Sistem.cpp
	g++ $(INC) ./lib/Organizma.o -c ./src/Organizma.cpp
	g++ $(INC) ./lib/Kontrol.o -c ./src/Kontrol.cpp

bagla:	
	g++ $(INC) ./bin/Test $(OBJ) ./src/Test.cpp

calistir:
	./bin/Test
