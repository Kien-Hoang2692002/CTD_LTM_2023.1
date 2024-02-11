#include <stdio.h>
#include <string.h>
#include <math.h>

struct student {
 char name[20];
 int eng;
 int math;
 int phys;
 double mean;
};


static struct student data[]={
 {"Tuan", 82, 72, 58, 0.0},
 {"Nam", 77, 82, 79, 0.0}, 
 {"Khanh", 52, 62, 39, 0.0}, 
 {"Phuong", 61, 82, 88, 0.0}
}; 

float avg_mean(struct student sv){
    float mean ;
    mean = (sv.eng + sv.math + sv.phys )/(3.0);
    return mean;
}

void rank_student(struct student sv){

    float mean;
    mean = avg_mean(sv);
    if(mean >= 90 && mean <= 100){
        printf("Rank: S\n");
    }
    else if(mean >= 80 && mean < 90){
        printf("Rank: A\n");

    }
    else if(mean >= 70 && mean < 80){
         printf("Rank: B\n");
    }
    else if(mean >= 60 && mean < 70){
         printf("Rank: C\n");
    }
    else {
         printf("Rank: D\n");
    }

}

void print_mean_student(){
    printf("Ket qua trung binh cua sinh vien la:\n");
    printf("=========================\n");

    for( int i = 0; i < 4 ; i++){
       printf("Ten: %s\n" ,data[i].name);
       printf("Diem tieng Anh: %d\n" ,data[i].eng);
       printf("Diem Toan: %d\n" ,data[i].math);
       printf("Diem Vat Ly: %d\n" ,data[i].phys);
       printf("Diem trung binh: %f\n" ,data[i].mean);
       rank_student(data[i]);
       printf("=========================\n");
    }

}

int main()
{
    for( int i = 0; i < 4 ; i++){
        data[i].mean = avg_mean(data[i]);
    }
    print_mean_student();
    return 0;
}