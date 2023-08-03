#ifndef DNODE_H
#define DNODE_H

typedef struct student {
	char *lastname;
	char *firstname;
	long id;
	char *year;
	int gradYear;
	struct student *next;
	struct student *prev;
} student;

void printStudent(struct student *myStudent);

#endif
