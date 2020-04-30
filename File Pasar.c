#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Dagangan{
    int kode;
    char nama[10];
    char jenis[10];
    int jmlbeli;
    int hargabeli;
    int sisa;
    int untung;
} Brg[100],temp;

struct Transaksi{
    char tanggal[10];
    int kode;
    int jumlah;
    int harga;
    int potongan;
} Tsksi[100];

struct Laporan{
    int untung_sayur;
    int untung_pokok;
    int untung_tambahan;
    int untung_total;
} Lapor;


int i,N,j,M;

FILE *barang;
FILE *transaksi;
FILE *lapor;

void isibarang()
{
    printf("\nINPUT DATA DAGANGAN\n\n");
    for(i=0; i<N; i++){
        printf("DATA DAGANGAN KE-%d\n",i+1);
        printf("Masukkan Kode : ");
        scanf("%d",&Brg[i].kode);
        printf("Masukkan Nama : ");
        fflush(stdin);
        gets(Brg[i].nama);
        printf("Masukkan Jenis Barang : ");
        gets(Brg[i].jenis);
        printf("Masukkan Jumlah Barang : ");
        scanf("%d",&Brg[i].jmlbeli);
        printf("Masukkan Harga Beli : ");
        scanf("%d",&Brg[i].hargabeli);
        printf("\n");
    }
}

void isijual()
{
    printf("\nINPUT DATA TRANSAKSI\n\n");
    for(j=0; j<M; j++){
        printf("DATA TRANSAKSI KE-%d\n",j+1);
        fflush(stdin);
        printf("Masukkan Tanggal Transaksi : ");
        gets(Tsksi[j].tanggal);
        printf("Masukkan Kode Transaksi : ");
        scanf("%d",&Tsksi[j].kode);
        printf("Masukkan Jumlah Transaksi : ");
        scanf("%d",&Tsksi[j].jumlah);
        printf("Masukkan Harga Transaksi : ");
        scanf("%d",&Tsksi[j].harga);
        printf("Masukkan Diskon Transaksi : ");
        scanf("%d",&Tsksi[j].potongan);
        printf("\n");
    }
}

void tampilkan()
{
    printf("DATA DAGANGAN\n");
    for(i=0; i<N; i++){
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n",Brg[i].kode,Brg[i].nama,Brg[i].jenis,Brg[i].jmlbeli,Brg[i].hargabeli,Brg[i].sisa,Brg[i].untung);
    }
}

void sisabarang()
{
    barang=fopen("Barang.txt","w");
    printf("\nMenghitung data Sisa dan Untung dari array trans\n");
    for(i=0; i<N; i++){
        Brg[i].sisa=Brg[i].jmlbeli;
        Brg[i].untung=0;
        printf("Kelompok Barang : %d %s\n",Brg[i].kode,Brg[i].nama);
        for(j=0; j<M; j++){
            if(Brg[i].kode==Tsksi[j].kode){
                    int untung,harga_asli;
                harga_asli=Tsksi[j].harga*(100-Tsksi[j].potongan)/100;
                Brg[i].sisa=Brg[i].sisa-Tsksi[j].jumlah;
                untung=(harga_asli-Brg[i].hargabeli)*Tsksi[j].jumlah;
                Brg[i].untung=Brg[i].untung+untung;
                printf("Tanggal %s harga asli %d sisa %d jml_untung %d\n",Tsksi[j].tanggal,Tsksi[j].harga*(100-Tsksi[j].potongan)/100,Brg[i].sisa,Brg[i].untung);

            }
        }
        // UNTUK MENYIMPAN SISA DAN UNTUNG KE ARRAY BARANG
        fwrite(&Brg[i],sizeof(Brg[i]),1,barang);
        printf("\n");
    }
    fclose(barang);
    tampilkan();
}

