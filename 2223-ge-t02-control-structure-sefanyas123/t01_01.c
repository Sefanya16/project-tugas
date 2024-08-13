// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv) {
  // codes
   int nomor_bulan;
    
        printf("Masukkan Angka Bulan (1-12) : ");
        scanf("%d",&nomor_bulan);
        {
         if  (nomor_bulan == 1)
           printf("Januari\n February\n Maret ");
         else if  (nomor_bulan == 2)
              printf("Februari\n Maret \n April ");
         else if  (nomor_bulan == 3)
              printf("Maret\n April \n Mei");
         else if (nomor_bulan == 4)
              printf("April\n Mei \n Juni");
         else if (nomor_bulan ==5)
              printf("Mei\n Juni \n Juli ");
         else if (nomor_bulan== 6)
              printf("Juni\n Juli\n Agustus");
         else if (nomor_bulan == 7)
              printf("Juli\n Agustus\n September");
         else if  (nomor_bulan == 8)
              printf("Agustus\n September\n Oktober");
         else if (nomor_bulan == 9)
              printf("September \n Oktober\n November");
         else if (nomor_bulan == 10)
              printf("Oktober \n November \n Desember");
         else if (nomor_bulan == 11)
              printf("November\n Desember\n Happy New year\n January");
         else if (nomor_bulan == 12)
              printf("Desember\n Happy New Year\n January\n February"); 
        }
   
  return 0;
}
