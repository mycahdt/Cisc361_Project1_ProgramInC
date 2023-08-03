#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLL.h"
#include "DNode.h"

#define BUFFERSIZE 1024

/*Add a student to the end of the list*/
void addStudent(DLL *my_DLL){

	printf("\n----------------------------------------\n");
	printf("Option 1: Adding a student to the list.\n");

	char buffer[BUFFERSIZE];

	/*Creates a new instance of a Student sturct called new_Student*/
        /*Uses malloc to dynamically allocate memory for new_Student*/
   	struct student* new_Student = (struct student*)malloc(sizeof(struct student));

	/*Asks user for lastname fgets and saves it in buffer*/
	/*Copies buffer into the new_Student's lastname*/
	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter the last name: ");
	if (fgets(buffer, BUFFERSIZE, stdin) != NULL){
    		int len = (int) strlen(buffer);
		buffer[len - 1] = '\0';                 // why minus 1 ???
    		new_Student->lastname = (char *) malloc(len);
    		strcpy(new_Student->lastname, buffer);
    		printf("The last name is [%s].\n", new_Student->lastname);
  	}

	/*Asks user for firstname using fgets and saves it in buffer*/
        /*Copies buffer into the new_Student's firstname*/
	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter the first name: ");
        if (fgets(buffer, BUFFERSIZE, stdin) != NULL){
                int len = (int) strlen(buffer);
                buffer[len - 1] = '\0';                 // why minus 1 ???
                new_Student->firstname = (char *) malloc(len);
                strcpy(new_Student->firstname, buffer);
                printf("The first name is [%s].\n", new_Student->firstname);
        }

	/*Asks user for ID using scanf*/
	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter an integer for the student ID: ");
	scanf("%ld", &new_Student->id);
	printf("The student ID is [%ld].\n", new_Student->id);

	/*Asks user for year using fgets and saves it in buffer*/
        /*Copies buffer into the new_Student's year*/
	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter the student\'s year (i.e. freshman, sophomore): ");
        if (fgets(buffer, BUFFERSIZE, stdin) != NULL){
                int len = (int) strlen(buffer);
                buffer[len - 1] = '\0';                 // why minus 1 ???
                new_Student->year = (char *) malloc(len);
                strcpy(new_Student->year, buffer);
                printf("The year is [%s].\n", new_Student->year);
        }

	/*Asks user for expected year of graduation*/
	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter the student\'s expected year of graduation: ");
	scanf("%d", &new_Student->gradYear);
	printf("The expected year of graduation is [%d].\n", new_Student->gradYear);

	if (my_DLL->head == NULL){
		/*When head is NULL, meaning there are no students in the list*/
		/*new_Student becomes the first student in the list*/

		/*Set prev and next to NULL*/
		new_Student->prev = NULL;
		new_Student->next = NULL;

		/*Set head and tail of the DLL to new_Student*/
		my_DLL->head = new_Student;
		my_DLL->tail = new_Student;


	} else if (my_DLL->head == my_DLL->tail) {
		/*When head is equal to tail, meaning there is 1 student in the list*/
		/*new_Student becomes the second student in the list*/

		/*Set prev to NULL, and next to head of the DLL*/
		new_Student->prev = my_DLL->head;
		new_Student->next = NULL;

		/*Set head's next to be new_Student*/
		my_DLL->head->next = new_Student;

		/*Set tail of the DLL to be new_Student*/
		my_DLL->tail = new_Student;


	} else {
		/*When there is 2 or more students in the list*/

    		/*Set next to NULL, since end item's next is always NULL*/
    		new_Student->next = NULL;

    		/*Set prev to be the list's last item (the tail)*/
    		new_Student->prev = my_DLL->tail;

    		/*Set tail's next to be new_Student*/
		(my_DLL->tail)->next = new_Student;

    		/*Move tail to point to new_Student*/
    		(my_DLL->tail) = new_Student;
	}
}

