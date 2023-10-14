#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stores {
    char storeName[20];
    char address[50];
    int totalProducts;
    char productNames[20][20];
    int productCalories[20];
};

int main(int argc, char *argv[]){
    int storeCount;
    char userStr[20];
    FILE *input;
    
    input = fopen(argv[1], "r");

    fscanf(input, "%d", &storeCount);

    struct stores *store = malloc(sizeof(struct stores) * storeCount);

    for(int i = 0; i < storeCount; i++){
        fscanf(input, "%s %s %d", store[i].storeName, store[i].address, &store[i].totalProducts);
        int productCount = store[i].totalProducts;
        for(int n = 0; n < productCount; n++){
            fscanf(input, "%s %d", store[i].productNames[n], store[i].productCalories);
        }
    }

    scanf("%s", userStr);

    for(int i = 0; i < storeCount; i++){
        int productCount = store[i].totalProducts;
        for(int n = 0; n < productCount; n++){
            if(strcmp(userStr, store[i].productNames[n]) == 0){
                printf("%s\n", store[i].storeName);
            }
        }
    }

    free(store);
    fclose(input);
    return 0;
}