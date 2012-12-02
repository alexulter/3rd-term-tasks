#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char buff[20];
	int i,k,l,m,ii,kk,d,maxd,flag;
	char **arr; 
	//char *strng;
	int pid;
	int *pidd;
	char *args[3];
	char *pp;
	//int status;
	int maxl;
	char *eos;





	printf("Введите лимит процессов\n");
		fgets(buff,20,stdin);
	kk=strtol(buff,&eos,10);
	if ((eos==buff)||(kk<=0)) {
		printf("Неверный лимит процессов\n");
		exit(-2);
	}
	/* maxl=kk;
	printf("Введите лимит ожидания\n");
	fgets(buff,20,stdin);
	kk=strtol(buff,&eos,10);
	if ((eos==buff)||(kk<0)) {
		printf("Неверный лимит Ожидания\n");
		exit(-2);
	}
	maxd=kk; */
	pidd=NULL;

	args[0] = NULL;
	//if (args[0]==NULL) {

	//printf("MEM1\n");

	//printf("Memory error\n");
	//exit(-2);
	//}
	args[1] = NULL;
	args[2] = NULL;

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
		d=0;
		//printf("OK\n");
		//printf("!!!!!!!!!!!!!!%c!!!!!!!!!!!\n",*(buff+19));
		pp=strchr(buff,'\n');
		strcat(arr[i],buff);

		//printf("%s\n",buff);
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
			//printf("Zapuskayem programmu %s\n",arr[i]);
			ii=i;
			kk=k;
			i++;
			k=0;

			//ZAPUSK!!!!!!!!!!!!!!!!!!!!!!!!!!			

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
				
				
				pp=strchr(args[0],' ');
				if (pp!=NULL) {
					*pp='\0';
					//args=realloc(args,sizeof(void*)*3);
					args[2]=NULL;
					args[1]=(pp+1);
					while(flag!=1){
						pp=strchr(args[1],' ');
						if (pp!=NULL) *pp='\0';
						else flag=1;
					}
					//*(pp+2)='\0';
				}

				//printf("%s\n",args[0]);
				execv(args[0],args);
				printf("EXEC не сработал\n");
				return -1;

			}



			pidd=(int*)realloc(pidd,sizeof(int)*(ii+1));
			pidd[ii]=pid;
			//printf("%i\n",pidd[ii]);


			//waitid(P_ALL, 0, infop ,WEXITED|WNOHANG);
			l++;
			pid=waitpid(-1,NULL,WNOHANG);
			for (m=1; m<ii; m++){ 
				if ((pid!=0)&&(pid==pidd[m])){
				//	printf("Зануляем %i\n",pidd[m]);
					pidd[m]=0;
					l=l-1;
				}
				//printf("PID%i\n",pidd[m]);
			}
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


			
			//printf("Proverka%i\n",l);
			if (l>maxl){
				printf("Sorry, too many processes :( Plz, wait\n");
				while(l>=maxl){
					//d++;	
					maxd=2;
					d=1;
					pid=waitpid(-1,NULL,WNOHANG);
					for (m=1; m<=ii; m++){
					
						//printf ("PID to kill %i d=%i\n", pidd[m],d);
						if ((pidd[m]!=0)&&(d>maxd)) {
							printf("Убиваем PID %i\n",pidd[m]);
							kill(pidd[m],9);
							l=l-1;
							pidd[m]=0;
						}
						if (l<maxl) m=ii+1;

						if ((pid!=0)&&(pid==pidd[m])){
							pidd[m]=0;
							l=l-1;
						}
					}
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

		}



	}










//printf("%sENDofPORTION\n",buff);

//while (l>0){
//	waitpid(-1,&status,WNOHANG);
//	if (WIFEXITED(status)||WIFSIGNALED(status)) l=l-1;
//}
for (m=1; m<ii; m++){
//printf("%i\n", pidd[m]);
	if (pidd[m]!=0) kill (pidd[m],9);
}


printf("Zakonchil\n");

return 0;
}


