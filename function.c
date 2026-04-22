#include "apc.h"

int read_and_validate(int argc,char *argv[])
{
    if(argc!=4) // check the argv
    {
        printf("Error: Less no.of arguments\n");
        return FAILURE;
    }
    if(check_nums(argv[1],argv[3])==SUCCESS) // check the numbers
    {       
        return SUCCESS;
    }
    else
    {
        printf("ERROR: NOT DIGITS\n");
        return FAILURE;
    }
}


int check_nums(char *num1,char *num2)
{
    int i=0;
    if(num1[i]=='+' || num1[i]=='-')
    {
        i++;    
    }
    while(num1[i]!='\0')
    {
        if(isdigit(num1[i])==0) // check if argv[i] is number 
        {
            return FAILURE;
        }
        i++;
    }
    i=0;
    if(num2[i]=='+' || num2[i]=='-')
    {
        i++;    
    }
    while(num2[i]!='\0')
    {
        if(isdigit(num2[i])==0) 
        {
            return FAILURE;
        }  
        i++;     
    }

    return SUCCESS;
}


void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    get_one_data(head1,tail1,head2,tail2,argv[1],argv[3]);
}


void get_one_data(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2)
{
    int i=0;  
    if(num1[i]=='-' || num1[i]=='+')
    {    
        i++;
    }
    while(num1[i]!='\0')
    {
        int data1=num1[i]-48; // Convert character to integer
        insert_last(head1,tail1,data1);
        i++;
    }
    i=0;
    if(num2[i]=='-' || num2[i]=='+')
    {
        i++;    //skip the sign if present
    }
    while(num2[i]!='\0')
    {
        int data2=num2[i]-48;
        insert_last(head2,tail2,data2);
        i++;
    }

}


int store_large_num(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    int flag=0;
    int num1 = abs(atoi(argv[1]));
    int num2 = abs(atoi(argv[3]));
    if(num1 > num2)
    {
       flag=0;
        get_one_data(head1,tail1,head2,tail2,argv[1],argv[3]);
    }

    else if(num1 < num2)
    {
        flag=1;
        get_one_data(head1,tail1,head2,tail2,argv[3],argv[1]);
    }
    else if(num1 == num2)
    {
        flag = 2;
        get_one_data(head1,tail1,head2,tail2,argv[1],argv[3]);
    }
    return flag;
}


int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;  //Memory allocation failed
    }
    new->data=data;
    new->prev=new->next=NULL;
    if(*head == NULL)
    {
        *head = *tail =new;
        return SUCCESS;
    }
    else
    {
        new->prev=*tail; // link the new node to the current tail
        (*tail) -> next= new; // Link current tail to the new node
        *tail = new; // Update tail pointer to the new node
        return SUCCESS; 
    }
}


int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE; //Memory allocation failed
    }
    new->data=data; //pass the data to new node
    new->prev=NULL; // make the prev of new node to NULL
    new->next=*head; // update the new node to header pointer
    if(*head == NULL)
    {
        *head = *tail =new;
    }
    else
    {
        (*head) -> prev= new;
        *head = new;
    }  
        return SUCCESS; 
}


void print_list(Dlist *headR)
{
	/* Cheking the list is empty or not */
	if (headR == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        Dlist *temp=headR;
	    while (temp!=NULL)		
	    {
		    printf("%d", temp -> data);
		    temp = temp -> next;
	    }
    	printf("\n");
    }
}

int remove_zero(Dlist **headR,Dlist **tailR)
{
    Dlist *temp = *headR;
    while(temp->next!=NULL) // traverse to find the zero
    {
        if(temp -> data == 0)
        {
            (*headR) = (*headR)->next;
            (*headR) -> prev = NULL;
            free(temp);
        }
        else if(temp -> data != 0)
        {
            return 0;
        }
        temp=(*headR); 
    }
}


int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    Dlist *temp = *head;
    while(temp!=NULL)
    {
        Dlist *nextnode = temp->next;
        free(temp); // delete the temp list
        temp = nextnode;
    }
    *head=NULL;
    *tail=NULL;

    return SUCCESS;
}


int check_big_num(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    Dlist *temp1 = *head1;
	Dlist *temp2 = *head2;

    int flag = 0;
    int len1=0,len2=0;

    while(temp1 != NULL) // Count digits in first number
    {
        temp1=temp1->next;
        len1++;
    }
    while(temp2!=NULL) // Count digits in second number
    {
        temp2=temp2->next;
        len2++;
    }

    temp1=*head1;
	temp2=*head2;

    if(len1 > len2)
    {
        return 1; // First number is greater
    }

    if(len1 < len2)
    {
        return 0;  // Second number is greater
    }
    if(len1 == len2)
    {
        for(int i=0;i<len2;i++)
	    {
            if(temp1->data > temp2->data)
            {
                return 1; // First number is larger
            }
            else if(temp1->data == temp2->data)
            {
                flag++;
                if(temp1 != NULL)
                {
                    temp1 = temp1->next;
                }
                if(temp2 != NULL)
                {
                    temp2 = temp2->next;
                }
            }
            else if(temp1->data < temp2->data)
            {
                return 0; // Second number is larger
            }
	    }
    }
    return flag;
}



char* check_sign(char *num1,char*num2)
{
    if(num1[0] == '-' && num2[0]=='-')
    {
        return "--"; //both the numbers are negative 
    }    
    else if(num1[0] == '-' )
    {
        return "-+"; // one is positive anothe one is negative
    }
    else if(num2[0]=='-')
    {
        return "+-"; // one is positive anothe one is negative
    }
    else
    {
        return "0";//both are positive numbers
    }
}
