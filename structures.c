#include <stdio.h>
#include <string.h>

struct students{
    char first[15];
    char last[15];
    float gpa;
    char email[100];
    int num_classes;
    char classes[10][20];
};

float get_grade_point(char grade) {
    if(grade == 'A') return 4.0;
    if(grade == 'B') return 3.0;
    if(grade == 'C') return 2.0;
    if(grade == 'D') return 1.0;
    if(grade == 'F') return 0.0;

    return 0.0;
}

void print_student(struct students student){
    printf("First name: %s\n", student.first);
    printf("Last name: %s\n", student.last);
    printf("%f\n", student.gpa);
    printf("Classes:\n");
    for (int i = 0; i < num_classes; i++){
        printf("    %s\n", student.classes[i]);
    }

}

int main(int argc, char *argv[]){
    File *input;
    input = fopen(arg[1], "r");

    struct students student1;

    //reading in student info.
    fscanf(input, "%s", student1.first)
    fscanf(input, "%s", student1.last)
    int num_classes;
    fscanf(input, "%d", &num_classes);
    for (int i = 0; i < num_classes; i++){
        fscanf(input, "%s", student1.classes[i]);
    }

    

    float gpa_sum = 0.0;
    int previous_classes;
    fscanf(input, "%d", &previous_classes);
    for(int i = 0; i < previous_classes; i++){
        char class_grade;
        fscanf(input, "%*s %c", &class_grade)   //* in between % and s makes it so you don't have to save data to a variable for fscanf.

        gpa_sum += get_grade_point(class_grade);
    }

    //Fill in student's email.

    strcat(student1.email, student1.first);
    strcat(student1.email, ".");
    strcat(student1.email, student1.last);
    strcat(student1.email, "@gmail.com");



    student1.gpa = gpa_sum / previous_classes;



    //printing stududent info.
    print_student(student1);
    fclose(arg[1]);

    return 0;
}


