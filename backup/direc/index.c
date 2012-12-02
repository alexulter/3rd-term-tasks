#include <stdio.h>



int main (int argc, char **argv) {
	int i;
	FILE *fd1;
	FILE *fd2;
	char buff[20];

	if (argv[1]==NULL){
		printf("argv[1]=NULL\n");
		exit(-2);
	}
	fd1=fopen(argv[1],"r");
	printf("!!!!\n");
	fgets(buff, 20, fd1);
	
	

	



	








fclose(fd1);
return 0;
}

