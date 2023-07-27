#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void menu();
void tambahBarang();
void informasiBarang();
void historyBarang();
void updateBarang();
void hapusBarang();
void tanggal();
void aboutUs();
void ambilBarang();

struct DATA {
	char nama[30], jml[50];
	char date[20], row[100], id[20], temp[50], *token, baru[100];
	char pengguna[100], tujuan[100], berapa[50];
}tambah,info,hapus,update,ambil,sejarahh, ambilnew;

int main(){
    system("cls");
    printf("Loading");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    menu();
    return 0;        
}

void tanggal(){
	printf("Selamat datang di aplikasi inventory");
	time_t mytime;
	time(&mytime);
	printf("\n%s", ctime(&mytime));
	
}

void menu(){
    int pilihan;
    start:

    system("cls");
    tanggal();
	printf("\n");
	printf("+================= MENU UTAMA =================+\n");
	printf("|                                              |\n");
	printf("| 1. TAMBAH BARANG                             |\n");
	printf("| 2. INFORMASI BARANG                          |\n");
	printf("| 3. HISTORY PENGGUNAAN                        |\n");
	printf("| 4. UPDATE BARANG                             |\n");
	printf("| 5. HAPUS BARANG                              |\n");
	printf("| 6. PENGAMBILAN BARANG                        |\n");    
	printf("| 7. ABOUT US                                  |\n");
	printf("| 8. EXIT                                      |\n");    
	printf("|                                              |\n");    
	printf("+==============================================+\n");
	
	printf("\nMasukkan pilihan anda : ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        tambahBarang();
        break;
    case 2:
        informasiBarang();
        break;
    case 3:
        historyBarang();
        break;
    case 4:
        updateBarang();
        break;
    case 5:
        hapusBarang();
        break;    
    case 6:
        ambilBarang();
        break;
    case 7:
        aboutUs();
        break;
    case 8:
        break;                
    default:
        printf("anda salah input coba kembali input sesuai angka diatas : ");
        getche();
        goto start;
    }
}

void tambahBarang(){
	FILE *ptr;
	
    ptr =fopen("inventory.txt","a");
	system("cls");
    printf("================= TAMBAH BARANG =================\n");
    printf("| \n");
    printf("| Masukkan \n");
	printf("| ID Barang   : ");fflush(stdin);            
	scanf("%[^\n]",tambah.id);    
	printf("| Nama barang : ");fflush(stdin);
	scanf("%[^\n]",tambah.nama);
	printf("| Stok        : ");fflush(stdin);
	scanf("%[^\n]",&tambah.jml);
	time_t mytime;
	time(&mytime);    
	fprintf(ptr,"%s;%s;%s;%s",tambah.id,tambah.nama,tambah.jml,ctime(&mytime));
	fclose(ptr);
    printf("\nBarang berhasil ditambahkan.");
    salah_tambah:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    goto salah_tambah;
    }
}

void informasiBarang(){
    FILE *inf = fopen("inventory.txt", "r");
    char *token;
    int no, numb, jmlstk;
    printf("ketik 1 untuk informasi semua barang dan ketik 2 untuk informasi berdasarkan stok : ");
    scanf("%d", &numb);
    if (numb == 1)
    {
        system("cls");    
        printf("\n");
        printf("\n");
        printf(" ================= INFORMASI BARANG =================\n");
        printf("\n                    SEMUA BARANG                    \n");
        printf("   +--------+---------------- +--------+-------------------------+\n");
        printf("   |   ID   |   NAMA BARANG   |  STOK  |           DATE          |\n");
        printf("   +--------+-----------------+--------+-------------------------+\n");
        while (fgets(info.row, 100, inf) != NULL)
        {
            token = strtok(info.row, ";");
            while (token != NULL)
            {
                printf("\t%s", token);
                token = strtok(NULL, ";");
            }
        }
    }else if (numb == 2){
        system("cls");
        printf("\n");
        printf("Masukan Jumlah stok : ");
        scanf("%d", &jmlstk);
        printf(" ================= INFORMASI BARANG =================\n");
        printf("\n                 BERDASARKAN STOK                    \n");    
        printf("   +--------+---------------- +--------+-------------------------+\n");
        printf("   |   ID   |   NAMA BARANG   |  STOK  |           DATE          |\n");
        printf("   +--------+-----------------+--------+-------------------------+\n");
        while (fgets(info.row, 100, inf) != NULL)
        {
            strcpy(info.temp, info.row);
            token = strtok(info.row, ";");
            token = strtok(NULL, ";");
            token = strtok(NULL, ";");  
            no = atoi(token);
            if (no <= jmlstk)
            {
                token = strtok(info.temp, ";");
                while (token != NULL)
                {
                    printf("\t%s", token);
                    token = strtok(NULL, ";");
                }                
            }
        }         
    }else{
        printf("salah");
    }   
    fclose(inf);
    salah_info:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    ;
    goto salah_info;
    }
}

