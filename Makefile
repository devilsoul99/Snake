all:main

main: main.o Body.o BonusTimer.o Ghost.o Money.o Notice.o Poison.o Portal.o SuperTimer.o Surprise.o Timer.o Wall.o
	g++ -o main main.o Body.o BonusTimer.o Ghost.o Money.o Notice.o Poison.o Portal.o SuperTimer.o Surprise.o Timer.o Wall.o -lncurses
main.o: main.cpp Body.h BonusTimer.h Ghost.h Money.h Notice.h Poison.h Portal.h SuperTimer.h Surprise.h Timer.h Wall.h
	g++ -c main.cpp -lncurses
Body.o: Body.cpp Body.h
	g++ -c Body.cpp -lncurses
BonusTimer.o: BonusTimer.cpp BonusTimer.h
	g++ -c BonusTimer.cpp -lncurses
Ghost.o: Ghost.cpp Ghost.h
	g++ -c Ghost.cpp -lncurses
Money.o: Money.cpp Money.h
	g++ -c Money.cpp -lncurses
Notice.o: Notice.cpp Notice.h
	g++ -c Notice.cpp -lncurses
Poison.o: Poison.cpp Poison.h
	g++ -c Poison.cpp -lncurses
Portal.o: Portal.cpp Portal.h
	g++ -c Portal.cpp -lncurses
SuperTimer.o: SuperTimer.cpp SuperTimer.h
	g++ -c SuperTimer.cpp -lncurses
Surprise.o: Surprise.cpp Surprise.h
	g++ -c Surprise.cpp -lncurses
Timer.o: Timer.cpp Timer.h
	g++ -c Timer.cpp -lncurses
Wall.o: Wall.cpp Wall.h
	g++ -c Wall.cpp -lncurses
clean:
	rm *.o
