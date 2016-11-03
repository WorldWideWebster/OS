all:prog hw1_2 b

HW1_Part1 : prog.o b
	gcc prog.c -o prog
	gcc b.c -o b
	
HW1_Part2 : HW1_Part2.o
	gcc hw1_2.c -o hw1_2

clean :
	rm prog.o hw1_2.o b.o