// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv) {

  int X1, X2;
  int waktu_tunggu_Ucok ;
  int waktu_tunggu_Butet ;
  int antri;
  
  //untuk ucok;
  if (X1==4){
    antri = 2;
    waktu_tunggu_Ucok=(antri*3)+3;
  } 
  else if (X1==0){
    antri = 0;
    waktu_tunggu_Ucok=(antri*3);
  }
  else if (X1==10){
    antri = 4;
    waktu_tunggu_Ucok=(antri*2);
  }

  //untuk butet
  if (X2==7){
    antri = 3;
    waktu_tunggu_Butet=(antri*3)+6;
  }
  else if (X2==2){
    antri = 1;
    waktu_tunggu_Butet=antri*3;
  }
  else if (X2==2){
    antri =1;
    waktu_tunggu_Butet=(antri*3)+3;
  }

  scanf("%d", &X1);
  scanf("%d", &X2);
  

 
  int waktu_tunggu_kombinasi = waktu_tunggu_Ucok + waktu_tunggu_Butet;

printf(" %d\n", waktu_tunggu_Ucok);
printf(" %d\n", waktu_tunggu_Butet);
printf(" %d\n", waktu_tunggu_kombinasi);


return 0;
}