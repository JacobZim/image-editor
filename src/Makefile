
all: hello

hello: hello.o
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c -o hello.o hello.cpp 

clean:
	-rm -f *.o *~
	-rm -f hello
