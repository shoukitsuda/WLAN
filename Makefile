backtrack:input_data.o opt-TT.o
	gcc -o backtrack input_data.o opt-TT.o

opt-TT.o:opt-TT.c input_data.c
	gcc -c opt-TT.c

input_data.o:input_data.c
	gcc -c input_data.c