/*Deletes a student from the list given their lastname*/
/*Deletes all students with that lastname*/
void deleteStudent(DLL *my_DLL){

	printf("\n---------------------------------------------\n");
	printf("Option 2: Deleting student(s) from the list.\n");

	/*Asks user for lastname using fgets and saves it in buffer*/
        /*Uses buffer in order to determine if the given lastname matches the current node's lastname*/
	/*Then deletes that node*/

	char buffer[BUFFERSIZE];

	fflush(stdin);
	setbuf(stdin, NULL);
	printf("\nEnter the last name of the student(s) you want to delete: ");

	if (fgets(buffer, BUFFERSIZE , stdin) != NULL){

		int len = (int) strlen(buffer);
		buffer[len - 1] = '\0';

		student *node = my_DLL->head;
		student *ptr;
		while (node != NULL) {

			if ((int)strcmp(node->lastname, buffer) == 0){
				/*When buffer is equal to node's lastname*/

				if ((int)strcmp(my_DLL->head->lastname, buffer) == 0){

					/*Delete head node*/
					/*When buffer is equal to head's lastname*/

					if(node->next == NULL){
						/*When head node's next is NULL, meaning there is 1 student in the list*/

						/*Sets head and tail of the DLL to NULL*/
						my_DLL->head = NULL;
						my_DLL->tail = NULL;

					} else {
						/*When node's next is not NULL, meaning there is 2 or more students in the list*/

						/*Set the node's next's prev to NULL*/
						node->next->prev = NULL;

						/*Move head to point to node's next*/
						my_DLL->head = node->next;

					}
				} else if(my_DLL->tail != node && my_DLL->head != node){
					/*Delete node in middle (anything node that's not head or tail)*/

                                        /*Set node's prev's next to node's next*/
                                        node->prev->next = node->next;

                                        /*Set node's next's prev to node's prev*/
                                        node->next->prev = node->prev;

				} else if((int)strcmp(my_DLL->tail->lastname, buffer) == 0){

					/*Delete tail node*/
					/*When buffer is equal to tail's lastname*/

					/*Set node's prev's next to NULL*/
					node->prev->next = NULL;

					/*Move tail to point to node's prev*/
					my_DLL->tail = node->prev;

				}

				/*Move ptr to point to node*/
				/*Move node to point to node's next*/
				/*free is used to deallocate the memory of ptr*/

				ptr = node;
				node = node->next;

				free(ptr->lastname);
				free(ptr->firstname);
				free(ptr->year);
				free(ptr);
			} else {
				/*When buffer if not equal to node's lastname, meaning that the node will not be deleted*/

				/*Set node to node's next*/
				node = node->next;

    			}
		}
	}
}

/*Prints the list of students from beginning to end*/
void printForward(DLL *my_DLL){
	printf("\n------------------------------------------------\n");
	printf("Option 3: Print the list from beginning to end.\n");

	if(my_DLL->head == NULL){
		/*When there are 0 students in the list*/
		printf("No students in the list.\n");
	} else {
		/*Prints the list of students starting from the head*/
		student *node = my_DLL->head;
		while (node != NULL) {
			printStudent(node);
        		node = node->next;
    		}
	}
}

/*Prints the list of students from end to beginning*/
void printBackwards(DLL *my_DLL){
	printf("\n------------------------------------------------\n");
	printf("Option 4: Print the list from end to beginning.\n");

	if(my_DLL->head == NULL){
		/*When there are 0 students in the list*/
		printf("No students in the list.\n");
	} else if(my_DLL->tail == NULL){
		/*When there is 1 student in the list*/
		printStudent(my_DLL->head);
	} else {
		/*Prints the list of students starting from the head*/
		student *node = my_DLL->tail;
		while (node != NULL) {
			printStudent(node);
        		node = node->prev;
		}
	}
}

/*Deallocates all of the allocated memory and exits the program*/
void exitProgram(DLL *my_DLL){

	/*Deallocates the allocated memory*/
	student *node = my_DLL->head;
	student *ptr;
	while (node != NULL) {
		ptr = node;
		node = node->next;
		free(ptr->lastname);
		free(ptr->firstname);
		free(ptr->year);
		free(ptr);
    	}
	free(my_DLL);
	printf("\n----------------------------\n");
	printf("Option 5: Exit the program.\n");
}

