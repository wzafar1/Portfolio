/*
Name: Wahab Zafar
Student number: 106939168
Email: Wzafar1@myseneca.ca
Workshop: 5
Section: Q
Date: 15/02/2017
*/

#include <stdio.h>
#define SIZE 3
// Define Number of Employees "SIZE" to be 2

struct Employee {
	int id;
	int age;
	double salary;
};
// Declare Struct Employee 


/* main program */
int main(void) {

	int option = 0;
	int n = 1;
	int a = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");
	struct Employee emp[SIZE] = { {0} };

		// Declare a struct Employee array "emp" with SIZE elements 
		// and initialize all elements to zero

		do {
			// Print the option list
			printf("1. Display Employee Information\n");
			printf("2. Add Employee\n");
			printf("0. Exit\n\n");
			printf("Please select from the above options: ");

			// Capture input to option variable
			scanf("%d", &option);
			printf("\n");

			switch (option) {
			case 0:	// Exit the program

				break;
			case 1: // Display Employee Data
					// @IN-LAB

				printf("EMP ID  EMP AGE EMP SALARY\n");
				printf("======  ======= ==========\n");
				int i = 1;
				while (i < SIZE ) {
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					i++;
					printf("\n");
				}
				printf("\n");
				// Use "%6d%9d%11.2lf" formatting in a   
				// printf statement to display
				// employee id, age and salary of 
				// all  employees using a loop construct 

				// The loop construct will be run for SIZE times 
				// and will only display Employee data 
				// where the EmployeeID is > 0

				break;
			case 2:	// Adding Employee
					// @IN-LAB
				printf("Adding Employee\n");
				printf("===============\n");
				if (n < SIZE) {
					n++;
					a++;
					printf("Enter Employee ID: ");
					scanf("%d", &emp[a].id);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[a].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[a].salary);
					printf("\n");
				}
				else {
					printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				}
				// Check for limits on the array and add employee 
				// data accordingly. 



				break;
			default:
				printf("ERROR: Incorrect Option: Try Again\n\n");
			}

		} while (option != 0);

		printf("Exiting Employee Data Program. Good Bye!!!\n");
		return 0;
	}