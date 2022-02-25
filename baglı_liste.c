#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 


typedef struct topluluk{ 
int bilgi;
char mesaj[100];
struct topluluk *arka;
}BLISTE; 
 

BLISTE *ilk = NULL, *son=NULL; 
 

BLISTE *ara(int); 
BLISTE *sil(int); 
BLISTE *okuKlavye(); 
int listele(); 
int ekle(BLISTE *); 
void yazEkrana(BLISTE *); 
  
int main() {
  BLISTE *eklenecek,*ki;
  int bilgi,sonuc;  
  char secim;  
  while(1){
    puts("\nEkleme\nListeleme\nArama\nSilme\nCikis\nSeciminiz?");   
    secim=getch();
         
    switch(secim){   
         case 'e': eklenecek = okuKlavye();
		       if(eklenecek != NULL)
			         ekle(eklenecek); 
			    else     
				     puts("Ekleme icin bellek dolu\n");    
			     break;   
		 case  'l': sonuc = listele();
		          if(sonuc==-1) 
			       puts("Bos Liste !");
			      break;
	     case  'a': puts("Aranan:"); 
		           scanf("%d",&bilgi);
				   ki=ara(bilgi);
				   if(ki == NULL)
				        puts("Aranan bulunamadi");
				   else 
				        yazEkrana(ki);
						break;  
		case   's': puts("Silinecek:"); 
		          scanf("%d",&bilgi);
				  ki = sil(bilgi);
				  if(ki != NULL)  
				        puts("Silindi...");
				  else  
				        puts("Silinmek istenen yok...");
						break;
		case   'c': puts("Hoscakal!");    
		          exit(0);   
		default: puts("Yanlis Secim!!!\n"); 
    }
   }
  return 0; 
  }
 

int ekle(BLISTE *ki) {  
    if( ilk != NULL){
	    son->arka = ki;   
		son = ki;   
		son->arka = NULL;  
	}  else  {
	          ilk = ki;
			  son = ilk;
			  ilk->arka = NULL;  
			  }  
 return 0; 
} 


int listele() {  
BLISTE *p;  
p = ilk;
     if(p==NULL) 
	    return -1; 
while(p){  
yazEkrana(p);   
p = p->arka;  
}  
return 0;
} 
 

BLISTE *ara(int aranan) {  
BLISTE *p;  
p = ilk;  
   while(p){   
      if( p->bilgi == aranan) 
	    return p;
		p = p->arka;
    }   
return NULL;
} 
 
 
BLISTE *sil(int silinecek) {  
BLISTE *p,*bironceki;  
p = ilk;  
bironceki = NULL;  
  while(p){   
      if(silinecek == p->bilgi)    
	     break;   
		 bironceki = p;   
		 p = p->arka;  
   }
   if( p != NULL){ 
      if(bironceki == NULL){    
	     if( ilk == son ){ 
		    ilk = NULL;     
		    son = NULL;    
		 } else{ 
		        ilk = ilk->arka;
			}
	  } else{  
		     bironceki->arka = p->arka; 
				if(bironceki->arka == NULL)    
					 son = bironceki;   
			 }   
	    free(p);   
	  return p;  
	}  else {
	         return NULL;
			 }	
  } 
 
void yazEkrana(BLISTE *yazilacak) {  
      printf("bilgi:%d, mesaj:%s\n",yazilacak->bilgi,yazilacak->mesaj);
} 
 

BLISTE *okuKlavye() {  
   BLISTE *okunan;  
   okunan =(BLISTE*)malloc(sizeof(BLISTE));  
        if(okunan == NULL) 
		   return NULL; 
 
 puts("Bilgi giriniz:"); 
 scanf("%d",&(okunan->bilgi));  
 puts("Mesaj giriniz:");   
 scanf("%s",&okunan->mesaj); 
 return okunan; 
} 
 