void Buatarray()
{
    // MENYIMPAN ARRAY KE FILE BARANG
    barang=fopen("Barang.txt","w");

    for(i=0; i<N; i++){
        fwrite(&Brg[i],sizeof(Brg[i]),1,barang);
    }
    fclose(barang);
    // MEMBACA ARRAY DARI FILE BARANG
    barang=fopen("Barang.txt","r");
    for(i=0; i<N; i++){
        fread(&Brg[i],sizeof(Brg[i]),1,barang);
    }
    fclose(barang);
    // MENYIMPAN ARRAY KE FILE JUAL
    transaksi=fopen("Jual.txt","w");
    for(j=0; j<M; j++){
        fwrite(&Tsksi[j],sizeof(Tsksi[j]),1,transaksi);
    }
    fclose(transaksi);
    // MEMBACA ARRAY DARI FILE JUAL
    transaksi=fopen("Jual.txt","r");
    for(j=0; j<M; j++){
        fread(&Tsksi[j],sizeof(Tsksi[j]),1,transaksi);
    }
    fclose(transaksi);

    // MENAMPILKAN OUTPUT SEMUA ARRAY
    printf("DATA DAGANGAN\n");
    for(i=0; i<N; i++){
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n",Brg[i].kode,Brg[i].nama,Brg[i].jenis,Brg[i].jmlbeli,Brg[i].hargabeli,0,0);
    }
    printf("\nDATA TRANSAKSI\n");
    for(j=0; j<M; j++){
        printf("%s\t%d\t%d\t%d\t%d\n",Tsksi[j].tanggal,Tsksi[j].kode,Tsksi[j].jumlah,Tsksi[j].harga,Tsksi[j].potongan);
    }
}

void selection_sort()
{
    int pass,Imax;
    for(pass=1; pass<=N; pass++){
        Imax=0;
        for(i=1; i<=N-pass; i++){
            if(strcmp(Brg[Imax].jenis,Brg[i].jenis)<0){
                Imax=i;
            }
            temp=Brg[Imax];
            Brg[Imax]=Brg[N-pass];
            Brg[N-pass]=temp;
        }
    }
    printf("\nURUTAN DATA SETELAH SELECTION SORT\n");
    tampilkan();
}

void laporan()
{
    Lapor.untung_pokok=0;
    Lapor.untung_sayur=0;
    Lapor.untung_tambahan=0;
    Lapor.untung_total=0;
    for(i=0; i<N; i++){
        if(strcmp(Brg[i].jenis,"pokok")==0){
            Lapor.untung_pokok=Lapor.untung_pokok+Brg[i].untung;
        }
        else if(strcmp(Brg[i].jenis,"sayuran")==0){
            Lapor.untung_sayur=Lapor.untung_sayur+Brg[i].untung;
        }
        else if(strcmp(Brg[i].jenis,"tambahan")==0){
            Lapor.untung_tambahan=Lapor.untung_tambahan+Brg[i].untung;
        }
        Lapor.untung_total=Lapor.untung_total+Brg[i].untung;
    }

}

void CatatLaporan()
{
    // MENULIS ISI LAPORAN
    lapor=fopen("laporan.txt","w");
    fwrite(&Lapor,sizeof(Lapor),1,lapor);
    fclose(lapor);
    // MEMBACA ISI LAPORAN
    lapor=fopen("laporan.txt","r");
    fread(&Lapor,sizeof(Lapor),1,lapor);
    fclose(lapor);

    printf("\nLaporan Keuntungan dagangan tiap jenis\n");
    printf("1. pokok : %d\n",Lapor.untung_pokok);
    printf("2. sayuran : %d\n",Lapor.untung_sayur);
    printf("3. tambahan : %d\n",Lapor.untung_tambahan);
    printf("Total Untung adalah : %d",Lapor.untung_total);
}
int main()
{
    printf("Jumlah Barang : ");
    scanf("%d",&N);
    printf("Jumlah Transaksi : ");
    scanf("%d",&M);

    isibarang();
    isijual();
    Buatarray();
    sisabarang();
    selection_sort();
    laporan();
    CatatLaporan();



return 0;
}

