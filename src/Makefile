

CXXFLAGS := -std=c++11 -Werror -Wall -Wpedantic -Wextra 
OBJECTS := Image.o image_drawing.o image_output.o PPM.o user_io.o controllers.o MenuData.o ActionData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
HEADERFILE := NumberGrid.h
LDFLAGS := -lpthread #add into link commands for executables for multithreading

all: hello questions_3 ascii_image image_file simple_squares_ascii hero ppm_menu 



hello: hello.o
	g++ $(CXXFLAGS) -o hello hello.o 

hello.o: hello.cpp
	g++ $(CXXFLAGS) -c -o hello.o hello.cpp 



questions_3: questions_3.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o questions_3 questions_3.o $(OBJECTS) $(LDFLAGS)

questions_3.o : questions_3.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o questions_3.o questions_3.cpp 



ascii_image : ascii_image.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o ascii_image ascii_image.o $(OBJECTS) $(LDFLAGS)

ascii_image.o : ascii_image.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o ascii_image.o ascii_image.cpp 

Image.o : Image.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o Image.o Image.cpp 

image_drawing.o : image_drawing.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_drawing.o image_drawing.cpp 

image_output.o : image_output.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_output.o image_output.cpp 



image_file : image_file.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o image_file image_file.o $(OBJECTS) $(LDFLAGS)

image_file.o : image_file.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o image_file.o image_file.cpp 

PPM.o : PPM.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o PPM.o PPM.cpp 




hero : hero.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o hero hero.o $(OBJECTS) $(LDFLAGS)

hero.o : hero.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o hero.o hero.cpp


simple_squares_ascii : simple_squares_ascii.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o simple_squares_ascii simple_squares_ascii.o $(OBJECTS) $(LDFLAGS)

simple_squares_ascii.o : simple_squares_ascii.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o simple_squares_ascii.o simple_squares_ascii.cpp

user_io.o : user_io.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o user_io.o user_io.cpp

controllers.o : controllers.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o controllers.o controllers.cpp 


ActionData.o : ActionData.cpp ActionData.h 
	g++ $(CXXFLAGS) -c -o $@ $<  

MenuData.o : MenuData.cpp MenuData.h 
	g++ $(CXXFLAGS) -c -o $@ $< 


ppm_menu : ppm_menu.o image_menu.h $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $< $(OBJECTS) $(LDFLAGS)

ppm_menu.o : ppm_menu.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o $@ $<


image_filters.o : image_filters.cpp image_menu.h 
	g++ $(CXXFLAGS) -c -o $@ $<

NumberGrid.o : NumberGrid.cpp NumberGrid.h 
	g++ $(CXXFLAGS) -c -o $@ $<

ColorTable.o : ColorTable.cpp ColorTable.h
	g++ $(CXXFLAGS) -c -o $@ $<

ComplexFractal.o : ComplexFractal.cpp ComplexFractal.h 
	g++ $(CXXFLAGS) -c -o $@ $<

JuliaSet.o : JuliaSet.cpp JuliaSet.h 
	g++ $(CXXFLAGS) -c -o $@ $<

MandelbrotSet.o : MandelbrotSet.cpp MandelbrotSet.h 
	g++ $(CXXFLAGS) -c -o $@ $<

ThreadedGrid.o : ThreadedGrid.cpp ThreadedGrid.h 
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f *.o *~
	-rm -f hello
	-rm -f questions_3
	-rm -f ascii_image 
	-rm -f image_file
	-rm -f hero 
	-rm -f simple_squares_ascii
	-rm -f ppm_menu 