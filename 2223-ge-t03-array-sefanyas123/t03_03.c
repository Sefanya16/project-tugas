// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Sinaga 

#include <stdio.h>

int main(int _argc, char **_argv) {
  int n;
    int min_value;  // inisialisasi min_value dengan angka yang besar agar diupdate dengan input yang lebih kecil
    int max_value; // inisialisasi max_value dengan angka yang kecil agar diupdate dengan input yang lebih besar
    float ratarata;
    float minratarata=0.00;
    float maxratarata=0.00;
    int ang1,ang2;
     scanf("%d", &n);
     int arr[n];

     for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
     }

     max_value=arr[0];
     min_value=arr[0];

    for (int i = 1; i < n; i++) {
        
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    for (int i = 0 ; i < (n-1) ; i++){
      ang1 = arr[i];
      ang2 = arr[i+1];
      ratarata = (float) (ang1+ang2) /2;

      if (i==0){
        minratarata = ratarata;
      }

      if (ratarata < minratarata){

        minratarata=ratarata;
      }
      if (ratarata > maxratarata){

        maxratarata=ratarata;
      }

    }

    
    printf("%d\n", min_value);
    printf("%d\n", max_value);
    printf("%.2f\n",minratarata);
    printf("%.2f\n",maxratarata);


  return 0;
}

