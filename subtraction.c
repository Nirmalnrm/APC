#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */

	Dlist *temp1=malloc(sizeof(Dlist));
	Dlist *temp2=malloc(sizeof(Dlist));

	temp1=*tail1;
	temp2=*tail2;

	int borrow=0,sub=0,num1,num2;
	int data;

	while(temp1!=NULL || temp2!=NULL) // traverse untill temp1 and temp2 is NULL
	{
		num1=num2=0;
		if(temp1!=NULL)
		{
			num1 = temp1 -> data;
		}

		if(temp2!=NULL)
		{
			num2 = temp2 -> data;
		}

		if(num1 - borrow < num2) // Borrow from the next digits
		{
			num1 = num1 + 10;
			sub = num1 - num2 - borrow;
			borrow = 1;
		}
		else
		{
			sub = num1 - num2 - borrow;
			borrow = 0;
		}

		insert_first(headR, tailR, sub); //Insert the digit at the beginning of the result list

		if(temp1!=NULL)
		{
			temp1 = temp1 -> prev;
		}
		if(temp2!=NULL)
		{
			temp2=temp2 -> prev;
		}

	}	
}
