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
double substractPositive(double amount, double newamount);
double taxCalc(double price, double rate);


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

double substractPositive(double amount, double newamount)
{
	if (newamount > 0)
	{
		amount = amount - newamount;
		return amount;
	}
	else
	{
		return amount;
	}
}

double taxCalc(double price, double rate)
{
	double taxes = price * rate;
	return taxes;
}

int main()
{
	const int noVehicles = 3;			
	int option;							
	int flag;							
	int tempID;							
	int i = 0;							
	int rent_days;
	char c;
	float kilo_driven;
	double taxRate = 0.14;
	double discount = 5;
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };
	printf("***** Rental Vehicle Management App *****\n\n");
	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
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
				scanf(" %d", &rent_days);
				printf("Enter kilometers driven: ");
				scanf(" %f", &kilo_driven);\
				printf("Apply Discount: ");
				scanf(" %c", &c);
				base_price = rent_days * vRent[flag].baseDay;
				if (kilo_driven > 100)
				{
					double temp;
					temp = kilo_driven - 100;
					kilo_cost = kilo_driven - temp;
					temp = temp * 0.49;
					kilo_cost = kilo_cost * 0.69;
					kilo_cost = kilo_cost + temp;
					
				}
				else
				{
					kilo_cost = kilo_driven * 0.69;
				}
				charge = kilo_cost + base_price;
				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);
				if (c == 'y' || c == 'Y')
				{
					vRent[flag].earnings = substractPositive(vRent[flag].earnings, discount);
				}
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");
				printf("%6.2lf %6.2lf %10c %6.2lf", base_price, kilo_cost, c, vRent[flag].earnings);
				printf("\n\n");
			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			break;

		case 3:

			printf("\n-- Apply Taxes To all Accounts--\n\n");
			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");
			for (i = 0; i < noVehicles; i++) {
				double tax;
				tax = taxCalc(vRent[i].earnings, taxRate);
				vRent[i].earnings = addPositive(vRent[i].earnings, tax);
				printf("%8d %10.2lf %6.2lf", vRent[i].id, vRent[i].earnings, tax);
				printf("\n");
			}
			printf("\n");
			break;

		case 4:

			flag = -1;
			int gift = 0;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			if (flag != -1)
			{
				printf("Enter Gift Card Amount: ");
				scanf("%d", &gift);
				vRent[flag].earnings = substractPositive(vRent[flag].earnings, gift);
				printf("Discount Applied");
				printf("\n");
			}
			printf("\n");
			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}