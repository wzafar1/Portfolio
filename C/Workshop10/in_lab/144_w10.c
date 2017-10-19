/*
Name: Wahab Zafar
Student number: 106939168
Email: wzafar1@myseneca.ca
Assignemt: Workshop 10
Section: Q
Date:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) {
  int isJedi = 0;

  char jedi_name[31];
  FILE *fp = NULL;
  fp = fopen("jedi_master.txt", "r");

  if (fp != NULL) {

	  while (fscanf(fp, "%[^\n]%*c", jedi_name) == 1) {

		  if (strcmp(jedi_name, name) == 0) {

			  isJedi = 1;

		  }

	  }
	  fclose(fp);
  }

  return isJedi;
}
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {

	int i = 0;
	int j_master = 0;
	int n_lenght;
	char t_name1[31];
	char t_name2[31];

	strcpy(t_name2, fullName);
	n_lenght = strlen(t_name2);

	if (isJediMaster(t_name2) == 1) {

		j_master = 1;

	}
	
	if (n_lenght <= 16) {

		for (i = 0; i < (16-n_lenght); i++) {

			strcat(t_name2, " ");

		}

	}
	else {

		strcpy(t_name1, t_name2);
		t_name1[14] = 0;
		strcpy(t_name2, t_name1);
		strcat(t_name2, "..");

	}

	strcpy(formattedRecord, t_name2);
	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);

	if (j_master == 1) {

		strcat(formattedRecord, " Jedi Master");

	}
}


/* formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/