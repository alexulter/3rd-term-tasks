#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	//Variables
	int i,k;
	long int *time;
	FILE *fd;
	char buffer[20];

	char *retrn;
	char **arr;
	pid_t qq;	
	char *endofstring;
	
	int pid;
	char *args[2];
	char *pp;
	
	//args[0]=malloc(sizeof(char)*2);
	retrn=(char*)malloc(20*sizeof(char));
	if (retrn==NULL){
		printf("Memory error\n");
		exit(-2);
		}
	//Открыть файл
	fd=fopen("file.t","r");
	if (fd==NULL) {
		printf("ERROR:Cannot open file\n");
		exit(-2);
	}

	//прочитать строки
	//Загнать в массив имена

	arr = NULL;
	time = NULL;
	retrn=fgets(buffer,20,fd);

		//printf("[%s]\n",buffer);
		if (retrn == NULL) {
				
			printf("Error, wrong file\n");
			exit(-2);
		}
	
	for (i=0; retrn!=NULL; i++) {
		
		//Выделяем память под массив
		arr=(char**)realloc(arr, sizeof(void *) * (i + 1));
		time=(long int*)realloc(time, sizeof(void*)*(i+1));
		//time[i]=malloc(sizeof(long int));
	
		//printf("OK3\n");
		if ((arr==NULL)||(time==NULL)/*||(time[i]==NULL)*/) {
			printf("Memory error\n");
			exit(-2);
		}

		
		
		arr[i] = (char*)malloc(sizeof(char)*20);
		
		if (arr[i] == NULL) {
			printf("Memory error");
			exit(-2);
		}

		 
				
		
		time[i]=strtol(buffer,&endofstring,10);
		if ( (endofstring==buffer) || (endofstring[0]!=' ')||(time[i]<=0) ) {
			printf("Wrong file!\n");
			printf("%s\n", endofstring);
			exit (-1);
			}
				
		//printf ("Read time %li\n", time[i]);	
		//printf("[%s]\n", endofstring);
		strcpy(arr[i], endofstring + 1);
		k=i;

#if 0
		for (k=1; k<19; k++){
			printf("%i\n",k);
		
			arr[i][k - 1] = endofstring[k];
			printf("OK\n");	
		};
#endif
	
			
		printf("%li %s\n",time[i], arr[i]);
		printf("OK2\n");
		retrn=fgets(buffer,20,fd);
		
		//printf("[%s]\n",buffer);
		
		if (retrn == NULL) 
			printf("Error or and of file\n");
				
		
	}
	
	printf("Operations with array completed successfully\n");
//i=0;
//k=1;
//fork+exec
for (i=0; i<=k; i++){
	printf("Preparing for execution of program\n #%s for %li seconds\n",arr[i],time[i]);
pid=fork();
	if (pid==-1)
		return -1;
	if (pid==0) {
			printf("Preparing for execution 2\n");
	
		sleep (time[i]);
		args[0] = malloc(sizeof(char)*20);
		if (args[0]==NULL) {
			printf("Memory error\n");
			exit(-2);
			}
		args[1] = NULL;
	
	
	
	
		//strcpy(args[0],"./");
		strcpy(args[0],arr[i]);
		pp=strchr(args[0],'\n');
		if (pp!=NULL) *pp='\0';
		pp=strchr(args[0],'\r');
		if (pp!=NULL) *pp='\0';
				
		//execv(arr[i],argv);
		execv(args[0],args);
		printf("Error in execution of program, may be file not found\n");
		return -1;
		}
}

printf("Resident Evil is coming\n");
//Wait
i=0;
while (i<=k){
i++;
qq=waitpid(-1,NULL,0);
}
//for (i=0; i<k; i++)
//{
//	kill pid[i];
//}


	fclose(fd);
	return 0;
}


