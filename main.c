
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    /*neheme die txt datei und lies daraus was drinn steht, 
    wenn eine Zeil zu ende ist dann get die next line. 
    
    zu erst müssen wir die zeile lesen und diese muss dann in buffersize zwischen gespeichertwerden,
    um dann den ganzen benöigten speicher zu alokieren. 

    wenn aber das file leer ist, muss eine error
    */
    
    // char *str = "hallo";
    char buffer[15];
    buffer[0] = 'c';

    // int fd = open("text.txt", O_RDONLY);
    // char *nextline = get_next_line(fd);
    // printf("line: %s", nextline);
    // printf("%li", sizeof(buffer));
    get_next_line(0);
    // close(fd); 
    return(0);



}