#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

void repository(struct student_t *student, struct dorm_t *dorm, int *dormc, int *studentc);
// void fdorm_print(struct dorm_t *dorm, int dormc);
void fdorm_print_detail(struct dorm_t *dorm, int dormc); 
void fstudent_print(struct student_t *student, int studentc);
void fstudent_print_detail(struct student_t *student, int studentc);
#endif
