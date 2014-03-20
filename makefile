all: main

main: main.o Sequence.o ExtractSequence.o
	g++ main.o Sequence.o ExtractSequence.o -o main

main.o: main.cpp
	g++ -c main.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

ExtractSequence.o: ExtractSequence.cpp
	g++ -c ExtractSequence.cpp

clean:
	rm -f *.o main
