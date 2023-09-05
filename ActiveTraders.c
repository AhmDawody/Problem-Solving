#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char** ActiveTraders(char** ,int );
int cmp(const void* a, const void* b){
    return strcmp(*(char**) a, *(char**) b);
}

int main(){
    int n = 23, i;
    char *names[] = {"Ahmed", "Ali", "Ahmed", "Mona", "Ahmed", "Mohamed", "Ibrahim", "Ali", "Ali", "Ali", "Ahmed", "Ahmed", "Ahmed", "Ali", "Ahmed", "Ahmed",
    "Ahmed", "Ahmed", "Ahmed", "Ahmed", "Ahmed", "Ahmed", "Ahmed"};
    char** sorted = ActiveTraders(names, n);
    for(i=0; sorted[i]!= NULL; i++){
        printf("%s\n", sorted[i]);
    }
    return 0;
}

char** ActiveTraders(char** names, int n){
    int i, c = 0;
    qsort(names, n, sizeof(char*), cmp);

    float* count = (float*)malloc(n * sizeof(float));
    char** names_one_time = (char**)malloc(n * sizeof(char*));
    for(i=0; i<n; i++){
        names_one_time[i] = malloc(20*sizeof(char));
        count[i] = 0;
    }

    names_one_time[c] = names[0];

    for(i=0; i<n; i++){
        if(strcmp(names[i], names_one_time[c]) == 0){
            count[c]++;
        }
        else{
            c++;
            names_one_time[c] = names[i];
            count[c]++;
        }
    }

    float f = n * (.05);
    for(i=n-1; i>=0; i--){
        if(count[i]<f){
            names_one_time[i] = NULL;
            free(names_one_time[i]);
        }
    }
    free(count);
    return names_one_time;
}