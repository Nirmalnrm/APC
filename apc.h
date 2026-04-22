#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;


/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2, Dlist **headRBack, Dlist **tailRBack);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,Dlist **headRBack,Dlist **tailRBack);

/*Read and validate operands*/
int read_and_validate(int argc,char *argv[]);

/*Checking operands are numbers or not*/
int check_nums(char *num1,char *num2);

/*Store largest number in the first list*/
int store_large_num(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Getting character by character from the string(CLA) and storing integer value to the list*/
void get_one_data(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2);

/*Inserting data at last position*/
int insert_last(Dlist **head, Dlist **tail, int data);

/*Inserting data at first position*/
int insert_first(Dlist **head, Dlist **tail, int data);

/*Printing the linked list*/
void print_list(Dlist *headR);

/*Removing first zeroes upto the non zero value*/
int remove_zero(Dlist **headR,Dlist **tailR);

/*Deleting Linked list*/
int delete_list(Dlist **head, Dlist **tail);

/*Checking biggest number between divisor and dividend during division(continues subtraction)*/
int check_big_num(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

/*Checking the signs of the operands*/
char* check_sign(char *num1,char*num2);

#endif
