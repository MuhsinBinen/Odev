#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

	//Muhsin BÝNEN
	//02210224015

int main(){
	
	char dosya[100];
	FILE *file;
	printf("dosya adini giriniz:");
	gets(dosya);
	char dizi[100];
	char kelime[100];
	int i=0;
	
	if((file=fopen(dosya,"r"))==NULL){	//dosya açýlýþý kontrol ediliyor
		
		printf("Dosya okuma basarisiz");
		
	}
	else{
		printf("Dosya okuma basarili\n");//dosya baþarýlý bir þekilde açýldýysa
		while(!feof(file)){					//kaynak kodu dosyasý ekrana yazýlýyor 
			fscanf(file,"%c",&dizi[i]);
			printf("%c",dizi[i]);
			i++;
		}
		fclose(file);						//dosya kapatýldý
		int j=0;
		printf("\n");
		while(j<i){							//ayraçlar kaynak koddan ayrýlýyor
			if(dizi[j]!=(int)10){			//enter tuþu kontrol ediliyor
				kelime[j]=dizi[j];
				if(kelime[j]==(int)32||kelime[j]==(int)44||kelime[j]==(int)91||kelime[j]==(int)93){//diðer ayraçlar kontrol ediliyor
					kelime[j]=kelime[j+1];
				}
				else{
					printf("%c",kelime[j]);		//kelimeleþtirilmiþ hali ekrana ardýþýl bir þekilde yazýlýyor
				}	
			}
			else{
				dizi[j]=dizi[j+1];
			}
			j++;
		}	
	}	
}
