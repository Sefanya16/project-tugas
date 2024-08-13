#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void repository(struct student_t *student, struct dorm_t *dorm, int *dormc, int *studentc)
{
    int sizestd = *studentc;
    int temp_size_dorm = *dormc;
    FILE *fp_dorm, *fp_student;
    fp_dorm = fopen("storage/dorm-repository.txt", "r");
    fp_student = fopen("storage/student-repository.txt", "r");
    if (fp_dorm == NULL || fp_student == NULL)
    {
        printf("File not found\n");
        return;
    }
    else
    {
        while (!feof(fp_dorm))
        {
            char fdorm_name[255], fgender[255];
            int fcapacity = 0;
            fscanf(fp_dorm, "%[^|]|%d|%[^\n]\n", fdorm_name, &fcapacity, fgender);
            if (fdorm_name != NULL && fcapacity != 0 && fgender != NULL)
            {
                if (strcmp(fgender, "female") == 0)
                {
                    dorm[temp_size_dorm] = create_dorm(fdorm_name, fcapacity, GENDER_FEMALE);
                }
                else if (strcmp(fgender, "male") == 0)
                {
                    dorm[temp_size_dorm] = create_dorm(fdorm_name, fcapacity, GENDER_MALE);
                }
            }
            temp_size_dorm++;
        }
        while (!feof(fp_student))
        {
            char fnim[255], fnama[255], fyear[255], fgender[255];
            fscanf(fp_student, "%[^|]|%[^|]|%[^|]|%[^\n]\n", fnim, fnama, fyear, fgender);
            if (fnim != NULL && fnama != NULL && fyear != NULL && fgender != NULL)
            {
                if (strcmp(fgender, "female") == 0)
                {
                    student[sizestd] = create_student(fnim, fnama, fyear, GENDER_FEMALE);
                }
                else if (strcmp(fgender, "male") == 0)
                {
                    student[sizestd] = create_student(fnim, fnama, fyear, GENDER_MALE);
                }
            }
            sizestd += 1;
        }
    }
    *dormc = temp_size_dorm;
    *studentc = sizestd;
}

// void fdorm_print(struct dorm_t *dorm, int dormc)
// {
//     FILE *fp_dorm;
//     fp_dorm = fopen("storage/dorm-repository.txt", "w");

//     if (fp_dorm == NULL)
//     {
//         printf("\n");
//         return;
//     }
//     else
//     {
//         int j;
//         for (j = 0; j < dormc; j++)
//         {
//             fprintf(fp_dorm, "%s|%d|", dorm[j].name, dorm[j].capacity);
//             if (dorm[j].gender == GENDER_MALE)
//             {
//                 fprintf(fp_dorm, "male\n");
//             }
//             else
//             {
//                 fprintf(fp_dorm, "female\n");
//             }
//         }
//     }
// }

void fdorm_print_detail(struct dorm_t *dorm, int dormc)
{
    FILE *fp_dorm;
    fp_dorm = fopen("storage/dorm-repository.txt", "r");

    if (fp_dorm == NULL)
    {
        printf("\n"); 
        return;
    }
    else
    {
        int j;
        for (j = 0; j < dormc; j++)
        {
            fprintf(fp_dorm, "%s|%d|", dorm[j].name, dorm[j].capacity);
            if (dorm[j].gender == GENDER_MALE)
            {
                fprintf(fp_dorm, "male|");
            }
            else
            {
                fprintf(fp_dorm, "female|");
            }
            fprintf(fp_dorm, "%d\n", dorm[j].residents_num);
        }
    }
}

// void fstudent_print(struct student_t *student, int studentc)
// {
//     FILE *fp_student;

//     fp_student = fopen("storage/student-repository.txt", "w");
//     if (fp_student == NULL)
//     {
//         printf("\n");
//         return;
//     }
//     else
//     {
//         int j = 0;
//         for (j = 0; j < studentc; j++)
//         {
//             fprintf(fp_student, "%s|%s|%s|", student[j].id, student[j].name, student[j].year);
//             if (student[j].gender == GENDER_MALE)
//             {
//                 fprintf(fp_student, "male\n");
//             }
//             else
//             {
//                 fprintf(fp_student, "female\n");
//             }
//         }
//     }
// }

void fstudent_print_detail(struct student_t *student, int studentc)
{
    FILE *fp_student;

    fp_student = fopen("storage/student-repository.txt", "r");
    if (fp_student == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        int j;
        for (j = 0; j < studentc; j++)
        {
            fprintf(fp_student, "%s|%s|%s|", student[j].id, student[j].name, student[j].year);
            if (student[j].gender == GENDER_MALE)
            {
                fprintf(fp_student, "male|");
            }
            else
            {
                fprintf(fp_student, "female|");
            }
            if (student[j].dorm != NULL)
            {
                fprintf(fp_student, "%s", student[j].dorm->name);
            }
            else
            {
                fprintf(fp_student, "unassigned");
            }
        }
    }
}
