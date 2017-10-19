/*
Name:Wahab Zafar
Student number:106939168
Email:wzafar1@myseneca.ca
Workshop:7
Section:Q
Date:08/03/2017
*/

#include <stdio.h>
#define SIZE 3

void decompose(long long phone_number, int *area, int *prefix, int *lineno);

void decompose( long long phone_number, int *area, int *prefix, int *lineno)
{
	*area = (int)(phone_number / 10000000);
	*prefix = (int)((phone_number % 10000000)/10000);
	*lineno = (int)(phone_number % 10000);
}

/* main program */
int main(void) {

	int option;
	int i;
	int n = 0;
	int area;
	int prefix;
	int line_no;
	long long phoneNumber [SIZE] =  {0LL} ;
	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		
		case 0:	// Exit the program

			break;

		case 1: // Display the Phone List

			printf("Phone Numbers\n");
			printf("==============\n");
			for (i = 0; i < n ;i++) 
			{
					decompose(phoneNumber[i], &area, &prefix, &line_no);
					printf("(%03d)-%03d-%04d", area, prefix, line_no);
					printf("\n");
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
			printf("Add a Number\n");
			printf("============\n");
			if (n < SIZE) {
				scanf("%lld", &phoneNumber[n]);
				n++;
			}
			else {
				printf("ERROR!!! Phone Number List is Full\n");
			}
			printf("\n");
			break;

		default:
			
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");

		}

	} while (option != 0);

	printf("Exiting Phone Number App. Good Bye!!!\n");
	return 0;
}
