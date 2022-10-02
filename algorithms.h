/*
This library stores the algorithms that will be used as works throughout the course.
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


int *insertion_sort(int A[], int n){ // Insertion Sort Algorithm: Implementation in Class
    /*
    Insertion Sort Function:
    This algorithm uses a vector of size n,
    where n is the number of elements of Sequence [A].
    */
    int i, j, key; // Declaration of variables

    for(j=1; j<n; j++){
        /*
        In the algorithm implemented in Class, the J started at 2,
        however, in this implementation we will start the J at 1,
        this is because our vector starts from 0,
        and not from 1 like the one implemented in class.
        */
        key = A[j]; // The numeric value that is at position j in vector A is set as the value of the key variable
        //Insert A[j] in the ordered sequence A[1, ..., j¹]
        i = j-1; // The value of j variable subtracting 1 (j-1), is set as the value of the variable i
        while(i>-1 && A[i]>key){
            /*
            Since we changed the FOR rule,
            we also need to change the WHILE rule,
            so the i has to be > -1 and not > 0.
            If it continued to be > 0, the algorithm
            would not enter the while as often as it should.
            */
            A[i+1] = A[i]; //The vector A in the position of i+1, receives the value that is in the position of i
            i = i-1; // i is decremented by 1 (i-1)
        } //end of WHILE
        A[i+1] = key; // The vector A at the position i+1, receives the value of the key variable
    } //end of FOR
    return A;
}




