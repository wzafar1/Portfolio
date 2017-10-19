/*
Name: Wahab Zafar
Section: Q
Student No. 106939168
Email address: wzafa1@myseneca.ca
Workshop: 6
Date: 22/02/2017
*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

struct Rental
{
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
};

double addPositive(double amount, double newamount);

double addPositive(double amount, double newamount)
{
	if (newamount > 0)
	{
		amount = amount + newamount;
		return amount;
	}
	else
	{
		return amount;
	}
}

int main()
{
	const int noVehicles = 2;			
	int option;							
	int flag;							
	int tempID;							
	int i = 0;							
	int rent_days;
	float kilo_driven;
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };
	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status

			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");
			for (i = 0; i < noVehicles; i++)
			{
				printf("%8d %10.2lf", vRent[i].id, vRent[i].earnings);
				printf("\n");
			}
			printf("\n");
			break;

		case 2:

			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}

			if (flag != -1) {
				double base_price = 0;
				double kilo_cost = 0;
				double charge;
				printf("Enter Rental Period (in Days): ");
				scanf("%d", &rent_days);
				printf("Enter kilometers driven: ");
				scanf("%f", &kilo_driven);
				base_price = rent_days * vRent[flag].baseDay;
				if (kilo_driven > 100)
				{
					double d1;
					double d2;
					double temp;
					d2 = kilo_driven - 100;
					temp = d2;
					d2 = d2 * 0.49;
					d1 = kilo_driven - temp;
					d1 = d1 * 0.69;
					kilo_cost = d1 + d2;
					
				}
				else
				{
					kilo_cost = kilo_driven * 0.69;
				}
				charge = kilo_cost + base_price;
				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);
				printf("\nBase   kmCost Total\n");
				printf("====== ====== ======\n");
				printf("%6.2lf %6.2lf %6.2lf", base_price, kilo_cost, vRent[flag].earnings);
				printf("\n\n");
			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			break;


		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}