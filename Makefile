program.out: projekt2.o merge.o quick.o TEST.o intro.o
	g++ projekt2.o merge.o quick.o TEST.o intro.o -o program.out

intro.o: intro.cpp header.h
	g++ -Wall -std=c++11 -c intro.cpp -o intro.o

TEST.o: TEST.cpp header.h
	g++ -Wall -std=c++11 -c TEST.cpp -o TEST.o

quick.o: quick.cpp header.h
	g++ -Wall -std=c++11 -c quick.cpp -o quick.o

merge.o: merge.cpp header.h
	g++ -Wall -std=c++11 -c merge.cpp -o merge.o

projekt2.o: projekt2.cpp header.h
	g++ -Wall -std=c++11 -c projekt2.cpp -o projekt2.o
