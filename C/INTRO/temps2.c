// temps2.c : Takes differet days high and low temperature from user and calculate the average using array.
/*Name: Wahab Zafar
Student number : 106939168
Email: wzafar1@myseneca.ca
Workshop: 4
Section: Q
Date: 01-02-2017
*/

#include <stdio.h>
#define NUMS b

int main()
{
	int a,b,c;
	int temp1, temp2, day1, day2;
	int high = 0;
	int low = 0;
	int temp_h = 0;
	int temp_l = 0;
	float avg = 0;
	scanf("%d", &b);
	c = b * 2;
	printf("---=== IPC Temperature Analyzer ===---");
	for (a = 1; a <= NUMS; a++)
	{
		do {
			printf("\nEnter the high value for day %d: ", a);
			scanf("%d", &temp1);
			printf("\nEnter the low value for day %d: ", a);
			scanf("%d", &temp2);
			if ((temp1 > 40 || temp2 < -40) || (temp1 < temp2) || (temp1 == temp2))
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}
		} while ((temp1 > 40 || temp2 < -40) || (temp1 < temp2) || (temp1 == temp2));
		temp_h = temp1 + temp_h;
		if (temp1 > high)
		{
			high = temp1;
			day1 = a;
		}
		temp_l = temp2 + temp_l;
		if (temp2 < low)
		{
			low = temp2;
			day2 = a;
		}
	}
	avg = (float)(temp_h + temp_l) / c;
	printf("\nThe average (mean) temperature was: %.2f", avg);
	printf("\nThe highest temperature was %d, on day %d", high, day1);
	printf("\nThe lowest temperature was %d, on day %d\n", low, day2);
	return 0;
}

