#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main (int argc, char **argv) {
	int i;
	FILE *fd1;
	FILE *fd2;
	char buff[20];
	struct stat buf;
	
	
	
	if (argv[1]==NULL){
		printf("argv[1]=NULL\n");
		exit(-2);
	}
	//fd1=fopen(argv[1],"r");
	
	//fcloce(fd1);
	/*while (read((int)fd1,(void*)buff, 1)!=-1){
		printf ("preprint\n");
		printf("print %s\n",buff);
	}*/
	
	if (stat(argv[1], &buf) == -1){
		printf("Can't access file\n");
		exit(-2);
	}
	printf("!!!\n");

	printf("%ld \n",buf.st_mode);
	
		//printf("%i\n",buf->st_ino);
	
	

	



	









return 0;
}

