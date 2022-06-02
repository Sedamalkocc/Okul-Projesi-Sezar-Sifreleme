#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define limit 100

struct bilgi
    {
    	char ad[20];
        char soyad[30];
    	int no;
		char metin[limit];
		int parola;
	}kullanici;



void sifreleme(char[], int);
void sifreCozumleme(char[], int);
int bul(char[], char);
 

int alfabeBoyutu;

void dosyayayazdir()
{
	FILE *belge;
	belge=fopen("C:\\Users\\SEDA\\OneDrive\\Masaüstü\\sifrelimetin.txt","w+");
	if(belge == NULL)
	{
		printf("Belge bulunamadi.");
	}
	else
	{
	    fprintf(belge,"%s",kullanici.metin);
	}
	
	fclose(belge);
}

void dosyayiokuma()
{
	FILE *belge;
	belge = fopen("C:\\Users\\SEDA\\OneDrive\\Masaüstü\\sifrelimetin.txt","r+");
	if(belge == NULL)
	{
		printf("Belge bulunamadi.");
	}
	else
	{
		
		while (fscanf(belge,"%s",kullanici.metin) != EOF);
		printf("\nBelgedeki metin:\n%s",kullanici.metin);
	}
	fclose(belge);
}

 
int enbuyukasalcarpan(int a)
{
    int i =2 ,buyukasalcarpan = 2;
     
    while(a!=1)
    {
        if(a%i==0)
        {
            while(a%i==0)
            {
                a = a/i;
                 
                if(i>buyukasalcarpan)
                {
                    buyukasalcarpan = i;
                }
            }
        } 
         
        i++;
    }
     
    return buyukasalcarpan;
}
 
int main() {
    
    system("Color 0d");
    printf("\n\n*********************************************************************************************************************\n\n");
	printf("\t Kullanici Bilgisi\n\n");
	printf("Turkce karakter kullanmayin lutfen!!!!\n");

	printf("Isminizi giriniz: ");
	gets(kullanici.ad);
	
	printf("Soyadinizi giriniz: ");
	scanf("%s",&kullanici.soyad);
    
    strcat(kullanici.ad , kullanici.soyad);
    
    printf("Sifrelenecek metin : %s\n", kullanici.ad);
    
    strcat(kullanici.metin,kullanici.ad);
    
    printf("\nOgrenci numaranizi giriniz:");
    scanf("%d",&kullanici.no);
   
    char alfabe[] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int kaydir;
    alfabeBoyutu =strlen(alfabe);
 
    kaydir = kullanici.no %10;
    printf("\nKaydirilmak istenen harf miktari %d dir\n",kaydir);
    
    	sifreleme(alfabe, kaydir);
	
    
    dosyayayazdir();
    
    int buyukasalcarpan;
    
    yer:
    printf("\nParola olarak ogrenci numaranizin en buyuk asal carpanini giriniz:");
    scanf("%d",&kullanici.parola);
     
    if(kullanici.parola == enbuyukasalcarpan(kullanici.no))
    {
    
        
    	printf("\nParola onaylandi.Metnin sifre cozme islemi baslatiliyor...\n");
    	
    	dosyayiokuma();
	}
	else
	{
		printf("\nHatali parola girdiniz!!Lufen tekrar deneyiniz.\n");
		goto yer;
	}
   
    sifreCozumleme(alfabe, kaydir);
    printf("\n\n******metinin sifre cozulmus hali******\n%s\n",kullanici.metin);
    
    printf("\nOgrenci numaraniz:%d",kullanici.no);   
	
	printf("\n\n*********************************************************************************************************************\n\n");
 
    return 0;
}
 
void sifreleme(char alfabe[], int kaydir) {
    
    
    int i;
    int harfdizilisi;
    int metinBoyut = strlen(kullanici.metin);
    for (i = 0; i < metinBoyut; i++) {
        harfdizilisi = bul(alfabe, kullanici.metin[i]);
        if (harfdizilisi != -1) {
            harfdizilisi = (harfdizilisi + kaydir) % alfabeBoyutu;
            if (harfdizilisi < 0)
                harfdizilisi += alfabeBoyutu;
            kullanici.metin[i] = alfabe[harfdizilisi];
        }
    }
 
}
 
void sifreCozumleme(char alfabe[], int kaydir) {
    
    
    int i;
    int harfdizilisi;
    int metinBoyut = strlen(kullanici.metin);
    for (i = 0; i < metinBoyut; i++) {
        harfdizilisi = bul(alfabe, kullanici.metin[i]);
        if (harfdizilisi != -1) {
            harfdizilisi = (harfdizilisi - kaydir) % alfabeBoyutu;
            if (harfdizilisi < 0)
                harfdizilisi += alfabeBoyutu;
            kullanici.metin[i] = alfabe[harfdizilisi];
        }
    }
 
}
 
int bul(char alfabe[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < strlen(alfabe); i++) {
        if (arananHarf == alfabe[i])
            sayac = i;
    }
    return sayac;
}



