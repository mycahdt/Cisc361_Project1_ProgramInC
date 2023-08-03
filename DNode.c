#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DNode.h"

/*Prints the student's information including
lastname, firstname, id, year, and gradYear*/
void printStudent(student *myStudent){
	printf("\n-------Student: %s %s-------\n", myStudent->firstname, myStudent->lastname);
	printf("Last name: %s\n", myStudent->lastname);
	printf("First name: %s\n", myStudent->firstname);
	printf("ID: %ld\n", myStudent->id);
	printf("Year: %s\n", myStudent->year);
	printf("Year of Expected Graduation: %d\n", myStudent->gradYear);
}

