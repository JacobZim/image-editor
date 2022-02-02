
all: hello questions_3 ascii_image


hello: hello.o
	g++ -std=c++11 -o hello hello.o

hello.o: hello.cpp
	g++ -std=c++11 -c -o hello.o hello.cpp 


questions_3: questions_3.o image_menu.h user_io.o controllers.o Image.o image_drawing.o image_output.o
	g++ -std=c++11 -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o

questions_3.o : questions_3.cpp image_menu.h 
	g++ -std=c++11 -c -o questions_3.o questions_3.cpp 


ascii_image : ascii_image.o image_menu.h Image.o image_drawing.o image_output.o controllers.o user_io.o
	g++ -std=c++11 -o ascii_image ascii_image.o Image.o image_drawing.o image_output.o controllers.o user_io.o

ascii_image.o : ascii_image.cpp image_menu.h
	g++ -std=c++11 -c -o ascii_image.o ascii_image.cpp 

Image.o : Image.cpp image_menu.h 
	g++ -std=c++11 -c -o Image.o Image.cpp 

image_drawing.o : image_drawing.cpp image_menu.h 
	g++ -std=c++11 -c -o image_drawing.o image_drawing.cpp 

image_output.o : image_output.cpp image_menu.h 
	g++ -std=c++11 -c -o image_output.o image_output.cpp 


user_io.o : user_io.cpp image_menu.h 
	g++ -std=c++11 -c -o user_io.o user_io.cpp

controllers.o : controllers.cpp image_menu.h 
	g++ -std=c++11 -c -o controllers.o controllers.cpp 







clean:
	-rm -f *.o *~
	-rm -f hello
	-rm -f questions_3
