// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Yemima Sinaga

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv) 
{
  struct student_t *students = malloc(12 * sizeof(struct student_t));
  struct course_t *courses = malloc(4 * sizeof(struct course_t));
  char data[100];
  char id[10];
  char name[25];
  char course_name[25];
  char year[5];
  char study_program[25];
  float gpa[5];
  char code[8];
  unsigned short credit;
  char passing_grade;
  char *kata;
  int i= 0;
  int j= 0;
  struct student_t std[100];
  struct course_t crs[100];

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

        else if (strstr(data, "create-course") != NULL)
        {
          kata = strtok(data, "#");
          kata = strtok(NULL, "#");
          strcpy(code, kata);
          kata = strtok(NULL, "#");
          strcpy(course_name, kata);
          kata = strtok(NULL, "#");
          credit = atoi(kata);
          kata = strtok(NULL, "#");
          passing_grade = atoi(kata);
          int gradef;

          if (strcmp(kata,"A")==0)
            {
              gradef = 8;
            }
             if (strcmp(kata,"AB")==0)
            {
              gradef = 7;
            }
             if (strcmp(kata,"B")==0)
            {
              gradef = 6;
            }
             if (strcmp(kata,"BC")==0)
            {
              gradef = 5;
            }
             if (strcmp(kata,"C")==0)
            {
              gradef = 4;
            }
             if (strcmp(kata,"D")==0)
            {
              gradef = 3;
            }
             if (strcmp(kata,"E")==0)
            {
              gradef = 2;
            }
             if (strcmp(kata,"T")==0)
            {
              gradef = 1;
            }
             if (strcmp(kata,"None")==0)
            {
              gradef = 0;
            }

            crs[j].passing_grade=gradef;
          courses[j] = create_course(code, course_name, credit, gradef);
          j++;
        }

        else if (strstr(data, "print-courses") != NULL) 
        {
            
          print_courses(courses, j);

        }

        if(strcmp(data, "---")==0)

        {
            break;    
        } 
    } while (1);
    
    free (students);  
    free (courses);

    return 0;
}
