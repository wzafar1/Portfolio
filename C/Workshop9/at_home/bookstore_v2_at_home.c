/*
Name: Wahab Zafar
Student number: 106939168
Email: wzafar1@myseneca.ca
Workshop: 9
Section: Q
Date: 22/03/2017
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 21

struct Book;

struct Book {

	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;

};
void menu();
void displayInventory(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
int searchInventory(FILE *fp, const int isbn2find); 
float calculateCapital(const char filename[]);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);

int main()
{
   //Type your code here:
	struct Book mybook; 
	int option;
	int t_isbn;
	char filename[] = "144_w9_inventory.txt";
	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do {
		
		menu();
		printf("Select: ");
		scanf("%d", &option);
		switch (option) {

		case 1:
			
			displayInventory(filename);
			break;
		
		case 2:

			printf("ISBN:");
			scanf("%d", &mybook._isbn);
			printf("Title:");
			scanf(" %[^\n]%*c", mybook._title);
			printf("Year:");
			scanf("%d", &mybook._year);
			printf("Price:");
			scanf("%f", &mybook._price);
			printf("Quantity:");
			scanf("%d", &mybook._qty);

			addBook(filename, &mybook);
			break;

		case 3:

			
			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &t_isbn);

			checkPrice(filename, t_isbn);
			break;

		case 4:

			printf("The total capital is: $%.2f.\n",calculateCapital(filename));
			break;

		case 0:

			printf("Goodbye!\n");
			break;

		}
			

	} while (option != 0);

    return 0;
}

void menu()
{

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");

}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
	struct Book book;
	//Open the file, and check for null pointer
	FILE *fp = NULL;
    fp = fopen(filename, "r");
    
    //If the file is properly opened, display headers
	if(fp != NULL) {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		//HEADERS
		while (readRecord(fp, &book) == 5) {

			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);

		}
		printf("===================================================\n\n");
	}
	else
	{

		printf("Could not open file\n\n");

	}
	
	fclose(fp);
    //Close the file

}





void addBook(const char filename[], struct Book *b2Add)
{
	int found = 0;
	FILE *fp = NULL;
	fp = fopen(filename, "a+");
	if (fp != NULL) {

		found = searchInventory(fp, b2Add->_isbn);
		if (found == 1) {

			printf("The book exists in the repository!\n\n");

		}
		else {

			fprintf(fp, "\n%d;%.2f;%d;%d;%s", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
			printf("The book is successfully added to the inventory.\n\n");

		}

	}
	else {

		printf("Could not open file\n\n");

	}
	fclose(fp);
}

void checkPrice(const char filename[],const int isbn2find)
{
	int found = 0;
	float price=0;
	struct Book book;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {

		while (readRecord(fp, &book) == 5) {

			if (isbn2find == book._isbn) {
				price = book._price;
				found = 1;
			}

		}
		if (found == 1) {

			printf("Book %d costs $%.2f\n\n", isbn2find, price);

		}
		else {

			printf("Book not found\n\n");

		}
	}
	else {

		printf("Could not open file\n\n");

	}

 
}

int searchInventory(FILE *fp,const int isbn2find)  
{
    
	struct Book book;
	int found = -1;
	if (fp != NULL) {

		while (readRecord(fp, &book) == 5) {

			if (isbn2find == book._isbn) {

				found = 1;

			}

		}

	}

	return found;

}


float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
	struct Book book;
    //Define and initialize total_capital
	float total_captial = 0;
	FILE *fp = NULL;
    
    //Open the file, and check for null pointer
	fp = fopen(filename, "r");
	if (fp != NULL) {

		//while loop to call readRecord
		while (readRecord(fp, &book) == 5) {

			//Accumulate the multiplication of the price of each item to its quantity
			total_captial = total_captial + (book._qty*book._price);

		}
		fclose(fp);
	}
	else {

		printf("Could not open file\n");

	}

    //Close the file
	//fclose(fp);
	return total_captial;
    //return the total_capital
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
	int rv = 0;

	rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]%*c",&b2read->_isbn, &b2read->_price,&b2read->_year,&b2read->_qty, b2read->_title);
	return rv;
    //return rv;

}
