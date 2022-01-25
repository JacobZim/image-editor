
all: hello questions_3

hello: hello.o
	g++ -std=c++11 -o hello hello.o

hello.o: hello.cpp
	g++ -std=c++11 -c -o hello.o hello.cpp 

questions_3: questions_3.o image_menu.h user_io.o controllers.o
	g++ -std=c++11 -o questions_3 questions_3.o user_io.o controllers.o

questions_3.o : questions_3.cpp image_menu.h 
	g++ -std=c++11 -c -o questions_3.o questions_3.cpp 

user_io.o : user_io.cpp image_menu.h 
	g++ -std=c++11 -c -o user_io.o user_io.cpp

controllers.o : controllers.cpp image_menu.h 
	g++ -std=c++11 -c -o controllers.o controllers.cpp 

clean:
	-rm -f *.o *~
	-rm -f hello
	-rm -f questions_3
