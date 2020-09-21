SOURCES := GfloatArithmetic.cpp Gfloat.cpp Garray.cpp  main.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


all:comp run
comp:$(OBJECTS)
	@clear 
	@g++ $(OBJECTS) -o smd -std=c++11

GfloatArithmetic.o:
	@g++ -c GfloatArithmetic.cpp -o GfloatArithmetic.o -std=c++11

Garray.o:
	@g++ -c Garray.cpp -o Garray.o -std=c++11

Gfloat.o:
	@g++ -c Gfloat.cpp -o Gfloat.o -std=c++11

main.o:
	@g++ -c main.cpp -o main.o -std=c++11

GfloatArithmetic.dep:
	@g++ -c -MM GfloatArithmetic.cpp \ 
	 	 -MT "GfloatArithmetic.dep GfloatArithmetic.o" \
		 -o GfloatArithmetic.dep -std=c++11	

Gfloat.dep:
	@g++ -c -MM Gfloat.cpp -MT "Gfloat.dep Gfloat.o" \
		 -o Gfloat.dep  -std=c++11

Garray.dep:
	@g++ -c -MM Garray.cpp -MT "Garray.dep Gfloat.o" \
		 -o Gfloat.dep -std=c++11

main.dep:
	@g++ -c -MM main.cpp -MT "main.dep main.o" -o main.dep -std=c++11

-include GfloatArithmetic.dep Gfloat.dep main.dep Garray.dep 
 
run:
	@./smd
	@ctags -R .
clean:
	rm smd *.o *.dep tags
