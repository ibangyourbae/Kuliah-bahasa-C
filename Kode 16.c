#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct sayuran{
    char nama[10];
    char jenis[10];
    int banyak;
    char kualitas;
    int harga;
    int total;
    }iqbal[10],temp;

    int i,N;
    int totalsyr=0,cacahsyr=0;
    float rata;

    FILE *sayur;

void input_sayuran()
{
    printf("Masukkan Banyaknya Sayuran : ");
    scanf("%d",&N);
    printf("\n");
    printf("================================\n");
    printf("\tINPUT DATA SAYURAN\n");
    printf("================================\n");
    for(i=0; i<N; i++){
        fflush(stdin);
        printf("\nData Sayuran ke-%d\n",i+1);
        printf("Masukkan Nama Sayuran : ");
        gets(iqbal[i].nama);
        printf("Masukkan Jenis Sayuran : ");
        gets(iqbal[i].jenis);
        printf("Masukkan Banyak Sayuran : ");
        scanf("%d",&iqbal[i].banyak);
        fflush(stdin);
        printf("Masukkan Kualias Sayuran : ");
        scanf("%c",&iqbal[i].kualitas);
    }
}

void Hitung_harga()
{

    for(i=0; i<N; i++){

        if(strcmp(iqbal[i].jenis,"sayur")==0){
            if(iqbal[i].kualitas=='A' || iqbal[i].kualitas=='a'){
                iqbal[i].harga=1500;
            }
            else if(iqbal[i].kualitas=='B' || iqbal[i].kualitas=='b'){
                iqbal[i].harga=1200;
            }
            cacahsyr=cacahsyr+iqbal[i].banyak;

        }
        else if(strcmp(iqbal[i].jenis,"lain")==0){
            if(iqbal[i].kualitas=='A' || iqbal[i].kualitas=='b'){
                iqbal[i].harga=2500;
            }
            else if(iqbal[i].kualitas=='B' || iqbal[i].kualitas=='b'){
                iqbal[i].harga=3000;
            }
            else{
                iqbal[i].harga=500;
            }
            cacahsyr=cacahsyr+iqbal[i].banyak;
        }
        iqbal[i].total=iqbal[i].harga*iqbal[i].banyak;
        totalsyr=totalsyr+iqbal[i].total;
    }
    rata=(float)totalsyr/cacahsyr;
}

void tampilkan()
{
    for(i=0; i<N; i++){
        printf("\nData Sayuran ke-%d\n",i+1);
        printf("Nama Sayuran : %s\n",iqbal[i].nama);
        printf("Jenis Sayuran : %s\n",iqbal[i].jenis);
        printf("Banyak Sayuran : %d\n",iqbal[i].banyak);
        printf("Kualitas Sayuran : %c\n",iqbal[i].kualitas);
        printf("Harga Sayuran : %d\n",iqbal[i].harga);
        printf("Total Harga Sayuran : %d\n\n",iqbal[i].total);
    }
}

void bublesort()
{
    int pass;
    for(pass=1; pass<=N-1; pass++){
        for(i=1; i<=N-pass; i++){
            if(strcmp(iqbal[i-1].jenis,iqbal[i].jenis)>0){
                temp=iqbal[i];
                iqbal[i]=iqbal[i-1];
                iqbal[i-1]=temp;
            }
        }
    }
}

void nulis_file()
{
    sayur=fopen("data_sayuran.txt","w");
    for(i=0; i<N; i++){
        fwrite(&iqbal[i],sizeof(iqbal[i]),1,sayur);
    }
}

void baca_file()
{
    sayur=fopen("data_sayuran.txt","r");
    for(i=0; i<N; i++){
        fread(&iqbal[i],sizeof(iqbal[i]),1,sayur);
    }
}

void modifBubleSort()
{
    int i,pass,tukar;
    pass=1; tukar=1;

    while(pass<=N-1 && tukar==1){
        tukar=0;
        for(i=1; i<=N-pass; i++){
                //i-1 lalu i
            if(iqbal[i-1].kualitas>iqbal[i].kualitas){
                temp=iqbal[i];
                iqbal[i]=iqbal[i-1];
                iqbal[i-1]=temp;
                tukar=1;
            }
        }
        pass=pass+1;
    }
}

void mencacah_sayur()
{
    int totalsyr_A=0,cacahsyr_A=0;
    int totalsyr_B=0,cacahsyr_B=0;
    int totalsyr_lain=0,cacahsyr_lain=0;

    for(i=0; i<N; i++){
        if(iqbal[i].kualitas=='A' || iqbal[i].kualitas=='a'){
            cacahsyr_A=cacahsyr_A+iqbal[i].banyak;
            totalsyr_A=totalsyr_A+iqbal[i].total;
        }
        else if(iqbal[i].kualitas=='B' || iqbal[i].kualitas=='b'){
            cacahsyr_B=cacahsyr_B+iqbal[i].banyak;
            totalsyr_B=totalsyr_B+iqbal[i].total;
        }
        else{
            cacahsyr_lain=cacahsyr_lain+iqbal[i].banyak;
            totalsyr_lain=totalsyr_lain+iqbal[i].total;
        }

    }
    printf("=========================================");
    printf("\nBERDASRKAN KUALITAS A : \n");
    printf("Total Sayur : %d\n",totalsyr_A);
    printf("Cacah Sayur : %d\n",cacahsyr_A);
    printf("\nBERDASARKAN KUALITAS B : \n");
    printf("Total Sayur : %d\n",totalsyr_B);
    printf("Cacah Sayur : %d\n",cacahsyr_B);
    printf("\nBERDASARKAN KUALITAS SELAIN A DAN B : \n");
    printf("Total Sayur : %d\n",totalsyr_lain);
    printf("Cacah Sayur : %d\n",cacahsyr_lain);
    printf("=========================================");
}
int main()
{
    printf("Nama    : Muhammad iqbal\n");
    printf("NIM     : 1103194114\n");
    printf("Kelas   : TK-43-01\n\n");

    input_sayuran();
    Hitung_harga();
    printf("================================\n");
    printf("OUTPUT SAYURAN \n");
    printf("================================\n");
    tampilkan();
    printf("================================\n");
    printf("RATA SELURUH SAYURAN : %.2f\n",rata);
    printf("================================\n\n");
    bublesort();
    printf("================================\n");
    printf("BUBLE SORT BERDASARKAN JENIS SAYURAN \n");
    printf("================================\n");
    tampilkan();
    nulis_file();
    baca_file();
    printf("============================================================\n");
    printf("OUTPUT SAYURAN SETELAH MEMBACA FILE YANG SUDAH DIURUTKAN\n");
    printf("============================================================\n");
    tampilkan();
    modifBubleSort();
    printf("=============================================\n");
    printf("MODIFIE BUBLE SORT BERDASARKAN KUALITAS \n");
    printf("=============================================\n");
    tampilkan();
    mencacah_sayur();

return 0;
}

