all:HW2_prog1 HW2_prog2

HW2_prog1 : HW2_prog1.o 
	g++ HW2_prog1.cpp -o HW2_prog1 -pthread 
	
HW2_prog2 : HW2_prog2.o
	g++ HW2_prog2.cpp -o HW2_prog2 -pthread 

clean :
	rm HW2_prog1.o HW2_prog2.o