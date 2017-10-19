/*
Name: Wahab Zafar
Student number: 106939168
Email: wzafar1@myseneca.ca
Assignemt: Milestone 3
Section: Q
Date:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

// Define statements:

#define LINEAR 1
#define FORM 0

#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

// Constant TAX value:

const double TAX = 0.13;

// Item structure:

struct Item {

	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


// Function Prototypes Milestone 1:

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


// Function Prototypes Milesone 2:

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function Prototypes Milestone 3

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// Function Implementations Milestone 1:

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
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
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
	} while (temp1 != '\n');
	return value;
}

// Request an integer under a certien limit till correct is entered

int getIntLimited(int lowerLimit, int upperLimit) {

	int Tryagain = 0;
	int value;
	while (Tryagain == 0) {
		value = getInt();
		if (value >= lowerLimit && value <= upperLimit) {
			Tryagain = 1;
		}
		else {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
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
		if (value >= lowerLimit && value <= upperLimit) {
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
	} while (temp < 0 || temp > 7); // Verify that the user should enter between 0 and 7
	flushKeyboard(); //clear the input buffer
	return temp;
}

// calls menu function and direct the program execution according to user input

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

// Function Implementations Milestone 2:

double totalAfterTax(struct Item item) {

	double after_tax;

	if (item.isTaxed == 1) {

		after_tax = item.quantity*item.price + TAX*(item.quantity*item.price);

	}
	else {

		after_tax = item.quantity * item.price;

	}
	return after_tax;
}

// Checks stock level

int isLowQuantity(struct Item item) {

	int i = 0;

	if (item.quantity <= item.minQuantity) {
		i = 1;
	}
	return i;
}

// Promote the user for item details

struct Item itemEntry(int sku) {

	struct Item I;
	I.sku = sku;
	printf("        SKU: %d\n", I.sku);

	printf("       Name: ");
	scanf(" %[^\n]s", I.name);
	flushKeyboard();

	printf("      Price: ");
	I.price = getDouble();

	printf("   Quantity: ");
	I.quantity = getInt();

	printf("Minimum Qty: ");
	I.minQuantity = getInt();

	printf("   Is Taxed: ");
	I.isTaxed = yes();

	return I;

}

// display all items in array with warning for thos with low stock/quantity level

void displayItem(struct Item item, int linear) {

	if (linear == 1) {

		printf("|%3d", item.sku);
		printf("|%-20s", item.name);
		printf("|%8.2lf", item.price);
		if (item.isTaxed == 1) {
			printf("|  Yes");
		}
		else {
			printf("|   No");
		}
		printf("| %3d", item.quantity);
		printf(" | %3d", item.minQuantity);
		printf(" |%12.2lf|", totalAfterTax(item));
		if (isLowQuantity(item) == 1) { // calls the isLowquantity fuction to check the quantity level 
			printf("***");
		}
		printf("\n");
	}
	else if (linear == 0) {

		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %0.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		if (item.isTaxed == 1) {
			printf("   Is Taxed: Yes\n");
		}
		else {
			printf("   Is Taxed: No\n");
		}

		if (isLowQuantity(item) == 1) {  // calls the isLowquantity fuction to check the quantity level 
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

// functionuses displayItem in a loop to display the list of items in array

void listItems(const struct Item item[], int NoOfItems) {

	int i = 0;
	double Grand_total = 0;

	printTitle();

	for (i = 0; i < NoOfItems; i++) {

		printf("%-4d", i + 1);
		displayItem(item[i], 1);
		Grand_total += totalAfterTax(item[i]);
	}
	printFooter(Grand_total);
}

// Used to locate a particular book in the array using sku

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {

	int found = 0;
	int i;
	for (i = 0; i < NoOfRecs; i++) {

		if (item[i].sku == sku) {

			*index = i;
			found = 1;

		}

	}
	return found;
}

// Function Implementations Milestone 3:

// Search through the array for particular Array

void search(const struct Item item[], int NoOfRecs) {

	int sku;
	int found;
	int Index;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX); // Calls getInLimited function to get sku value in limit
	found = locateItem(item, NoOfRecs, sku, &Index); // Calls locateItem to search for the sku value
	if (found == 1) {

		displayItem(item[Index], FORM); // Calls display function if sku was found

	}
	else {

		printf("Item not found!\n"); // Error message of sku is not found

	}

}

// Update the items in array like quantity and other stuff

void updateItem(struct Item* itemptr) {

	int sure;
	struct Item add_item; // adding new item
	printf("Enter new data:\n");
	add_item = itemEntry(itemptr->sku); // gets the details of items using sku provided as pointer
	printf("Overwrite old data? (Y)es/(N)o: ");
	sure = yes(); // calls yes function
	if (sure == 1) {

		*itemptr = add_item; // if yes pointer value is updated
		printf("--== Updated! ==--\n");

	}
	else {

		printf("--== Aborted! ==--\n");

	}
	

}

//add new items at the end of current items in array

void addItem(struct Item item[], int *NoOfRecs, int sku) {

	int sure;
	struct Item add_item; //creating new item called add_item
	if (*NoOfRecs == MAX_ITEM_NO) { //check if we exceed the maximum allowed limit

		printf("Can not add new item; Storage Full!\n");

	}
	else {

		add_item = itemEntry(sku); // getting the details of item we want to add
		printf("Add Item? (Y)es/(N)o: ");
		sure = yes(); // Calling yes function for user confirmation
		if (sure == 1) {

			item[*NoOfRecs] = add_item; // assign the value to last record in list
			*NoOfRecs = *NoOfRecs + 1;
			printf("--== Added! ==--\n");

		}
		else {

			printf("--== Aborted! ==--\n");

		}

	}

}

// gets sku value from the user and update or add an item depending if the item is in the array

void addOrUpdateItem(struct Item item[], int* NoOfRecs) {

	int sku;
	int found;
	int sure;
	int Index;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);  // Calls getInLimited function to get sku value in limit
	found = locateItem(item, *NoOfRecs, sku, &Index); //search for the sku in the list
	if (found == 1) {

		displayItem(item[Index], FORM);   // If found display the item
		printf("Item already exists, Update? (Y)es/(N)o: ");
		sure = yes();
		if (sure == 1) {

			updateItem(&item[Index]); // if exists update the item by calling the update function

		}
		else {

			printf("--== Aborted! ==--\n");

		}
	}
	else {

		addItem(item, NoOfRecs, sku); //if sku is not found calls additem function to add the item

	}
}

//This function will increase or reduce the quantity of the selected Item in the array by the value received from the user

void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {

	int sku;
	int found;
	int Index;
	int new_value;
	int low_qty;
	char var1[10] = "to stock";
	char var2[12] = "to checkout";
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);  // Calls getInLimited function to get sku value in limit
	found = locateItem(item, NoOfRecs, sku, &Index); //search for the sku in the list
	if (found == 1) {

		displayItem(item[Index], FORM);
		if (stock == STOCK) {   //to keep the items on stock
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", var1, MAX_QTY - item[Index].quantity);
			new_value = getIntLimited(0, MAX_QTY - item[Index].quantity);
		}
		else {   //to check out the items that are available
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", var2, item[Index].quantity);
			new_value = getIntLimited(0, item[Index].quantity);

		}

		if (new_value != 0) {

			if (stock == STOCK) {

				item[Index].quantity = item[Index].quantity + new_value; // increase the quantity of the item by adding the enter value
				printf("--== Stocked! ==--\n");

			}
			else if (stock == CHECKOUT) {

				item[Index].quantity = item[Index].quantity - new_value; // decrese the quantity of the item by substracting the entered value
				printf("--== Checked out! ==--\n");
			}
			low_qty = isLowQuantity(item[Index]);    //checks if the quantity of item below minimum quantity
			if (low_qty == 1) {                            //if it is below the minimum quantity message is displayed
				printf("Quantity is low, please reorder ASAP!!!\n");

			}
		}
		else {

			printf("--== Aborted! ==--\n");

		}
	}
	else {

		printf("SKU not found in storage!\n");

	}


}