#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t stu;

    strcpy(stu.id, _id);
    strcpy(stu.name, _name);
    strcpy(stu.year, _year);
    stu.gender = _gender;
    stu.dorm = malloc (sizeof(struct dorm_t));
    stu.dorm = NULL;

    return stu;
}

void print_student(struct student_t *_student, int jumlah)
{
    int j;
    for (j = 0; j < jumlah; j++)
    {
        if(_student[j].gender ==  GENDER_MALE)
        {
            printf("%s|%s|%s|male\n", _student[j].id, _student[j].name, _student[j].year);
        }
        else if (_student[j].gender ==  GENDER_FEMALE)
        {
            printf("%s|%s|%s|female\n", _student[j].id, _student[j].name, _student[j].year);
        }
    }   
}

void print_student_detail(struct student_t *_student, int jumlah)
{
    int k;
    for (k= 0; k < jumlah; k++)
    {
        if (_student[k].dorm == NULL)
        {
            if (_student[k].gender==GENDER_MALE)
            {
                printf("%s|%s|%s|male|unassigned\n", _student[k].id, _student[k].name, _student[k].year);
            } 
            else if (_student[k].gender==GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|unassigned\n", _student[k].id, _student[k].name, _student[k].year);
            }
        }   
        else 
        {         
            if (_student[k].gender==GENDER_MALE)
            {
                printf("%s|%s|%s|male|%s\n", _student[k].id, _student[k].name, _student[k].year, _student[k].dorm->name);
            } 
            else if (_student[k].gender==GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|%s\n", _student[k].id, _student[k].name, _student[k].year, _student[k].dorm->name);
            }
        }  
    }

}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->capacity > _dorm->residents_num)
    {
        if (_dorm->gender == _student->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}
 
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_dorm->gender== _student->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num++;
            old_dorm->residents_num--;
            
        }
    }   
}
