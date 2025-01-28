#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX_STUDENTS 100
#define MAX_SUBJECTS 10

struct Student{
char name[50];
float  scores[MAX_SUBJECTS];
int num_subjects;
};

void add_student(struct Student students[], int  *num_students){

if(*num_students >= MAX_STUDENTS){
printf("Maximum number of students  reached.\n");
return;
}

printf("Enter student name: ");
 scanf("%s",students[*num_students].name);

printf("Enter number of subjects: ");
scanf("%d",  &students[*num_students].num_subjects);

printf("Enter scores for each subject:\n");
for (int i  = 0; i < students[*num_students].num_subjects; i++)
{
 scanf("%f", &students[*num_students].scores[i]);
}

(*num_students)++;

}

void  view_summary(struct Student students[], int num_students){

if(num_students == 0){
printf("No students  added yet.\n");
return;
}

for (int i = 0; i <  num_students; i++)
{
printf("\nStudent: %s\n",students[i].name);

float sum  = 0;
for (int j = 0; j <  students[i].num_subjects; j++)
{
sum += students[i].scores[j];
}
float average = sum /  students[i].num_subjects;
printf("Average Score: %.2f\n", average);

float highest =  students[i].scores[0];
float lowest = students[i].scores[0];
for (int  j = 1; j < students[i].num_subjects; j++)
{
if  (students[i].scores[j] > highest)
{
highest = students[i].scores[j];
}
if  (students[i].scores[j] < lowest)
{
lowest = students[i].scores[j];
}
}
 printf("Highest Score: %.2f\n", highest);
printf("Lowest Score:  %.2f\n", lowest);

printf("---------------------\n");
}
}

int main(){
struct Student  students[MAX_STUDENTS];
int num_students = 0;
int choice;

do{
printf("\nStudent  Grade Management System\n");
printf("1. Add Student\n");
printf("2. View Student  Summary\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d",  &choice);

switch(choice){
case 1:
add_student(students, &num_students);
break;
 case 2:
view_summary(students, num_students);
break;
case 3:
 printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
 }
while (choice!= 3);

return 0;
}