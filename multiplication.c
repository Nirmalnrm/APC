#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2, Dlist **headRBack, Dlist **tailRBack)
{

	Dlist *temp1;
	Dlist *temp2;

	temp1=*tail1;
	temp2=*tail2;

	int prod=0,carry=0,num1,num2;
	int data;
	int count=0;

	while(temp2!=NULL) 
	{
		num1=num2=0;
		carry=0;
		if(temp2!=NULL)
		{
			num2 = temp2 -> data;
		}
		for(int i=0;i<count;i++) //Insert Leading Zeros for Shift
		{
			insert_first(headR2, tailR2, 0);
		}
		while(temp1!=NULL)
		{
			if(temp1!=NULL)
			{
				num1 = temp1 -> data;
			}

			prod = ( num1 * num2 ) + carry; //multiplication
			data = prod % 10;
			carry = prod / 10;

			if(count) //Insert Product into Result List
			{
				insert_first(headR2, tailR2, data);
			}
			else
			{
				insert_first(headR1, tailR1, data);
			}

			if(temp1!=NULL)
			{
				temp1 = temp1 -> prev;
			}
		}

		if (count>0) // Adding up for result
		{	
			addition(headR1,tailR1,headR2,tailR2,headRBack,tailRBack);
			delete_list(headR1 , tailR1);
			delete_list(headR2 , tailR2);

			*headR1 = *headRBack; 
			*tailR1 = *tailRBack;

			*headRBack = NULL;
			*tailRBack = NULL;
		}

		if(temp2!=NULL)
		{
			temp2=temp2 -> prev;
		}
		count++;
		temp1 = *tail1;

		if(carry!=0) // If there is a carry left, insert it at the front 
		{
			insert_first(headR1, tailR1, carry);
		}
	}
	
}
