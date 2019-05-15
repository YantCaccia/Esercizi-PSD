driver_sort.exe: utils.o array.o driver_sort.o
	gcc utils.o array.o driver_sort.o -o driver_sort.exe

driver_test.exe: driverTest.o array.o utils.o
	gcc driverTest.o array.o utils.o -o driver_test.exe

driver_ricerca.exe: utils.o array.o driver_ricerca.o
	gcc utils.o array.o driver_ricerca.o -o driver_ricerca.exe

driver_somma.exe: utils.o array.o driver_somma.o
	gcc utils.o array.o driver_somma.o -o driver_somma.exe

driver_sommaArray.exe: utils.o array.o driver_sommaArray.o
	gcc utils.o array.o driver_sommaArray.o -o driver_sommaArray.exe

driver_scalare.exe: utils.o array.o driver_scalare.o
	gcc utils.o array.o driver_scalare.o -o driver_scalare.exe

test_dyn_mem.exe: utils.o array.o test_dyn_mem.o
	gcc utils.o array.o test_dyn_mem.o -o test_dyn_mem.exe

testalloc.exe: utils.o array.o testalloc.o
	gcc utils.o array.o testalloc.o -o testalloc.exe

driver_struct.exe: utils.o array.o point.o driver_struct.o
	gcc utils.o array.o point.o driver_struct.o -o driver_struct.exe 

utils.o:
	gcc -c utils.c

array.o:
	gcc -c array.c

driver_sort.o:
	gcc -c driver_sort.c

driverTest.o:
	gcc -c driverTest.c

driver_ricerca.o:
	gcc -c driver_ricerca.c

driver_somma.o:
	gcc -c driver_somma.c

driver_sommaArray.o:
	gcc -c driver_sommaArray.c

driver_scalare.o:
	gcc -c driver_scalare.c

test_dyn_mem.o:
	gcc -c test_dyn_mem.c

testalloc.o:
	gcc -c testalloc.c

driver_struct.o:
	gcc -c driver_struct.c

point.o:
	gcc -c point.c

clean:
	rm *.o *.exe