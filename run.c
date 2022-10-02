/*
This code is the execution code of the application, where the main calls are made.
Subject: Algorithm Design (SIN 213 - Projeto de Algoritmos)
Class: 2
Teacher: Pedro Moises de Sousa
Teacher email: pedromoises@ufv.br
Student: Viviane Renizia Mendes Silva
Registration: ER05209
Email: viviane.mendes@ufv.br
Year: 2022
Semester: 2022-2
*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>
#include<time.h>
#include "algorithms.h"
#include "menu-options.h"


void save_spent_time(int scenario, int size_sequence, double spent_time){
	printf("\n Cenario in save spent time: %d\n", scenario);
    int i, scenario_choice=scenario, size_entries=size_sequence;
    char path[] = "C://PA//1. Insertion Sort//Time Spent//";
    char straux[15];
    FILE *f;

    switch(scenario_choice){
        case  1:
            strcat(path, "Ascending//time_spent_ascending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        case  2:
            strcat(path, "Descending//time_spent_descending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s", path);
            f = fopen(path, "w");
            break;
        case  3:
            strcat(path, "Random//time_spent_random_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        default:
            printf("\n \tScenario does not exist!\n");
            break;
    }

    if (f == NULL){
        printf("Erro na abertura!\n");
        exit(1); // aborta o programa
    }
    fprintf(f, "%d\n", size_sequence);
    fprintf(f, "Time spent %f\n", spent_time);

    fclose(f);
}


void save_outputs(int scenario, int size_sequence, int *sequence){
	printf("\n Cenario in save outputs: %d\n", scenario);
    int i, scenario_choice=scenario, size_entries=size_sequence;
    char path[] = "C://PA//1. Insertion Sort//Outputs//";
    char straux[15];
    FILE *f;

    switch(scenario_choice){
        case  1:
            strcat(path, "Ascending//outputs_ascending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        case  2:
            strcat(path, "Descending//outputs_descending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s", path);
            f = fopen(path, "w");
            break;
        case  3:
            strcat(path, "Random//outputs_random_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        default:
            printf("\n \tScenario does not exist!\n");
            break;
    }

    if (f == NULL){
        printf("Erro na abertura!\n");
        exit(1); // aborta o programa
    }
    fprintf(f, "%d\n", size_sequence);
    for (i = 0; i < size_sequence; i++){
        fprintf(f, "%d\n", sequence[i]);
    }

    fclose(f);
}


void save_entries(int scenario, int size_sequence, int *sequence){
	printf("\n Cenario in save entries: %d\n", scenario);
    int i, scenario_choice=scenario, size_entries=size_sequence;
    char path[] = "C://PA//1. Insertion Sort//Entries//";
    char straux[15];
    FILE *f;

    switch(scenario_choice){
        case  1:
            strcat(path, "Ascending//entries_ascending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        case  2:
            strcat(path, "Descending//entries_descending_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s", path);
            f = fopen(path, "w");
            break;
        case  3:
            strcat(path, "Random//entries_random_");
            strcat(path, itoa(size_sequence, straux, 10));
            strcat(path, ".txt");
            printf("%s\n", path);
            f = fopen(path, "w");
            break;
        default:
            printf("\n \tScenario does not exist!\n");
            break;
    }

    if (f == NULL){
        printf("Erro na abertura!\n");
        exit(1); // aborta o programa
    }
    fprintf(f, "%d\n", size_sequence);
    for (i = 0; i < size_sequence; i++){
        fprintf(f, "%d\n", sequence[i]);
    }

    fclose(f);
}


int ascending(int size_sequence, int scenario){
    int i=0, n=size_sequence;
    int *v=NULL, *ordered_sequence=NULL;
    float start_t, end_t;
    double time_spent;

    v = (int *)malloc(n * sizeof(int));
    if (v == NULL){
        printf("Insufficient space to allocate an array of size %d\n", n);
        system("pause");
        exit(1);
    }
    for (i=0; i<n; i++){
         v[i] = i;
    }
	printf("\n Cenario atual: %d\n", scenario);
    save_entries(scenario, n, v);
    start_t = clock();
    ordered_sequence = insertion_sort(v, n);
    end_t = clock();
    time_spent = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
    save_spent_time(scenario, n, time_spent);
	printf("\n Cenario atual: %d\n", scenario);
    save_outputs(scenario, n, ordered_sequence);

    free(v);
}


int descending(int size_sequence, int scenario){
    int i=0, j=0, n=size_sequence;
    int *v=NULL, *ordered_sequence=NULL;
    float start_t, end_t;
    double time_spent;

    v = (int *)malloc(n * sizeof(int));
    if (v == NULL){
        printf("Insufficient space to allocate an array of size %d\n", n);
        system("pause");
        exit(1);
    }
    for (i=n; i>= 0; i--){
         v[j] = i;
         j=j+1;
    }

    save_entries(scenario, n, v);
    start_t = clock();
    ordered_sequence = insertion_sort(v, n);
    end_t = clock();
    time_spent = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
    save_spent_time(scenario, n, time_spent);
    save_outputs(scenario, n, ordered_sequence);

    free(v);
}


int random(int size_sequence, int scenario){
    int i=0, n=size_sequence;
    int *v=NULL, *ordered_sequence=NULL;
    float start_t, end_t;
    double time_spent;

    v = (int *)malloc(n * sizeof(int));
    if (v == NULL){
        printf("Insufficient space to allocate an array of size %d\n", n);
        system("pause");
        exit(1);
    }
    srand(time(NULL));
    for (i=0; i<n; i++){
         v[i] = rand() % n + 1;
    }

    save_entries(scenario, n, v);
    start_t = clock();
    ordered_sequence = insertion_sort(v, n);
    end_t = clock();
    time_spent = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
    printf("\nTime spent: %f\n", time_spent);
    save_spent_time(scenario, n, time_spent);
    save_outputs(scenario, n, ordered_sequence);

    free(v);
}


int main(){
    // Se estiver utilizando o vscode, pode ser necessário
    // digitar "chcp 65001" no terminal antes de executar
    // o código, para que o setlocale reconheça o idioma pt-BR.
    setlocale(LC_ALL, "pt-BR");
    algorithm_selection();
    system("pause");
    return 0;
}
