// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Yemima Sinaga

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int l = atoi(argv[1]);
    char s[120];
    fgets(s, sizeof(s), stdin);
    int n;
    n = (strlen(s)-2) / l + ((strlen(s)-2) % l != 0);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < l; j++) {
            if (i * l + j < (strlen(s)-1)) {
                printf("%c", s[i * l + j]);
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;

    
}