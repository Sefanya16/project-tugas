// 12S22045 - Cintya Sitorus
// 12S22051  - Sefanya Yemima Sinaga

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    int sizestd = 0;
    int th[100];
    int sh = 0;
    int slp[100];
    int tls = 0;

    char input[255];
    // dorm
    int temp_size_dorm = 0;
    int dorm_showall[100], dorm_slc = 0;
    int dorm_showalldetail[100], dorm_sh = 0;
    char scheduler[255][255];
    int count_scheduler = 0;

    struct student_t *student = malloc(100 * sizeof(struct student_t));
    struct student_t *student_modified = malloc(100 * sizeof(struct student_t));

    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    struct dorm_t *dorm_modified = malloc(100 * sizeof(struct dorm_t));

    void (*printstudents)(struct student_t * student, int tls);
    void (*function)(struct student_t * student, struct dorm_t * dorm, char *nim, char *ldorm, int size_student, int size_dorm);

    repository(student, dorm, &temp_size_dorm, &sizestd);

    while (1 == 1)
    {
        fflush(stdin);
        input[0] = '\0';
        int l = 0;
        while (1)
        {
            char c = getchar();
            if (c == '\r')
            {
                continue;
            }
            if (c == '\n')
            {
                break;
            }
            input[l] = c;
            input[++l] = '\0';
        }
        if (strcmp(input, "---") == 0)
        {
            int i;
            int temp1 = 0;
            int temp2 = 0;
            int temp3 = 0;
            int temp4 = 0;
            for (i = 0; i < count_scheduler; i++)
            {
                if (strcmp(scheduler[i], "student-print-all") == 0)
                {
                    printstudents = print_student;
                    printstudents(student, th[temp1]);
                    fstudent_print(student, th[temp1]);
                    temp1++;
                }
                if (strcmp(scheduler[i], "student-print-all-detail") == 0)
                {
                    printstudents = print_student_details;
                    printstudents(student, slp[temp2]);
                    fstudent_print_detail(student, slp[temp2]);
                    temp2++;
                }
                if (strcmp(scheduler[i], "dorm-print-all") == 0)
                {
                    // print_dorm(dorm, dorm_showall[temp3]);
                    // fdorm_print(dorm, dorm_showall[temp3]);
                    temp3++;
                } 
                if (strcmp(scheduler[i], "dorm-print-all-detail") == 0)
                {
                    print_dorm_detail(dorm, dorm_showalldetail[temp4]);
                    fdorm_print_detail(dorm, dorm_showalldetail[temp4]);
                    temp4++;
                }
                if (strcmp(scheduler[i], "modified") == 0)
                {
                    CPstudent(student_modified, student, sizestd);
                    CPdorm(dorm_modified, dorm, temp_size_dorm);
                } 
            }
            break;
        }
        else if (strcmp(input, "student-print-all") == 0)
        {
            strcpy(scheduler[count_scheduler], "student-print-all");
            count_scheduler++;
            th[sh] = sizestd;
            sh++;
        }
        else if (strcmp(input, "student-print-all-detail") == 0)
        {
            strcpy(scheduler[count_scheduler], "student-print-all-detail");
            count_scheduler++;
            slp[tls] = sizestd;
            tls++;
        }
        else if (strcmp(input, "dorm-print-all") == 0)
        {
            strcpy(scheduler[count_scheduler], "dorm-print-all");
            count_scheduler++;
            dorm_showall[dorm_slc] = temp_size_dorm;
            dorm_slc++;
        }
        else if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            strcpy(scheduler[count_scheduler], "dorm-print-all-detail");
            count_scheduler++;
            dorm_showalldetail[dorm_sh] = temp_size_dorm;
            dorm_sh++;
        }
        else
        {
            char temp_id[255], temp_name[255], temp_year[255];
            int capacity = 0;
            char *token = strtok(input, "#");
            char assign_nim[255];
            char assign_dorm[255];
            // move
            char move_nim[255];
            char move_dorm[255];

            char temp[255];
            strcpy(temp, token);
            if (strcmp(temp, "student-add") == 0)
            {
                token = strtok(NULL, "#");
                strcpy(temp_id, token);
                token = strtok(NULL, "#");
                strcpy(temp_name, token);
                token = strtok(NULL, "#");
                strcpy(temp_year, token);
                token = strtok(NULL, "#");
                if (strcmp("male", token) == 0)
                {
                    student[sizestd] = create_student(temp_id, temp_name, temp_year, GENDER_MALE);
                    sizestd++;
                }
                else
                {
                    student[sizestd] = create_student(temp_id, temp_name, temp_year, GENDER_FEMALE);
                    sizestd++;
                }
            }
            else if (strcmp(temp, "dorm-add") == 0)
            {
                token = strtok(NULL, "#");
                strcpy(temp_name, token);
                token = strtok(NULL, "#");
                capacity = atoi(token);
                token = strtok(NULL, "#");
                if (strcmp("male", token) == 0)
                {
                    dorm[temp_size_dorm] = create_dorm(temp_name, capacity, GENDER_MALE);
                    temp_size_dorm++;
                }
                else
                {
                    dorm[temp_size_dorm] = create_dorm(temp_name, capacity, GENDER_FEMALE);
                    temp_size_dorm++;
                }
            }
            else if (strcmp(temp, "assign-student") == 0)
            {
                token = strtok(NULL, "#");
                strcpy(assign_nim, token);
                token = strtok(NULL, "#");
                strcpy(assign_dorm, token);
                function = assign_student;
                function(student, dorm, assign_nim, assign_dorm, sizestd, temp_size_dorm);
            }
            else if (strcmp(temp, "move-student") == 0)
            {
                token = strtok(NULL, "#");
                strcpy(move_nim, token);
                token = strtok(NULL, "#");
                strcpy(move_dorm, token);
                function = move_student;
                function(student, dorm, move_nim, move_dorm, sizestd, temp_size_dorm);
            }
            else if (strcmp(temp, "dorm-empty") == 0)
            {
                CPstudent(student, student_modified, sizestd);
                CPdorm(dorm, dorm_modified, temp_size_dorm);
                token = strtok(NULL, "#");
                dorm_empty(student_modified, dorm_modified, token, sizestd, temp_size_dorm);
                strcpy(scheduler[count_scheduler], "modified");
                count_scheduler++;
            }
        }
    }
    free(student);
    free(dorm);
    free(student_modified);
    free(dorm_modified);
    return 0;
}

