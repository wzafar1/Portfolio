/*Name : Wahab Zafar
Section : Q
Student number : 106939168
Workshop 2*/

#include <stdio.h>


int main()
{
	double amount;
	float a1, a2;
	int quarters, loonies;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	loonies = amount/1;
	a1 = amount - loonies;
	printf("Loonies required: %d, ", loonies);
	printf("balance owing $%.2f\n", a1);
	quarters = a1 / .25;
	a2 = a1 - quarters * 0.25;
	printf("Quarters required: %d, ", quarters);
	printf("balance owing $%.2f\n", a2);


	return 0;
}