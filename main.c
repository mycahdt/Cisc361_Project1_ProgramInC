#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"
#include "DNode.h"

int main(){
	int option;

	/*Creates a new instance of a DLL sturct called new_DLL*/
	/*Uses malloc to dynamically allocate memory for new_DLL*/
	struct DLL *new_DLL = (struct DLL*)malloc(sizeof(struct DLL));

	do {
		/*Prints the 5 possible options for the user to choose from*/
		/*Uses scanf to ask the user's option from 1 to 5*/
		printf("\n--------------------------------------------\n");
		printf("Doubly Linked List: Student Data\n");
		printf("1. Add a student to the list\n");
		printf("2. Delete student(s) from the list\n");
		printf("3. Print the list from beginning to end\n");
		printf("4. Print the list from end to beginning\n");
		printf("5. Exit the program\n");
		printf("Please enter an option from 1 to 5:\n");
		scanf("%d", &option);

		/*Uses the user's input option in order to do 1 out of the 5 possible options*/
		switch(option){
			case 1:
				addStudent(new_DLL);
				break;
			case 2:
				deleteStudent(new_DLL);
				break;
			case 3:
				printForward(new_DLL);
				break;
			case 4:
				printBackwards(new_DLL);
				break;
			case 5:
				exitProgram(new_DLL);
				break;
			default:
				printf("Out of range\n");
				break;
		}

	} while (option != 5); //Continually asks the user for input, until the option 5 is chosen and the program exits
	return 0;
}

