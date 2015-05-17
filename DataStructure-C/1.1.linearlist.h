#ifndef LinearList1_h
#define LinearList1_h
#include<stdlib.h>

typedef struct _list{
	int lenth;
	int* elements;
} List;

List createList(int lenth);
int get(List* l, int index);
int set(List* l, int index, int x);
int indexOf(List* l, int x);
void insertInto(List* l, int index, int x);
void deleteElementAt(List * l, int index);
int getLength(List* l);
void printAll(List* l);
#endif