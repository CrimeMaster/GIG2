//
//  main.c
//  Menu
//
//  Created by Gladwin Tirkey on 1/27/19.
//  Copyright © 2019 Gladwin Tirkey. All rights reserved.
//

#include <stdio.h>
#define size 100
int array[size];
int n;
void create();
void display();
void insert(int pos, int value);
void delete(int pos);
int main() {
    /*
     Develop and Implement a menu drivemn program in C for the followoing Array operations
     a) Creating an array of N integer element
     b) Displaying an array
     c) Inserting an array
     d) Deleting an array
     */
    int input, pos, value;
  
    printf("menu\n");
    printf("\t [1] Create \n");
    printf("\t [2] Display \n");
    printf("\t [3] Insert \n");
    printf("\t [4] Delete \n");
    printf("\t [0] Exit \n");
    printf("input: ");
    scanf("%d", &input);
    if(input == 1){
        create();
    }
    else if(input == 2){
        display();
    }
    else if(input == 3){
        printf("At what position you want the element inserted?\n");
        scanf("%d", &pos);
        printf("What value ?\n");
        scanf("%d", &value);
        insert(pos, value);
    }
    else if(input == 4){
        printf("At what position you want to delete the element ?\n");
        scanf("%d", &pos);
        delete(pos);
    }else if(input == 0)
    
    return 0;
}
void create(){
    int i, len;
    printf("How many elements ?\n");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        printf("Element no %d: ", i);
        scanf("%d",&array[i]);
    }
   
    printf("\n");
    main();
}
void display(){
    int i;
    printf("Display Elements\n");
    for(i = 0 ; i < n ; i++){
        printf("Element no %d: %d\n",i ,array[i]);
    }
    main();
}
void insert(int pos, int value){
    array[pos] = value;
    main();
}
void delete(int pos){
    array[pos] = 0;
    main();
}

