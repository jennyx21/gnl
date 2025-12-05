
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    /*
    neheme den input vom filedescriptor (fd) und lies daraus, bis zur buffer_size bzw. \n (newline), 
    bei \n (ende der zeile) dann wiederholt sich die get_line loop. 
    bei EOF (end of file) schliesst die loop ab und das programm endet.


    zu erst müssen wir die zeile lesen, das gelesene wird in buffer zwischen gespeichert,
    dann muss fuer die buffer_size (gelesene groesse) alloziert werden
    dann den kopierten string aus dem buffer entfernen und in dem neuen string speichern.

    wenn aber das file leer ist oder ein error passiert (malloc/calloc fail, read fail, etc) return NULL;


    */
    
    // char *str = "hallo";
    // char buffer[15];
    // buffer[0] = 'c';
	int i = 5;
    char *nextline;

    int fd = open("text.txt", O_RDONLY);
	while (i > 0)
	{
    nextline = get_next_line(fd);
    printf("line: %s\n", nextline);
	i--;
	}
    // close(fd); 
    // return(0);


    // int fd = open("test.txt", O_RDONLY);
    // char *line;

    // while ((line = get_next_line(fd)))
    // {
    //     printf("%s", line);
    // }
    // return 0;


}