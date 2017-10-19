/*Name : Wahab Zafar
Section : Q
Student number : 106939168
Workshop 2
Write a program that calculates the minimum number of coins required to pay an amount owing. 
The coins to be used are loonies, quarters, dimes, nickels and pennies.
*/

#include <stdio.h>


int main()
{
	double amount1, amount2;
	float a1, a2, a3, a4, a5, gst;
	int quarters, loonies, dimes, nickels, pennies;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount1);
	gst = amount1 * .13+0.005;
	printf("GST: %.2f\n",gst);
	amount2 = amount1 + gst;
	printf("Balance owing: $%.2lf\n", amount2);
	loonies = amount2/1;
	a1 = amount2 - loonies;
	printf("Loonies required: %d, ", (int)loonies);
	printf("balance owing $%.2f\n", a1);
	quarters = a1 / 0.25;
	a2 = a1 - quarters * 0.25;
	printf("Quarters required: %d, ", (int)quarters);
	printf("balance owing $%.2f\n", a2);
	dimes = a2 / 0.10;
	a3 = a2 - dimes * 0.10;
	printf("Dimes required: %d, ", (int)dimes);
	printf("balance owing $%.2f\n",a3);
	nickels = a3 / 0.05;
	a4 = a3 - nickels * 0.05;
	printf("Nickels required: %d, ", (int)nickels);
	printf("balance owing $%.2f\n", a4);
	pennies = a4 / 0.01;
	a5 = a4 - pennies * 0.01;
	printf("Pennies required: %d, ", (int)pennies);
	printf("balance owing $%.2f\n", a5);


	return 0;
}