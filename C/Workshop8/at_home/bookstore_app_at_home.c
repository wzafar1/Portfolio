/*
Name: Wahab Zafar
Student number: 106939168
Email: wzafar1@myseneca.ca
Workshop: 8
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

void flushKeyboard(void);
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);

void flushKeyboard(void) {

	while (getchar() != '\n')
		;

}

void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n");

}

void displayInventory(const struct Book book[], const int size) {

	int i;
	if (size == 0) {

		printf("The inventory is empty!\n");

	}
	else {

		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for (i = 0; i < size; i++) {

			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);

		}
	}
	printf("===================================================\n\n");
}

int searchInventory(const struct Book book[], const int isbn, const int size) {

	int i;
	int index = -1;

	for (i = 0; i < size; i++) {

		if (isbn == book[i]._isbn) {

			index = i;
			i = i + 10;

		}

	}
	return index;
}


void addBook(struct Book book[], int *size) {

	int index;
	int isbn;
	printf("ISBN:");
	scanf("%d", &isbn); 
	printf("Quantity:");
	scanf("%d", &book[*size]._qty);
	flushKeyboard();
	index = searchInventory(book, isbn, *size);
	if (index != -1) {
	
		book[index]._qty = book[index]._qty + book[*size]._qty;
		printf("The book exists in the repository, quantity is updated.\n\n");

		}
	else if (*size != MAX_BOOKS) {

		book[*size]._isbn = isbn;
		printf("Title:");
		scanf("%[a-zA-Z0-9 ]", book[*size]._title);
		printf("Year:");
		scanf("%d", &book[*size]._year);
		printf("Price:");
		scanf("%f", &book[*size]._price);
		*size = *size + 1;
		printf("The book is successfully added to the inventory.\n\n");

	}
	else {

		printf("the inventory is full\n");

	}
}

void checkPrice(const struct Book book[], const int size) {

	int isbn;
	int index;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn);
	flushKeyboard();
	index = searchInventory(book, isbn, size);
	if (index != -1) {

		printf("Book %d costs $%.2lf\n\n",book[index]._isbn,book[index]._price);

	}
	else {

		printf("Book does not exist in the bookstore! Please try again.\n\n");

	}

}

int main() {

	struct Book book[MAX_BOOKS];
	int size = 0;
	int tryagain;
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do {
		menu();
		printf("\nSelect: ");
		scanf("%d", &tryagain);
		flushKeyboard();
		switch (tryagain){

		case 1:

			displayInventory(book, size);
			break;

		case 2:

			addBook(book, &size);
			break;

		case 3:

			checkPrice(book, size);
			break;

		case 0:

			printf("Goodbye!\n");
			break;

		default:
			printf("Invalid input, try again:\n");
			break;
		}

	} while (tryagain != 0);
	return 0;
}