void historyBarang(){
	FILE *sejarah = fopen("pengambilan.txt", "r");
	char *kata;
    system("cls");    
	printf("\n");
	printf("\n");
	printf(" ================================================ HISTORY =================================================\n");
	printf("\n");
	printf(" Barang yang keluar : \n");
	printf("\n");
	printf("   +---------+--------------------+-----------------+--------+------------+-------------------------------+\n");
	printf("   |    ID   |     NAMA BARANG    |  NAMA PENGGUNA  | JUMLAH |   TUJUAN   |              DATE             |\n");
	printf("   +---------+--------------------+-----------------+--------+------------+-------------------------------+\n");
	while(fgets(sejarahh.row, 100, sejarah) != NULL)
	{
		kata = strtok(sejarahh.row, ";");
		while(kata != NULL)
		{
			printf("\t%s     ", kata);
			kata = strtok(NULL, ";");
		}
	}
	fclose(sejarah);
    salah_history:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!! ");
    ;
    goto salah_history;
    }
}

void updateBarang(){
    FILE *upd=fopen("inventory.txt","r+");
    FILE *updTemp=fopen("invTemp.txt","w");    
    system("cls");    
	int a;
	printf("\n");
	printf("+======== UPDATE BARANG =======+\n");
	printf("|                              |\n");
	printf("| 1. Nama Barang               |\n");
	printf("| 2. Stok Barang               |\n");
	printf("|                              |\n");
	printf("+==============================+\n\n");
    wrong_edit:    
	printf("Masukkan pilihan anda : "); scanf("%d", &a);    
    printf("Masukan ID Barang yang diedit  : ");fflush(stdin);            
    scanf("%[^\n]",update.id);    
	while (fgets(update.row, 100, upd)!=NULL)
    {
        strcpy(update.temp, update.row);
        update.token = strtok(update.row, ";");
        if (strcmp(update.token, update.id)==0)
        {        
            time_t mytime;
            time(&mytime);            
            if (a == 1){
                update.token = strtok(update.temp, ";");
                update.token = strtok(NULL, ";");
                update.token = strtok(NULL, ";");                 
                printf("Masukan nama barang baru : ");fflush(stdin);            
                scanf("%[^\n]",update.baru);                    
                fprintf(updTemp,"%s;%s;%s;%s", update.id, update.baru, update.token, ctime(&mytime));
            }else if(a == 2){
                printf("Masukan stok barang baru : ");fflush(stdin);            
                scanf("%[^\n]",update.baru);      
                update.token = strtok(update.temp, ";");
                update.token = strtok(NULL, ";");
                fprintf(updTemp,"%s;%s;%s;%s", update.id, update.token, update.baru, ctime(&mytime));
            }else{
                printf("salahh");
                goto wrong_edit;
            }        
        }else
        {
            fprintf(updTemp, update.temp);
        }
    }    
    printf("berhasil edit");    
    fclose(upd);
    fclose(updTemp);
    remove("inventory.txt");
    rename("invTemp.txt", "inventory.txt");
    salah_update:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    ;
    goto salah_update;
    }
}

