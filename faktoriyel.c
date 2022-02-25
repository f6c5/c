#include<stdio.h>
unsigned int fac(unsigned int i);
int main(){
	int i=6;
	printf("%d nin faktoriyeli %d",i,fac(i));
	
	
	return 0;
}
unsigned int fac(unsigned int i){
	if(i<=1){
		return 1;
	}
	return i* fac(i-1);
}
