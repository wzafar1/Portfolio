/*Program : Add two numbers or Compare them depending upon the user request
  Name : Wahab Zafar
  Version : 1.0	2017-01-11*/

#include<stdio.h>
#include<math.h>
int main()
{
	int a;
	int b;
	int c;
	int result;
	printf("Enter First Number:");
	scanf("%d",&a);
	printf("\nEnter Second Number:");
	scanf("%d", &b);
	printf("\nEnter 1 for addition or else for comparison: ");
	scanf("%d", &c);

	if
		(c ==1)
	{
		result = a + b;
		printf("\nTotal:%d", result);
		printf("\n");
	}
	else
	{
		if
			(a > b)
			printf("First Number is greater\n");
		else
			printf("Second Number is greater\n");
	};
	return 0;
};