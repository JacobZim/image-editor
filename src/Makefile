

CXXFLAGS := -std=c++11 -Werror -Wall -Wpedantic -Wextra

all: hello questions_3 ascii_image image_file



hello: hello.o
	g++ $(CXXFLAGS) -o hello hello.o

hello.o: hello.cpp
	g++ $(CXXFLAGS) -c -o hello.o hello.cpp 



questions_3: questions_3.o image_menu.h user_io.o controllers.o Image.o image_drawing.o PPM.o image_output.o
	g++ $(CXXFLAGS) -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o PPM.o image_output.o

questions_3.o : questions_3.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o questions_3.o questions_3.cpp 



ascii_image : ascii_image.o image_menu.h Image.o image_drawing.o image_output.o controllers.o user_io.o PPM.o 
	g++ $(CXXFLAGS) -o ascii_image ascii_image.o Image.o image_drawing.o image_output.o controllers.o user_io.o PPM.o 

ascii_image.o : ascii_image.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o ascii_image.o ascii_image.cpp 

Image.o : Image.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o Image.o Image.cpp 

image_drawing.o : image_drawing.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_drawing.o image_drawing.cpp 

image_output.o : image_output.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_output.o image_output.cpp 



image_file : image_file.o image_menu.h Image.o image_drawing.o image_output.o controllers.o user_io.o PPM.o 
	g++ $(CXXFLAGS) -o image_file image_file.o Image.o image_drawing.o image_output.o controllers.o user_io.o PPM.o 

image_file.o : image_file.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_file.o image_file.cpp 

PPM.o : PPM.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o PPM.o PPM.cpp 

image_file.o : image_file.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_file.o image_file.cpp 



user_io.o : user_io.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o user_io.o user_io.cpp

controllers.o : controllers.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o controllers.o controllers.cpp 







clean:
	-rm -f *.o *~
	-rm -f hello
	-rm -f questions_3
	-rm -f ascii_image 
	-rm -f image_file
