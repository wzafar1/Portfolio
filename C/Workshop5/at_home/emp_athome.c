/*
Name: Wahab Zafar
Student number: 106939168
Email: Wzafar1@myseneca.ca
Workshop: 5
Section: Q
Date: 15/02/2017
*/

#include <stdio.h>
#define SIZE 4

struct Employee {
	int id;
	int age;
	double salary;
};

int main(void) 
{
	int option = 0;
	int n = 0; // Used to keep track for struct in if else statement
	int s,r; // s for salary update and r is for removing the employing
	printf("---=== EMPLOYEE DATA ===---\n\n");
	struct Employee emp[SIZE] = { { 0 } };
	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			break;
		case 1: // Display Employee Data
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			int i = 0;
			while (i < SIZE ) {
				if (emp[i].id > 0) 
				{
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
				i++;
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
			printf("Adding Employee\n");
			printf("===============\n");
			if (n < SIZE) {
				do {
					printf("Enter Employee ID: ");
					scanf("%d", &emp[n].id);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[n].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[n].salary);
					printf("\n");
					if (emp[n].id <= 0)
					{
						printf("Employee ID cannot be zero or less\n\n");
					}
				} while (emp[n].id <= 0);
				n++;
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;
		case 3:
			do {
				printf("Update Employee Salary\n");
				printf("======================\n");
				printf("Enter Employee ID: ");
				scanf("%d", &s);
				if (s != emp[0].id && s != emp[1].id && s != emp[2].id && s != emp[3].id)
				{
					printf("\nEmployee does not exist!!\n");
				}
			} while (s != emp[0].id && s != emp[1].id && s != emp[2].id && s != emp[3].id);
			for (i = 0; i < SIZE; i++) {
				if (s == emp[i].id) {
					printf("The current salary is %.2lf", emp[i].salary);
					printf("\nEnter Employee New Salary: ");
					scanf("%lf",&emp[i].salary);
				}
			}
			printf("\n");
			break;
		case 4:
			do {
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &r);
				if (r != emp[0].id && r != emp[1].id && r != emp[2].id && r != emp[3].id)
				{
					printf("\nEmployee does not exist!!\n");
				}
			} while (r != emp[0].id && r != emp[1].id && r != emp[2].id && r != emp[3].id);

			printf("Employee %d will be removed\n\n", r);
			for (i = 0; i < SIZE; i++) {
				if (r == emp[i].id) 
				{
					emp[i].id = 0;
					emp[i].age = 0;
					emp[i].salary = 0;
					n--;
				}
			}
				break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
			}
		} while (option != 0);
		printf("Exiting Employee Data Program. Good Bye!!!\n");
		return 0;
	}