// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Yemima Sinaga

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv) 
{
    struct student_t *students = malloc(12 * sizeof(struct student_t));
    char data[100];
    char id[10];
    char name[25];
    char year[5];
    char study_program[25];
    float gpa[5];
    char *kata;
    int i= 0;
    struct student_t std[100];
    

    do
    {
        data[0] = '\0';
        int k = 0;
        while (1)
        {
            char c = getchar();
            if (c == '\n')
            {
                break;
            }
            if (c == '\r')
            {
                continue;
            }
            data[k] = c;
            data[++k] = '\0';
        }
        if (strstr(data, "create-student") != NULL)
        {
            kata = strtok(data, "#");
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(name, kata);
            kata = strtok(NULL, "#");
            strcpy(year, kata);
            kata = strtok(NULL, "#");
            strcpy(study_program, kata);
            
            students[i] = create_student(id, name, year, study_program);
            i++;
        }      
        
        else if (strstr(data, "print-students") != NULL) 
        {
            
            print_students(students, i);
           
        }
        if(strcmp(data, "---")==0) 
        {
            break;
        } 
    } while (1);
    
    free (students);    
     
    return 0; 
} 

