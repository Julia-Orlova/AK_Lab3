build: lab3.o
	g++ -o command lab3.o

lab3.o:
	g++ -c lab3.cpp

clean:
	rm -f lab3.o command