int :	utils.o main.o list.o song-item.o playlist.o song.o
	gcc utils.o main.o song-item.o list.o playlist.o song.o -o driver.exe

list.o :
	gcc -c list.c
	
utils.o :
	gcc -c utils.c
	
main.o :
	gcc -c main.c
	
int-item.o:
	gcc -c int-item.c
	
string-item.o:
	gcc -c string-item.c

playlist.o:
	gcc -c playlist.c

song-item.o:
	gcc -c song-item.c

song.o:
	gcc -c song.c

clean: 
	rm -f utils.o main.o int-item.o string-item.o point-item.o point.o list.o playlist.o song-item.o song.o driver.exe