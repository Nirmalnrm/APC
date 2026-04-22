/**************************************************************************************************************************************************************
*Author         : Nirmal Mohan
Student ID      : 24030_066
*Title		    : Arbitrary Precesion Calculator(APC)
*Description	:The Arbitrary Precision Calculator is a command-line tool that performs addition, subtraction, multiplication, and division on large numbers 
				that exceed the limits of standard data types (int, long, long long).To handle these large numbers, the calculator stores each digit in a node 
				of a doubly linked list (DLL), allowing for efficient arithmetic operations without worrying about integer overflow.
***************************************************************************************************************************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
		/* Declare the pointers */
      
		Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;

		Dlist *headR1=NULL, *tailR1=NULL;
		Dlist *headR2=NULL, *tailR2=NULL; 
		Dlist *headRBack=NULL,*tailRBack=NULL;

		 /* Extract operator from command-line arguments */
	    char operator=argv[2][0];
		int flag=0;
		char sign[3];
		long int count = 0;
	

		/* Validate input arguments */
		if(read_and_validate(argc,argv)==FAILURE)
		{
			printf("Validation Unsuccessfull :-(\n");
			return FAILURE;
		}


		/* Perform operation based on operator */
		switch (operator)
		{
			case '+':  // "ADDITION"
				/* call the function to perform the addition operation */
				printf("Result is : ");
				strcpy(sign,check_sign(argv[1],argv[3]));
				if(strcmp(sign,"--")==0)
				{
					store_large_num(&head1,&tail1,&head2,&tail2,argv);
					addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					printf("-");
				}
				else if(strcmp(sign,"+-")==0)
				{		
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);	
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					if(flag == 1)
					{
						printf("-");
					}
				}
				else if(strcmp(sign,"-+")==0)
				{
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);	
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					if(flag == 0)
					{
						printf("-");
					}
				}
				else
				{
					digit_to_list(&head1,&tail1,&head2,&tail2,argv);
					addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				}
				remove_zero(&headR,&tailR);
				print_list(headR);	
				break;
			
			case '-':	//"SUBTRACTION"
				/* call the function to perform the subtraction operation */
				printf("Result is : ");
				strcpy(sign,check_sign(argv[1],argv[3]));
				if(strcmp(sign,"--")==0)
				{
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					if(flag==0)
					{
						printf("-");
					}
				}
				else if(strcmp(sign,"+-")==0)
				{		
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);	
					addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				}
				else if(strcmp(sign,"-+")==0)
				{
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);
					addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);	
					printf("-");
				}
				else
				{
					flag=store_large_num(&head1,&tail1,&head2,&tail2,argv);
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					if(flag==1)
					{
						printf("-");
					}
				}
				remove_zero(&headR,&tailR);
				print_list(headR);	
				break;				
				
			case '*':	//"MULTIPLICATION"
				/* call the function to perform the multiplication operation */
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				multiplication(&head1,&tail1,&head2,&tail2,&headR1,&tailR1,&headR2,&tailR2,&headRBack,&tailRBack);
				if(abs(atoi(argv[1]))==0 || abs(atoi(argv[3]))==0)
				{
					printf("Result is : 0\n");
				}
				else
				{
					printf("Result is : ");
					strcpy(sign,check_sign(argv[1],argv[3]));
					if(strcmp(sign,"+-")==0 || strcmp(sign,"-+")==0)
					{
						printf("-");
					}
					print_list(headR1);	
				}
				break;

			case '/':	//"DIVISION"
				/* call the function to perform the division operation */
				if(abs(atoi(argv[3]))==0)
				{
					printf("ERROR: Division is not possible\n");
					return -1;
				}
                digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				count=division(&head1,&tail1,&head2,&tail2,&headR,&tailR,&headRBack,&tailRBack);
				printf("Result is : ");
				strcpy(sign,check_sign(argv[1],argv[3]));
				if(strcmp(sign,"+-")==0 || strcmp(sign,"-+")==0)
				{
					printf("-");
				}
				printf("%ld\n",count);
				break;

			default:// INVALID
				printf("Invalid Input:-( Try again...\n");
				break;
		}
	return 0;
}
