#include "apc.h"

int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
	
	Dlist *temp1=malloc(sizeof(Dlist)); //Declare the temp Dlist
	Dlist *temp2=malloc(sizeof(Dlist));

	temp1=*tail1;
	temp2=*tail2;

	int carry=0,sum=0,num1,num2;
	int data,flag=0;

	while(temp1!=NULL || temp2!=NULL)
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

		sum = num1 + num2 + carry; // SUM
		data = sum % 10;
		carry = sum/10;

		insert_first(headR, tailR, data); //Insert the digit at the beginning of the result list

		if(temp1!=NULL)
		{
			temp1 = temp1 -> prev;
		}
		if(temp2!=NULL)
		{
			temp2=temp2 -> prev;
		}

	}
	if(carry!=0)  // If there is a carry left, insert it at the front 
	{
		insert_first(headR, tailR, carry);
	}
}
