#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int arc, char **ars)
{
	char buff[20];
	int i,k,l,m,ii,kk,d,dd;
	char **arr; 
	//char *strng;
	int pid;
	int *pidd;
	char **args;
	char *pp;
	//	int status;
	int maxl;
	char *eor;


	if (arc>2) exit(-2);
	if (arc<2) {
		printf("Too little arguments\n");
		exit(-2);
		}
	dd=0;
	//printf("Введите лимит процессов  ");
	//fgets(buff,20,stdin);
	k=strtol(ars[1], &eor, 10);
	if ((buff == eor)||(k<=0)) {
		printf("Неверный лимит. Введите положительное число.\n");
		exit(-2);
	}
	//if (fgets(buff,20,stdin)!=NULL) {
	//	printf("Неправильный ввод\n");
	//	exit(-2);
	//}
	//pp=strchr(buff,'\0');
		//printf("%c\n",buff);

	maxl=k;
	//	siginfo_t *infop;
	pidd=NULL;
	args = NULL;
	//args[0] = NULL;
	//if (args[0]==NULL) {

	//printf("MEM1\n");

	//printf("Memory error\n");
	//exit(-2);
	//}
	//args[1] = NULL;
	args=realloc(args,sizeof(void*)*2);
	args[0]=NULL;
	args[1]=NULL;	
	arr = (char**)malloc(sizeof(void*)*3);	
	arr[1]=NULL;
	i = 1;
	k=0;
	l=0;
	while (fgets (buff,20,stdin) != NULL) {
		//printf("OK1n\n");
		//printf("OK2:%s\n",buff);
		/*if (arr==NULL){
		  printf("MEM2\n");
		  printf ("Memory error\n");
		  exit(-2);
		  }*/
		k++;
		arr[i] = (char*)realloc(arr[i],(sizeof(char)*20*k));
		if (arr[i]==NULL) {
			printf("MEM3\n");
			printf("Memory error\n");
			exit(-2);
		}
		//printf("OK\n");
		//printf("!!!!!!!!!!!!!!%c!!!!!!!!!!!\n",*(buff+19));
		pp=strchr(buff,'\n');
		strcat(arr[i],buff);

		printf("%s\n",buff);
		//for (m=0; (buff[m]!='\n')&&(m<19); m++){printf("%i   %c\n",m,*(buff+m));}


		//printf("!1\n");

		if (pp!=NULL){
			//printf("!2\n");	


			arr=(char**)realloc(arr, (sizeof(void*)*(i+2)));
			if (arr==NULL) {
				printf("MEM4\n");
				printf("Memory error\n");

				exit(-2);
			}
			arr[i+1]=NULL;
			//printf("!!!!! l= %i\n",l);
			
			
			ii=i;
			printf("PLZ WAIT Zapuskayem programmu %s\n",arr[ii]);

			kk=k;
			i++;
			k=0;

			//ZAPUSK!!!!!!!!!!!!!!!!!!!!!!!!!!			
			l++;
			//printf("++l=%i\n",l);
			d=0;
			if (l>maxl){
				printf("Sorry, too many processes :( Plz, wait\n");
				while(l>maxl){
											
					pid=waitpid(-1,NULL,0);
					for (m=1; m<ii; m++){ 
						if ((pidd[m]!=0)&&(d>1)) {
							kill(pidd[m],9);
							l=l-1;
							pidd[m]=0;
						}

						if ((pid!=0)&&(pid==pidd[m])){
							pidd[m]=0;
							l=l-1;
						}
					}
					//printf("Proverka%i\n",l);


					/*for (m=1; m<ii; m++ ){
					  if (pidd[m]!=0)	{
					  waitpid(pidd[m],&status,WNOHANG);
					  if (WIFEXITED(status)||WIFSIGNALED(status)) {
					  l=l-1;
					  pidd[m]=0;
					  }
					  }
					  }*/
				}
				printf("You may proceed\n");
				

			}
			
			dd++;
			pid=fork();
			if (pid==-1)
				return -1;
			if (pid==0) {
				args[0]=(char*)realloc(args[0],sizeof(char)*20*kk);
				if (args[0]==NULL) exit(-2);
				strcpy(args[0],arr[ii]);
				pp=strchr(args[0],'\n');
				if (pp!=NULL) *pp='\0';
				pp=strchr(args[0],'\r');
				if (pp!=NULL) *pp='\0';

				
				
				d=0;
				while ((pp=strchr(args[d],' '))!=NULL) {
					d++;
					args=realloc(args, sizeof(void*)*(d+2));
					args[d]=NULL;
					args[d]=realloc(args[d],sizeof(char)*20*kk);
					*pp='\0';
					args[d]=(pp+1);
					args[d+1]=NULL;
				}
				
				d=0;

				//printf("%s\n",args[0]);
				execv(args[0],args);
				printf("EXEC не сработал\n");
				return -1;

			}
				pidd=(int*)realloc(pidd,sizeof(int)*(ii+2));
				pidd[ii]=pid;
				//printf("!!!%i\n",pidd[ii]);



						//printf("__%i\n",pidd[ii]);


			//waitid(P_ALL, 0, infop ,WEXITED|WNOHANG);
			sleep(1);	
			pid=waitpid(-1,NULL,WNOHANG);
			if (pid==-1) printf("Child error.");
			if (pid!=0) { 
				printf("There is zombie\n");
				for (m=1; m<=ii; m++){ 
					if (pid==pidd[m]){
						printf("Зануляем pid %i\n",pidd[m]);
						pidd[m]=0;
						l=l-1;
					}
					printf("%i_PID= %i\n", m, pidd[m]);
				}
			}
			if (pid==0) printf("No zombies\n");
			//printf("l=%i\n",l);
			printf("You may enter new filename for execution\n");
			/*for (m=1; m<ii; m++){
			  printf("%i\n", pidd[m]);
			  if (pidd[m]!=0)	{
			  waitpid(pidd[m],&status,WNOHANG);
			  if (WIFEXITED(status)||WIFSIGNALED(status)) {
			  l=l-1;
			  pidd[m]=0;
			  }
			  }
			  }*/



			
		}



	}










	//printf("%sENDofPORTION\n",buff);

	//while (l>0){
	//	waitpid(-1,&status,WNOHANG);
	//	if (WIFEXITED(status)||WIFSIGNALED(status)) l=l-1;
	//}
	for (m=1; m<=dd; m++){
		printf("%i\n", pidd[m]);
		if (pidd[m]!=0) kill (pidd[m],9);
	}


	printf("Zakonchil\n");

	return 0;
}


