// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Yemima Sinaga

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"


int main(int _argc, char **_argv) {
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char data[100];
    char id[10];
    char name[25];
    char year[5];
    char dorm_name[10];
    unsigned short capacity;
    char *kata;
    int std = 0, dr = 0;
    int idx_student, idx_dorm ;
   

    if (students == NULL || dorms == NULL) {
        printf("Failed to allocate memory. Exiting.\n");
        return -1;
    }

    while (fgets(data, sizeof(data), stdin) != NULL) { 
        data[strcspn(data, "\r\n")] = '\0';
    
        kata = strtok(data, "#");
        if (strcmp(kata, "student-add") == 0) {
            kata = strtok(NULL, "#");  
            strcpy(id, kata);
            kata = strtok(NULL, "#");  
            strcpy(name, kata);
            kata = strtok(NULL, "#");
            strcpy(year, kata);
            kata = strtok(NULL, "#");
            if (strcmp(kata, "male") == 0) {
                students[std] = create_student(id, name, year, GENDER_MALE);
            } else if (strcmp(kata, "female") == 0) {
                students[std] = create_student(id, name, year, GENDER_FEMALE);
            }
            std++;
        } else if (strcmp(kata, "dorm-add") == 0) {
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            kata = strtok(NULL, "#");
            capacity = atoi(kata);
            kata = strtok(NULL, "#");
            if (strcmp(kata, "male") == 0) {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_MALE);
            } else if (strcmp(kata, "female") == 0) {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            dr++;
        } else if (strcmp(kata, "student-print-all") == 0) {
            void (*pf)(struct student_t *, int) = NULL;
            pf = print_student;
            pf(students, std);
        } else if (strcmp(kata, "student-print-all-detail") == 0) {
            void (*pf)(struct student_t *, int) = NULL;
            pf = print_student_detail;
            pf(students, std);
        } else if (strcmp(kata, "dorm-print-all") == 0) {
            void (*pf)(struct dorm_t *, int) = NULL;
            pf = print_dorm;
            pf(dorms, dr);
        } else if (strcmp(kata, "dorm-print-all-detail") == 0) {
            void (*pf)(struct dorm_t *, int) = NULL;
            pf = print_dorm_detail;
            pf(dorms, dr);
        } else if (strcmp(kata, "assign-student")==0) 
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            int x;
            for (x = 0; x < std; ++x)
            {
                if(strcmp(students[x].id, id)==0)
                {
                    idx_student = x;
                    break;
                }
            }
            for (x = 0; x < std; ++x)
            {
                if(strcmp(dorms[x].name, dorm_name)==0)
                {
                    idx_dorm = x;
                    break;
                }
            }
            void (*pf)(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name) = NULL;
            pf = assign_student;
            pf(&students[idx_student], &dorms[idx_dorm], id, dorm_name);
        } 
        else if (strcmp(kata, "move-student")==0) 
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            idx_student = 0;
            idx_dorm = 0;
            int x ;
            for (x= 0; x < std; ++x){
                if(strcmp(students[x].id, id)==0)
                {
                    idx_student = x;
                    break;
                }
            }
            for (x = 0; x < std; ++x){
                if(strcmp(dorms[x].name, dorm_name)==0)
                {
                    idx_dorm = x;
                    break;
                }
            }
            if (students[idx_student].dorm==NULL)
            {
                void (*pf)(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name) = NULL;
                pf = assign_student;
                pf(&students[idx_student], &dorms[idx_dorm], id, dorm_name);
            } 
            else 
            {
                int x;
                for (x = 0; x < std; ++x)
                {
                    if(strcmp(students[idx_student].dorm->name, dorms[x].name)==0)
                    {
                        void (*pf)(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name) = NULL;
                        pf = move_student;
                        pf(&students[idx_student], &dorms[idx_dorm], &dorms[x], id, dorm_name);
                        break;
                    }
                }
            }    
        }
        else if(strcmp(kata, "---")==0)
        {
            break;
        } 
    }
    free(students);
    free(dorms);
    return 0;
}
