// temps.c : Takes differet days high and low temperature from user and calculate the average.
/*Name: Wahab Zafar
Student number : 106939168
Email: wzafar1@myseneca.ca
Workshop: 3
Section: Q
Date: 01-02-2017
*/

#include <stdio.h>
#define NUMS 3

int main()
{
	int a = 1;
	int t1, t2;
	int t_h = 0;
	int t_l = 0;
	float avg = 0;
	printf("---=== IPC Temperature Analyzer ===---");
	for (a = 1; a <= NUMS; a++)
	{	
		do {
			printf("\nEnter the high value for day %d: ", a);
			scanf("%d", &t1);
			printf("\nEnter the low value for day %d: ", a);
			scanf("%d", &t2);
			if ((t1 > 40 || t2 < -40) || (t1 < t2) || (t1 == t2))
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}
		} while ((t1 > 40 || t2 < -40) || (t1 < t2)|| (t1==t2));
		t_h = t1 + t_h;
		t_l = t2 + t_l;
	}
	avg = (float)(t_h+t_l) / 6;
	printf("\nThe average (mean) temperature was: %.2f\n", avg);

	return 0;
}

