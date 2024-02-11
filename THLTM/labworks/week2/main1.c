#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct student{
 char name[20];
 int eng;
 int math;
 int phys;
}STUDENT;
STUDENT data[]={
 {"Tuan", 82, 72, 58},
 {"Nam", 77, 82, 79}, 
 {"Khanh", 52, 62, 39}, 
 {"Phuong", 61, 82, 88}
}; 
STUDENT *p;

void print_mean_student(STUDENT *p){
    printf("=========================\n");
    for(int i = 0; i <4; i++){
        p = &data[i];
    printf("Ten: %s\n" ,p->name);
    printf("Diem tieng Anh: %d\n" ,p->eng);
    printf("Diem Toan: %d\n" ,p->math);
    printf("Diem Vat Ly: %d\n" ,p->phys);
    }

}

int main()
{
    printf("Ket qua cua sinh vien la:\n");
    for(int i = 0; i <4; i++){
        print_mean_student(&data[i]);
    }
    return 0;
}