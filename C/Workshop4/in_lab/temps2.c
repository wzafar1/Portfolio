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
	int a,d;
	int temp_l[10];
	int temp_h[10];
	printf("---=== IPC Temperature Analyzer V2.0 ===---");
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &d);
	while(d < 3 || d > 10)
		{
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &d);
		}
	printf("\n");
	for (a = 1; a <=d; a++)
	{
			printf("Day %d - High: ", a);
			scanf("%d", &temp_h[a]);
			printf("Day %d - Low: ", a);
			scanf("%d", &temp_l[a]);
	}
	printf("\nDay  Hi  Low");
		for (a = 1; a <= d; a++)
		{
			printf("\n%d    %d    %d", a , temp_h[a], temp_l[a]);
	}
	printf("\n");

	return 0;
}

