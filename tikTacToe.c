#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int arr[3][3]);

int main(){
    srand(time(NULL));
    int available = 9;
    int arr[3][3];
    int col;
    char row;
    int sum = 0;
    int diag1;
    int diag2;
    int compcol, comprow, c;
    int z;

    printf("Welcome: rows are alphabetical, columnns are numerical.\n");

    //filling array with 0s.
    for(int a = 0; a < 3; a++){ 
        for(int b = 0; b < 3; b++){
            arr[a][b] = 0;
        }
    }

    //game of TikTacToe.
    while(available > 0){
        z = 0;
        while(z == 0){
            printf("Please select a row and column:\n");
            scanf("%c%d", &row, &col);
            col--;

            //putting user input into array.
            switch(row){
                case 'a':
                    if(arr[col][0] == 0){
                        arr[col][0] = 1;
                        z = 1;
                    }
                    else{
                        printf("This space is taken or input is invalid.\n");       
                    }
                    break;
                case 'b':
                    if(arr[col][1] == 0){
                        arr[col][1] = 1;
                        z = 1;
                    }
                    else{
                        printf("This space is taken or input is invalid.\n");
                    }
                    break;
                case 'c':
                    if(arr[col][2] == 0){
                        arr[col][2] = 1;
                        z = 1;
                    }
                    else{
                        printf("This space is taken.\n");
                    }
                    break;
            }
        }
        print_matrix(arr);

        //checking for solutions.
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                sum = sum + arr[a][b];
            }
            if(sum == 3){
                printf("The user has won!\n");
                return 0;
            }
            sum = 0;
        }
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                sum = sum + arr[b][a];
            }
            if(sum == 3){
                printf("The user has won!\n");
                return 0;
            }
            sum = 0;
        }        
        diag1 = arr[0][0] + arr[1][1] + arr[2][2];
        diag2 = arr[2][0] + arr[1][1] + arr[0][2];
        if(diag1 == 3){
            printf("The user has won!\n");
            return 0;
        }
        else if(diag2 == 3){
            printf("The user has won!\n");
            return 0;
        }

        //updating game turn and checking for tie.
        available--;
        if(available == 0){
            printf("The game is a tie.\n");
            break;
        }

        //comp turn.
        compcol = 0;
        comprow = 0;
        c = 1;
        while(c == 1){
            compcol = rand() % 3;
            comprow = rand() % 3;
            if(arr[compcol][comprow] == 0){
                arr[compcol][comprow] = -1;
                c = 0;
            }
        }
        print_matrix(arr);

        //checking for solutions.
        diag1 = arr[0][0] + arr[1][1] + arr[2][2];
        diag2 = arr[2][0] + arr[1][1] + arr[0][2];
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                sum = sum + arr[a][b];
            }
            if(sum == -3){
                printf("The computer has won!\n");
                return 0;
            }
            sum = 0;         
        }
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                sum = sum + arr[b][a];
            }
            if(sum == -3){
                printf("The computer has won!\n");
                return 0;
            }
            sum = 0;
        }  
        if(diag1 == -3){
            printf("The computer has won!\n");
            return 0;
        }
        else if(diag2 == -3){
            printf("The computer has won!\n");
            return 0;
        }

        available--;
    }
    return 0;
}

void print_matrix(int arr[3][3]){
    int a, b;
    for(a = 0; a < 3; a++){
        for(b = 0; b < 3; b++){
            if (arr[a][b] == 1){
                printf("O ");
            }
            else if (arr[a][b] == -1){
                printf("X ");
            }
            else{
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}