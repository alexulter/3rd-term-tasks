#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h> 
#include "unistd.h"



int main(void)
{
char* ch1, ch2;
int c,i,tim,k,nachalo,p,l;
FILE*fp;
fp=fopen("file.t","r");
i=0;
 while (c!=-1)
	{
	c = getc (fp);
	if ((c == '\n')||(c==-1)) ++i;
	}


fclose(fp);
fp=fopen("file.t","r");


k=0; 
c=10;
struct Item 
	{
	int time;
	char ff[10];
	} z[i], h[i];
printf("OK\n");
do
	{
	
	fscanf (fp,"%i %s",&tim, &(h[k].ff)[0]);
	h[k].time=tim;
	k++;
//	printf("%d\n", h[k].time);
//	printf("%s\n", h[k].ff);
	
	}
while (k!=i);
fclose(fp);
printf("OK\n");
char exe[12];
int j=0,m=0,m1=0;
exe[0]='.';
exe[1]='/';
//Sorting
for (j=0; j<i;j++)
	{
	z[j].time=0;
	};
j=0;
m=0;
for (j=i-1; j>=0;j--)
 	{
	
	
 	for (m=0; m<i; m++)
		if (h[m].time>z[j].time) 
			{
			z[j].time=h[m].time;
			printf("%i %i",z[j].time,h[m].time);
			l=m;
			};
		
	h[l].time=0;
	for (p=0; p<10; p++) z[j].ff[p]=h[l].ff[p];	
 	};

//Running programs
j=0;
m=0;
k=0;
for (m=0;m<i;m++)
{
	for (j=0;j<10;j++)
	exe[j+2]=z[m].ff[j];
	printf("%s\n",exe);
	sleep(z[m].time-k*z[m-k].time);
	system(exe);
	printf("\n");
	k=1;
	
}




return 0;
}

