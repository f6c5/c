# include<stdio.h>
# include<stdlib.h>
# define MAX 10

int kuyruk[MAX];
int r = -1;
int f =-1;

int	ekle();
int sil();
int	oynat();
int main(){
    int sec;
    while(1){
        printf("1.ekle\n");
        printf("2.sil\n");
        printf("3.oynat\n");
        printf("4.cik\n");
        printf("secimini gir : ");
        scanf("%d",&sec);
        
        switch(sec){
            case 1 : ekle();
                break;
            case 2 : sil();
                break;
            case 3:  oynat();
                break;
            case 4:  exit(1);
            default: printf("\nhatali secim\n\n");
            	break;
        }
    }
}

ekle(){
    int ekle_item;
    if (r==MAX-1)
    	printf("\n kuyruk dolu \n \n");
    else{
        if (f==-1)
        	f=0;
		printf("eklemek istedigini yaz : ");
        scanf("%d", & ekle_item);
        r+=1;
        kuyruk[r] = ekle_item ;
        }
}

sil(){
    if (f == -1 || f > r){
    	printf("kuyruk bos\n");
    	return r ;
    }else{
        printf("kuyruktan silinen : %d\n", kuyruk[f]);
        f=f+1;
    }
}

oynat(){
    int i;
    if(f == -1)
    	printf("kuyruk bos\n");
    else{
        printf("kuyruktakiler :\n \n");
        for(i=f;i<= r;i++)
        printf("%d \n",kuyruk[i]);
        printf("\n");
    }
}

