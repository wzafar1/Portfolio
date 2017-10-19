#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:

void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

// Prints the layout in whicht the data will be arranged (when we will receive the data)

void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

// Display the Total

void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n",grandTotal);
	}
}

// Clears the input buffer

void flushKeyboard(void) {
	
	while (getchar() != '\n')
		;
}

// Stop th execution till the user press enter

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard(); //calls flushKeyboard to clear the input buffer
		}

// Request an integer from user

int getInt(void) {
	int value;
	char temp1;
	do {
		scanf("%d%c", &value, &temp1);
		if (temp1 != '\n') {
			printf("Invalid integer, please try again: ");
			flushKeyboard(); //clear the input buffer
		}
	} while ( temp1 !='\n');
	return value;
}

// Request an integer under a certien limit till correct is entered

int getIntLimited(int lowerLimit, int upperLimit){
	int Tryagain = 0;
	int value;
	while (Tryagain == 0) {
		value = getInt();
		if (value > lowerLimit && value < upperLimit) {
			Tryagain = 1;
		}else{
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
						}
	return value;
}

//Request an double from user

double getDouble(void) {
	double value;
	char temp1 = 0;
	while (temp1 != '\n') {
		scanf("%lf%c", &value, &temp1);
		if (value == 0 || temp1 != '\n') {
			printf("Invalid number, please try again: ");
			flushKeyboard(); //clear the input buffer
		}
	}
	return value;
}

// Request an double under a certien limit till correct is entered

double getDoubleLimited(double lowerLimit, double upperLimit) {
	int Tryagain = 0;
	double value;
	while (Tryagain == 0) {
		value = getDouble();
		if (value > lowerLimit && value < upperLimit) {
			Tryagain = 1;
		}
		else {
			printf("Invalid value, %.6lf< value < %.6lf: ", lowerLimit, upperLimit);
		}
	}
	return value;
}

// for returning a value 1 if the user type 'Y' or 'y' for exiting the program

int yes(void) {
	char temp_Input;
	char Input;
	int Tryagain = 0;
	do {
		int count = 0; // character counter since we only want single character input from the user 'Y','y','N'or'n'
		while ((temp_Input = getchar()) && temp_Input != '\n') {
			count = count + 1;
				Input = temp_Input;
			}
		if ((Input == 'Y' || Input == 'y') && count == 1) {
			Tryagain = 1;
		}
		else if ((Input == 'N' || Input == 'n') && count == 1) {
			Tryagain = 2;
		}
		else {
			printf("Only (Y)es or (N)o are acceptable: ");
		}
	} while (Tryagain == 0); //maintains fool proof input
	return Tryagain;
}

// Display the options available to the user for selection (receive the option number and return it to calling function)

int menu(void) {
	int temp; // Holds the options selected by the user for returning
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	do {
		scanf("%d", &temp);
		if (temp < 0 || temp > 7) {
			printf("Invalid value, 0 < value < 7: ");
		}
	}while(temp < 0  || temp > 7); // Verify that the user should enter between 0 and 7
	flushKeyboard(); //clear the input buffer
	return temp;
}

void GroceryInventorySystem(void) {
	welcome();
	int options;
	int c_var = 1;				//loop control vaiable
	do {
		options = menu(); //calls menu() function and stoer user input for switch
		switch (options) {
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:

			printf("Add/Update Item under construction!\n");
			pause();
			break;

		case 6:

			printf("Delete Item under construction!\n");
			pause();
			break;

		case 7:

			printf("Search by name under construction!\n");
			pause();
			break;

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			int temp1 = yes();
			if (temp1 == 1) {
				c_var = 0;
			}
			break;

		default:
			printf("Invalid Menu option\n");
			break;
		}
	} while (c_var == 1); // switch iternation controller
		
}