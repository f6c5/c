#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void zar();
int main()
{
	printf("bir tusa bas , cik 'q'...\n");
	while(getch()!='q'){
		zar();
	}
	printf("bitti.....\n");
	return 0;
}
void zar(){
	printf("atilan zar %d dir. bir daha at...\n",rand()%6+1);
	
}
