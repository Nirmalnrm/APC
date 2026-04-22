#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,Dlist **headRBack,Dlist **tailRBack)
{
	/* Definition goes here */
	Dlist *temp1;
	Dlist *temp2;

	temp1=*head1;
	temp2=*head2;

	long int count=0;
	int len1 = 0,len2 = 0; 
	int flag = 0;
	while(1)
	{
		while(temp1!=NULL) //traverse to find the length of divident
		{
			temp1=temp1->next;
			len1++;
		}
		while(temp2!=NULL) //traverse to find the length of divisor
		{
			temp2=temp2->next;
			len2++;
		}

		if(len1 < len2) // check it division is possible
		{
			flag=0;
			break;
		}
		else if(len1 > len2 || flag==1) 
		{
			subtraction(head1,tail1,head2,tail2,headR,tailR);
			count++;
			remove_zero(headR,tailR);
			delete_list(head1,tail1);

			*head1 = *headR; // new dividend
			*tail1 = *tailR;

			int r = check_big_num(head1,tail1,head2,tail2); //check with new divident
			if(r == 0)
			{
				break;
			}

			*headR = NULL;
			*tailR = NULL;
		}
		else if(len1 == len2)
		{
			flag = check_big_num(head1,tail1,head2,tail2);
			if(flag == 0)
			{
				break;
			}
			else if(flag == len2)
			{
				count = 1;
				break;
			}
		}
	}
	return count; // returning the quotient
}


