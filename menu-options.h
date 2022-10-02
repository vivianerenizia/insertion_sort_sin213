/*
This library contains the menus used for the selection of algorithms, input sizes and scenarios.
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


void algorithm_selection(){
    system("cls");
    int choice = 0;
    do{
        printf("\n \t==============================");
        printf("\n \t==== SELECT THE ALGORITHM ====");
        printf("\n \t==============================");
        printf("\n \t==== 1 - Insertion Sort   ====");
        printf("\n \t==== 0 - Exit             ====");
        printf("\n \t==============================");
        printf("\n \tEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case  1:
                input_size();
                break;
            case  0:
                printf("\n \tCode execution has ended. Goodbye! :)\n\n");
                exit(1);
                break;
            default:
                printf("\n \tWrong Choice. Enter again!\n");
                break;
        }
    }while(choice != 0);
}


int input_size(){
    system("cls");
    int choice = 0;
    do{
        printf("\n \t===========================================");
        printf("\n \t====         SELECT INPUT SIZE         ====");
        printf("\n \t===========================================");
        printf("\n \t==== 1 - 10                            ====");
        printf("\n \t==== 2 - 100                           ====");
        printf("\n \t==== 3 - 1.000                         ====");
        printf("\n \t==== 4 - 10.000                        ====");
        printf("\n \t==== 5 - 100.000                       ====");
        printf("\n \t==== 6 - 1.000.000                     ====");
        printf("\n \t==== 7 - Return to Algorithm Selection ====");
        printf("\n \t==== 0 - Exit                          ====");
        printf("\n \t===========================================");
        printf("\n \tEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case  1:
                scenario(10);
                break;
            case  2:
                scenario(100);
                break;
            case  3:
                scenario(1000);
                break;
            case  4:
                scenario(10000);
                break;
            case  5:
                scenario(100000);
                break;
            case  6:
                scenario(1000000);
                break;
            case  7:
                algorithm_selection;
                break;
            case  0:
                printf("\n \tCode execution has ended. Goodbye! :)\n\n");
                exit(1);
                break;
            default:
                printf("\n \tWrong Choice. Enter again!\n");
                break;
        }
    }while(choice != 0);
}


int scenario(int input){
    system("cls");
    int choice = 0, size_sequence=input;
    do{
        printf("\n \t============================================");
        printf("\n \t====         SELECT THE SCENARIO        ====");
        printf("\n \t============================================");
        printf("\n \t==== 1 - Ascending order                ====");
        printf("\n \t==== 2 - Descending order               ====");
        printf("\n \t==== 3 - Random order                   ====");
        printf("\n \t==== 4 - All scenarios                  ====");
        printf("\n \t==== 5 - Return to Input Size Selection ====");
        printf("\n \t==== 0 - Exit                           ====");
        printf("\n \t============================================");
        printf("\n \tEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case  1:
                system("cls");
                ascending(size_sequence, choice);
                break;
            case  2:
                system("cls");
                descending(size_sequence, choice);
                break;
            case  3:
                system("cls");
                random(size_sequence, choice);
                break;
            case  4:
                system("cls");
                ascending(size_sequence, 1);
                descending(size_sequence, 2);
                random(size_sequence, 3);
                break;
            case  5:
                input_size();
                break;
            case  0:
                printf("\n \tCode execution has ended. Goodbye! :)\n\n");
                exit(1);
                break;
            default:
                printf("\n \tWrong Choice. Enter again!\n");
                break;
        }
    }while(choice != 0);
}
