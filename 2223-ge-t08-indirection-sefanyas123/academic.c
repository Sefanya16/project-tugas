// 12S22045 - Cintya Sitorus
// 12S22051 - Sefanya Yemima Sinaga

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) 
{

    switch (_grade) 
    {

        case GRADE_NONE:return "None";
        case GRADE_A:return "A";
        case GRADE_AB:return "AB";
        case GRADE_B:return "B";
        case GRADE_BC:return "BC";
        case GRADE_C:return "C";
        case GRADE_D:return "D";
        case GRADE_E:return "E";
        default:return "";}
    
}


float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    
    float performance = 0.0;
    switch (_grade) 
    {
        case GRADE_A:
            performance = 4.0;
            break;
        case GRADE_AB:
            performance = 3.5;
            break;
        case GRADE_B:
            performance = 3.0;
            break;
        case GRADE_BC:
            performance = 2.5;
            break;
        case GRADE_C:
            performance = 2.0;
            break;
        case GRADE_D:
            performance = 1.0;
            break;
        case GRADE_E:
            performance = 0.0;
            break;
        case GRADE_T:
            break;
        case GRADE_NONE:
            performance = 0.0;
            break;

    }

    float hasilakhir = performance *= _credit;

    return hasilakhir;
}

void print_course(struct course_t _course) 
{


    printf("%s|", _course.code);
    printf("%s|", _course.name);
    printf("%hu|", _course.credit);
    printf("%s\n", grade_to_text(_course.passing_grade));


}


void print_student(struct student_t _student) 
{

    printf("%s|", _student.id);
    printf("%s|", _student.name);
    printf("%s|", _student.year);
    printf("%s|", _student.study_program);
    printf("%.2f\n", _student.gpa);}

void print_enrollment(struct enrollment_t _enrollment) {


    printf("%s|", _enrollment.course.code);
    printf("%s|", _enrollment.student.id);
    printf("%s|",grade_to_text( _enrollment.grade));
    printf("%.2f\n", calculate_performance(_enrollment.grade, _enrollment.course.credit));


};

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size) 

{
    int i;
    for (i = 0; i < _enrollment_size; i++)
    {

        print_enrollment(_enrollments[i]);
        
    }
}


struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade){


    struct course_t crs;

    strcpy (crs.code, _code);
    strcpy (crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;

    return crs;


}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)

{

    struct student_t std;


    strcpy (std.id, _id);
    strcpy (std.name, _name);
    strcpy (std.year, _year);
    strcpy (std.study_program, _study_program);
    std.gpa = 0.0;

    return std;

}

struct enrollment_t create_enrollment(struct course_t _course, struct student_t _student, char *_year, enum semester_t _semester){
    

    struct enrollment_t emt;

    emt.course = _course;
    emt.student = _student;
    strcpy (emt.year, _year);
    emt.semester = _semester;
    emt.grade = GRADE_NONE;


    return emt;

}

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)

{

    float total_credit =  0.0;
    float total_performance = 0.0;

    int i;
    for ( i = 0; i < _enrollment_size; i++)
    {

      if (strcmp (_enrollments[i].student.id, _student -> id) == 0){

        float performance =  calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
        total_credit += _enrollments[i].course.credit;
        total_performance += performance;

      }

    }
    
    if (total_credit == 0.0){

        _student ->gpa = 0.0;
        }

    else
    {
        _student ->gpa = total_performance / total_credit;
    }
    
   
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{

    int i;

    for (i = 0; i <_enrollment_size; i++)

    {

        if (strcmp(_enrollments[i].course.code, _course.code) == 0 &&
        strcmp (_enrollments[i].student.id, _student.id) == 0) 
        {

            _enrollments[i].grade = _grade;
            break;

        }
    }
}
