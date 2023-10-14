#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct schools{
    char school_name[25];
    struct schools *next;
    struct students *student;
};

struct students{
    char student_name[25];
    struct students *next;
};

struct schools *create_school(struct schools *master, char school_name[25]);

void create_student(struct schools *master, char school_name[25], char student_name[25]);

void print_schools(struct schools *master);

void print_students(struct schools *master, char school_name[25]);

struct schools *remove_school(struct schools *master, char school_name[25]);

void remove_student(struct schools *master, char student_name[25]);

void clean_up(struct schools *master);

int main(int argc, char* argv[]){
    char command[4];
    char name1[25];
    char name2[25];
    struct schools *master = NULL;

    scanf("%s", command);

    while(strcmp(command,"q:") != 0){
        if(strcmp(command, "s:") == 0){
            scanf("%s", name1);
            master = create_school(master, name1);
        }else if(strcmp(command, "c:") == 0){
            scanf("%s%s", name1, name2);
            create_student(master, name1, name2);
        }else if(strcmp(command, "ps:") == 0){
            print_schools(master);
        }else if(strcmp(command, "pc:") == 0){
            scanf("%s", name1);
            print_students(master, name1);
        }else if(strcmp(command, "rs:") == 0){
            scanf("%s", name1);
            master = remove_school(master, name1);
        }else if(strcmp(command, "rc:") == 0){
            scanf("%s", name1);
            remove_student(master, name1);
        }else{
            printf("this is not a valid command\n");
        }
        scanf("%s", command);
    }
    clean_up(master);
    return 0;
}



struct schools *create_school(struct schools *master, char school_name[25]){
    if(master == NULL){
        master = malloc(sizeof(struct schools));
        strcpy(master->school_name, school_name);
        master->next = NULL;
    }else{
        if(master->school_name[0] > school_name[0]){
            struct schools *tmp = malloc(sizeof(struct schools));
            strcpy(tmp->school_name, school_name);
            tmp->next = master;
            master = tmp;
        }else if(master->next == NULL){
            master->next = malloc(sizeof(struct schools));
            strcpy(master->next->school_name, school_name);
            master->next->next = NULL;
        }else{
            struct schools *walker = master;
            struct schools *walker2 = master->next;
            while(walker2->school_name[0] < school_name[0]){
                if(walker2->next == NULL){
                    walker2->next = malloc(sizeof(struct schools));
                    strcpy(walker2->next->school_name, school_name);
                    walker2->next->next = NULL;
                    break;
                }
                walker = walker2;
                walker2 = walker2->next;
                
            }
            walker->next = malloc(sizeof(struct schools));
            walker = walker->next;
            strcpy(walker->school_name,school_name);
            walker->next = walker2;
        }  
    }
    return master;
};



void create_student(struct schools *master, char school_name[25], char student_name[25]){
    while(strcmp(master->school_name, school_name) != 0){
        if(master->next == NULL){
            printf("There is no matching school\n");
            break;
        }//checking for matching school.
        master = master->next;
    }
    if(strcmp(master->school_name, school_name) == 0){
        if(master->student == NULL){
            master->student = malloc(sizeof(struct students));
            strcpy(master->student->student_name, student_name);
            master->student->next = NULL;
        }else{
            if(master->student->student_name[0] > student_name[0]){
                struct students *tmp = malloc(sizeof(struct students));
                strcpy(tmp->student_name, student_name);
                tmp->next = master->student;
                master->student = tmp;
            }else if(master->student->next == NULL){
                master->student->next = malloc(sizeof(struct students));
                strcpy(master->student->next->student_name, student_name);
                master->student->next->next = NULL;
            }else{
                struct students *walker = master->student;
                struct students *walker2 = master->student->next;
                while(walker2->student_name[0] < student_name[0]){
                    if(walker2->next == NULL){
                        walker2->next = malloc(sizeof(struct students));
                        strcpy(walker2->next->student_name, student_name);
                        walker2->next->next = NULL;
                        walker2 = walker2->next;
                        break;
                    }else{
                        walker = walker2;
                        walker2 = walker2->next;
                    }
                }
                if(strcmp(walker2->student_name, student_name) != 0){
                    struct students *tmp = malloc(sizeof(struct students));
                    strcpy(tmp->student_name, student_name);
                    tmp->next = walker2;
                    walker->next = tmp;
                }
            }
        }
    }
};



void print_schools(struct schools *master){
    while(master != NULL){
        printf("%s ", master->school_name);
        master = master->next;
    }
    printf("\n");
};



void print_students(struct schools *master, char school_name[25]){
    while(master != NULL){
        if(strcmp(master->school_name, school_name) == 0){
            struct students *walker = master->student;
            printf("%s: ", master->school_name);
            while(walker != NULL){
                printf("%s ", walker->student_name);
                walker = walker->next;
            }
            printf("\n");
        }
        master = master->next;
    }
};



struct schools *remove_school(struct schools *master, char school_name[25]){
    if(master == NULL){
        printf("No Schools Remaining\n");
    }else if(strcmp(master->school_name, school_name) == 0){
        struct schools *tmp = master;
        master = master->next;
        free(tmp);
    }else{
        struct schools *walker1 = master;
        struct schools *walker2 = master->next;

        while(strcmp(walker2->school_name, school_name) != 0){
            walker1 = walker1->next;
            walker2 = walker2->next;
        }
        walker1->next = walker2->next;
        free(walker2);
    }
    return master;
};



void remove_student(struct schools *master, char student_name[25]){
    if(master == NULL){
        printf("No Schools Remaining\n");
    }else{
        while(master != NULL){
            if(master->student == NULL){
            }else if(strcmp(master->student->student_name, student_name) == 0){
                if(master->student->next == NULL){
                    free(master->student);
                    master->student = NULL;
                }else{
                    struct students *tmp = master->student;
                    master->student = master->student->next;
                    free(tmp);
                }
            }else if(master->student->next == NULL){
            }else if(strcmp(master->student->next->student_name, student_name) == 0){
                if(master->student->next->next == NULL){
                    free(master->student->next);
                    master->student->next = NULL;
                }else{
                    struct students *tmp = master->student->next;
                    master->student->next = master->student->next->next;
                    free(tmp);
                }
            }else{
                struct students *walker = master->student;
                struct students *walker2 = master->student->next;
                while(walker2->next != NULL){
                    if(strcmp(walker2->student_name, student_name) == 0){
                        struct students *tmp = walker2;
                        walker->next = walker2->next;
                        free(tmp);
                    }
                    walker = walker2;
                    walker2 = walker2->next;
                }
            }
            master = master->next;
        }
    }
};



void clean_up(struct schools *master){
    struct schools *walkers = master;
    while(master != NULL){
        struct students *walker = master->student;
        struct students *walker2 = master->student;
        while(walker != NULL){
            walker = walker->next;
            free(walker2);
            walker2 = walker;
        }
        master = master->next;
        free(walkers);
        walkers = master;
    }
    printf("Linked list cleaned up!\n");
};