#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h> 
#include "unistd.h"


int main(void)
{
char* ch1, ch2;
int c,i,tim,k;
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
	} h[i];
printf("OK\n");
do
	{
	k++;
	fscanf (fp,"%i %s",&tim, &(h[k].ff)[0]);
	h[k].time=tim;

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

for (m=1;m<6;m++)
{
	for (j=0;j<10;j++)
		exe[j+2]=h[m].ff[j];
	printf("%s\n",exe);
	system(exe);
}

return 0;
}