void hapusBarang(){
    FILE *upd=fopen("inventory.txt","r+");
    FILE *updTemp=fopen("invTemp.txt","w");        
    system("cls");    
	printf("\n");
	printf("================= HAPUS BARANG =================\n");
	printf("|\n");
    printf("Masukan ID Barang yang dihapus  : ");fflush(stdin);            
    scanf("%[^\n]",update.id);    
	while (fgets(update.row, 100, upd)!=NULL)
    {
        strcpy(update.temp, update.row);
        update.token = strtok(update.row, ";");
        if (strcmp(update.token, update.id)!=0)
        {        
            fprintf(updTemp, update.temp);                
        }
    }    
    printf("Barang dengan ID %s dihapus dari Inventory \n", update.id);
    fclose(upd);
    fclose(updTemp);
    remove("inventory.txt");
    rename("invTemp.txt", "inventory.txt");
    salah_hapus:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    ;
    goto salah_hapus;
    }
}

void ambilBarang(){
	FILE *ambl = fopen("pengambilan.txt", "a");
	FILE *ambl1 = fopen("inventory.txt", "r");
	FILE *ambl2 = fopen("inventorytemp.txt", "w");
	int no, yes, hasil;
	char hasil2[50];
    system("cls");
	printf("\n");
	printf(" ================= PENGAMBILAN =================\n");
	printf("\n");
	printf(" Masukkan ID Barang   : "); fflush(stdin); scanf("%[^\n]",ambilnew.id);
	printf(" Nama Pengguna        : "); fflush(stdin); scanf("%[^\n]",ambilnew.pengguna); 
	printf(" Jumlah               : "); fflush(stdin); scanf("%[^\n]",ambilnew.berapa); 
	printf(" Tujuan               : "); fflush(stdin); scanf("%[^\n]",ambilnew.tujuan); 
	time_t mytime;
	time(&mytime);
	while(fgets(ambil.row, 100, ambl1) != NULL)
	{
		strcpy(ambil.temp, ambil.row);
		ambil.token = strtok(ambil.row, ";");
		if (strcmp(ambil.token, ambilnew.id) == 0){
			time_t mytime;
			time(&mytime);
			ambilnew.token = strtok(ambil.temp, ";");
			ambilnew.token = strtok(NULL, ";");
			fprintf(ambl,"%s;%s;%s;%s;%s;%s",ambilnew.id,ambilnew.token,ambilnew.pengguna,ambilnew.berapa,ambilnew.tujuan,ctime(&mytime));
			ambil.token = strtok(NULL, ";");
			no = atoi(ambil.token);
			yes = atoi(ambilnew.berapa);
			hasil = no - yes;
			itoa(hasil, hasil2, 10);
			fprintf(ambl2,"%s;%s;%s;%s",ambilnew.id,ambilnew.token,hasil2,ctime(&mytime));
		}else{
			fprintf(ambl2, ambil.temp);
		}
	}
	fclose(ambl);
	fclose(ambl1);
	fclose(ambl2);
	
	remove("inventory.txt");
	rename("inventorytemp.txt", "inventory.txt");
	printf("\nBarang dengan id %s berhasil diambil.", ambilnew.id);
    salah_ambil:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    ;
    goto salah_ambil;
    }
}

void aboutUs(){
    system("cls");    
	printf("\n");
	printf("+====================== ABOUT US ======================+\n");
	printf("|                                                      |\n");
	printf("| 1. SYAHRUL PANGESTU - 202010370311299                |\n");
	printf("| 2. FAUZAN ADRIVANO SETIONO - 202010370311312         |\n");
	printf("| 3. AGNES AYU MAHARANI DYAH GAYATRI - 202010370311288 |\n");
	printf("|                                                      |\n");    
	printf("+======================================================+\n\n");    
    salah_about:
    printf("\n\nketik 1 untuk ke menu utama dan ketik 0 untuk keluar : ");
    switch (getch())
    {
    case '1':
        menu();
        break;
    case '0':
        break;
    default:
    printf("\nsalah input!!");
    ;
    goto salah_about;
    }
}
