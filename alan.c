#include<stdio.h>

void daire(float *r,float *ar,float *cev);

int main()

{

	float r,alan,cevre;

	printf("Yaricapi giriniz : ");

	scanf("%f",&r);

    daire(&r,&alan,&cevre);

	printf("Alan=%f dir,Cevre = %f dir",alan,cevre);

	return 0;

}

void daire(float *r,float *ar,float *cev){

	*ar=3.14* *r * *r;

	*cev=2*3.14 * *r;

}
