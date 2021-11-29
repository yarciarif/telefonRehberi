#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
typedef struct
{
    char isim[100];
    long int kod;
    long int numara;
} telephone;

int Secim;
int main()
{
    printf("\t\t\tTelefon Rehberi v1.0\n");
    printf("\t\t       **********************\n");
    printf("Islemler\n");
    printf("\n1.Kayit Ekleme");
    printf("\n2.Telefon Kayitlarini Listele");
    printf("\n3.Kaydi Duzenle");
    printf("\n4.Numara Ile Kayit bul");
    printf("\n5.Isim Ile Kayit Bul");
    printf("\n6.Kayit Sil");
    printf("\n0.Cikis\n");
    printf("Secim:");
    scanf("%d",&Secim);


    switch (Secim)
    {
    case 0:
        exit(0);
        break;
    case 1:
        //Kayýt Ekleme
        KayitEkleme();
        break;
    case 2:
        //Telefon Kayýtlarýný Listeleme
        KayitListele();
        break;
    case 3:
        //Kayýt Duzenleme
        KayitDuzenleme();
        break;
    case 4:
        //Numara Ýle Kayýt Bul
        KayitBul_Num();
        break;
    case 5:

        //Ýsim ile Kayýt Bul
        KayitBul_Isim();
        break;
    case 6:
        //Kayýt Sil
        KayitSil();

        break;
    default:
        printf("Hatali Secim");
        AnaMenuyeDon();
        break;
    }
    return 0;
}
void KayitSil()
{
    char secim;
    int kacinci=-1;
    long int kod;
    int bulundu=0;
    telephone BulunanKayit;
    FILE *fp;
    printf("Kod Giriniz:");
    scanf("%ld",&kod);

    fp=fopen("TelefonRehber.txt","r+");
    if (fp == NULL)
    {
        printf("Okuma Hatasi\n");
        AnaMenuyeDon();
    }
    while (fread(&BulunanKayit,sizeof(telephone),1,fp) == 1)
    {
        if (BulunanKayit.kod == kod)
        {
            bulundu=1;
            break;
        }
        else
            kacinci+=1;
    }
    if (bulundu == 1)
    {
        fseek(fp,(kacinci+1)*sizeof(telephone),SEEK_SET);
        strcpy(BulunanKayit.isim,"");
        BulunanKayit.kod=NULL;
        BulunanKayit.numara=NULL;
        fwrite(&BulunanKayit,sizeof(telephone),1,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
        printf("Kayit Bulunamadi!\nTekrar silme yapmak ister misiniz?(E/H)");
        scanf("%s",&secim);
        if (secim == 'E')
            KayitSil();
    }
    printf("Ana Menuye Donmek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if ((secim =='E') || (secim == 'e'))
        AnaMenuyeDon();
}
void KayitBul_Isim()
{
    char secim;
    char Aranacak_Isim[100];
    int bulundu;
    FILE *fp;
    telephone BulunanKayit;
    printf("Isim Giriniz:");
    scanf("%s",&Aranacak_Isim);
    fp=fopen("TelefonRehber.txt","r");
    if (fp == NULL)
    {
        printf("Dosya Acma Hatasi\n");
        AnaMenuyeDon();
    }

    while(fread(&BulunanKayit,sizeof(telephone),1,fp)==1)
    {
        if ((strncmp(BulunanKayit.isim,Aranacak_Isim)) == 0)
        {

            bulundu = 1;
            break;
        }
    }
    if (bulundu== 1)
    {
        fclose(fp);
        printf("Isim:%s\n",BulunanKayit.isim);
        printf("Kod:%ld\n",BulunanKayit.kod);
        printf("Numara:%ld\n",BulunanKayit.numara);
    }else
    {
        fclose(fp);
        printf("Kayit Bulunamadi!\nTekrar arama yapmak ister misiniz?(E/H)");
        scanf("%s",&secim);
        if ((secim == 'E') || (secim == 'e'))
            KayitBul_Num();
    }
    printf("Ana Menuye Donmek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if (secim =='E')
        AnaMenuyeDon();

}
void KayitBul_Num()
{
    char secim[100];
    long int Bulunan_Num;
    int bulundu;
    FILE *fp;
    telephone BulunanKayit;
    printf("Numara Giriniz:");
    scanf("%ld",&Bulunan_Num);

    fp=fopen("TelefonRehber.txt","r");
    if (fp == NULL)
    {
        printf("Dosya Acma Hatasi\n");
        AnaMenuyeDon();
    }

    while(fread(&BulunanKayit,sizeof(telephone),1,fp)==1)
    {
        if (BulunanKayit.numara == Bulunan_Num)
        {
            bulundu = 1;
             break;
        }
    }
    if (bulundu== 1)
    {
        fclose(fp);
        printf("Isim:%s\n",BulunanKayit.isim);
        printf("Kod:%ld\n",BulunanKayit.kod);
        printf("Numara:%ld\n",BulunanKayit.numara);
    }else
    {
        fclose(fp);
        printf("Kayit Bulunamadi!\nTekrar arama yapmak ister misiniz?(E/H)");
        scanf("%s",&secim);
        if ((secim == 'E') || (secim == 'e'))
            KayitBul_Num();
    }
    printf("Ana Menuye Donmek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if ((secim =='E') || (secim == 'e'))
        AnaMenuyeDon();
}
void KayitEkleme()
{
    char secim;
    int i;
    telephone Kayit;
    FILE *fp;
    fp=fopen("TelefonRehber.txt","a+");
    if (fp == NULL )
    {
        printf("Dosya Acma Hatasi");
    }
    printf("Isim Giriniz:");
    scanf("%s",&Kayit.isim);
    printf("Kod Giriniz:");
    scanf("%ld",&Kayit.kod);
    printf("Numara Giriniz:");
    scanf("%ld", &Kayit.numara);

    if (fwrite(&Kayit,sizeof(Kayit),1,fp)!=1)
    {
        printf("Yazma Hatasi!");
        exit(1);
    }
    fclose(fp);
    printf("Tekrar Kayit Eklemek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if ((secim =='E') || (secim == 'e'))
        KayitEkleme();
    AnaMenuyeDon();
}
void KayitDuzenleme()
{
    char secim;
    int kacinci=-1;
    char isim[100];
    int degisiklik=0;
    telephone BulunanKayit;
    FILE *fp;
    printf("Isim Giriniz:");
    scanf("%s",&isim);

    fp=fopen("TelefonRehber.txt","r+");
    if (fp == NULL)
    {
        printf("Okuma Hatasi\n");
        AnaMenuyeDon();
    }
    while (fread(&BulunanKayit,sizeof(telephone),1,fp) == 1)
    {
        if (strncmp(BulunanKayit.isim , isim)==0)
        {
            degisiklik=1;
            break;
        }
        else
            kacinci+=1;
    }
    if (degisiklik == 1)
    {
        fseek(fp,(kacinci+1)*sizeof(telephone),SEEK_SET);
        printf("Isim Giriniz:");
        scanf("%s",&BulunanKayit.isim);
        printf("Kod Giriniz:");
        scanf("%ld",&BulunanKayit.kod);
        printf("Numara Giriniz:");
        scanf("%ld",&BulunanKayit.numara);
        fwrite(&BulunanKayit,sizeof(telephone),1,fp);
    }
    else
    {
        printf("Kayit Bulunamadi!\nTekrar arama yapmak ister misiniz?(E/H)");
        scanf("%s",&secim);
        if (secim == 'E')
            KayitDuzenleme();
    }
    fclose(fp);
    printf("Ana Menuye Donmek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if ((secim =='E') || (secim == 'e'))
        AnaMenuyeDon();
}
void KayitListele()
{
    FILE *fp;
    telephone Kayit;
    char secim=' ';
    fp=fopen("TelefonRehber.txt","r");
    system("CLS");
    while(fread(&Kayit,sizeof(Kayit),1,fp)==1)
    {
        if ((Kayit.kod !=0 ) && (Kayit.numara!=0))
        {
            printf("Isim:%s\n",Kayit.isim);
            printf("Kod:%ld\n",Kayit.kod);
        printf("Numara:%ld\n",Kayit.numara);
        }
    }
    fclose(fp);
    printf("Ana Menuye Donmek Ister misiniz?(E/H):");
    scanf("%s",&secim);
    if ((secim =='E') || (secim == 'e'))
        AnaMenuyeDon();

}
void AnaMenuyeDon()
{
    int i;
    printf("Anamenuye donuluyor...\n");
    for (i=3; i>0; i--)
    {
        wait(1);
        printf("%d\n",i);
    }
    system("CLS");
    main();

}
void wait(int sure)
{
    clock_t son;
    son = clock() + sure * CLK_TCK;
    while (clock()<son) {};
}
