backtrack: input_data.o opt-TT.o
	gcc -o backtrack main.o sub.o
input_data.o:    input_data.c
	gcc -c input_data.c
opt-TT.o:     opt-TT.c
	gcc -c opt-TT.c