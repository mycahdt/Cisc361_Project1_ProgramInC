#ifndef DLL_H
#define DLL_H

typedef struct DLL {
	struct student *head;
	struct student *tail;
} DLL;

void addStudent(struct DLL *my_DLL);
void deleteStudent(struct DLL *my_DLL);
void printForward(struct DLL *my_DLL);
void printBackwards(struct DLL *my_DLL);
void exitProgram(struct DLL *my_DLL);

#endif
