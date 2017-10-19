// temps2.c : Takes differet days high and low temperature from user and calculate the average using array.
/*Name: Wahab Zafar
Student number : 106939168
Email: wzafar1@myseneca.ca
Workshop: 4
Section: Q
Date: 08-02-2017
*/

#include <stdio.h>

int main()
{
	int a;		// Used in for loop to control the number of iteration.
	int b;		// Used in while loop to calculate differet days average teperature.
	int d;		// Used to store number of days user want to use for this program (total days).
	int t_l;	// Store the total low temperature value of all the days.
	int t_h;	// Store the total high temperature value of all the days.
	float avg;		// Store the average value for printing.
	int temp_l[10];			// An array used to store value of each day low tempeature.
	int temp_h[10];			// An array used to store value of each day high tempeature.
	printf("---=== IPC Temperature Analyzer V2.0 ===---");
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &d);			// Request input for number of days.
	while(d < 3 || d > 10)		// Check if user entered right input. If not reuest again.
		{
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &d);		// Request input for number of days again.
		}
	printf("\n");
	for (a = 1; a <=d; a++)		// Request user input for each day (low and high).
	{
			printf("Day %d - High: ", a);
			scanf("%d", &temp_h[a]);		// Store high temperature value.
			printf("Day %d - Low: ", a);
			scanf("%d", &temp_l[a]);		// Store low temperature value.
	}
	printf("\nDay  Hi  Low");
		for (a = 1; a <= d; a++)		// Loop for displaying result for each day.
		{
			printf("\n%d    %d    %d", a , temp_h[a], temp_l[a]);		// Display the results on screen in specfic formate.
	}
	printf("\n\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",d);
	scanf("%d", &b);		// Reequest user input to calculate the average.
	while (b > 0 )		// If user enter value greater than 1 enter the loop.
	{
		while (b < 1 || b > d)		// If user enter wrong input keep requestion the right input.
		{
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", d);
			scanf("%d", &b);
		}
		t_h = 0;		// Sets the value of t_h = 0 for each time the loop is repeated.
		t_l = 0;		// Sets the value of t_l = 0 for each time the loop is repeated.
		for (a = 1; a <= b; a++)
		{
			t_l = t_l + temp_l[a];		// Store all the low temperature values.
			t_h = t_h + temp_h[a];		// Store all the high temperature values.
		}
		avg = (float)(t_l+t_h) / (b * 2);		// cast the total of t_l and t_h into float and then calculate the average.
		printf("\nThe average temperature up to day %d is: %.2f",b,avg);
		printf("\n\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", d);
		scanf("%d", &b);		// Ask the user for input to see another day average or enter -1 to exit.
	}
	printf("\nGoodbye!\n");
	return 0;
}

