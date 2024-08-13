//12S22045 - Cintya Sitorus
//12S22051 - Sefanya Yemima Sinaga
 

#include <stdio.h>
#include <string.h>

#define bahasa1 20
#define bahasa2 80
#define jumlah 5


struct dictionary {
    char english[bahasa1 + 1];
    char indonesian[bahasa2 + 1];
};


enum CommandType {
    REGISTER,
    FIND,
    STOP
};

int main() {
    
    struct dictionary word[jumlah];
    int banyakkata = 0;

    
    while (1) {
        
        char suruh[bahasa1+ 1];
        scanf("%s", suruh);

        
        enum CommandType commandType;
        if (strcmp(suruh, "register") == 0) {
            commandType = REGISTER;
        } else if (strcmp(suruh, "find") == 0) {
            commandType = FIND;
        } else if (strcmp(suruh, "---") == 0) {
            commandType = STOP;
        } 

        
        switch (commandType) {
            case REGISTER: {
                
                if (banyakkata == jumlah) {
                    break;
                } 

                
                char english[bahasa1+ 1];
                char indonesian[bahasa2+ 1];
                scanf("%s %[^\n]", english, indonesian);

                
                int n;
                for (n = 0; n < banyakkata; n++) {
                    if (strcmp(english, word[n].english) == 0) {
                        break;
                    }
                }
                if (n < banyakkata) {
                    break;
                }

                
                strcpy(word[banyakkata].english, english);
                strcpy(word[banyakkata].indonesian, indonesian);
                banyakkata++;
                break;
            }
            case FIND: {
                
                char english[bahasa1 + 1];
                scanf("%s", english);

                
                int n;
                for (n = 0; n < banyakkata; n++) {
                    if (strcmp(english, word[n].english) == 0) {
                        printf("%s#%s\n", word[n].english, word[n].indonesian);
                        break;
                    }
                }
                if (n == banyakkata) {
                }
                break;
            }
            case STOP:
                return 0;
        }
    }
}