#ifndef LinearList2_h
#define LinearList2_h
#include<stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
} Node;

typedef struct _list{
	Node *head;
	Node *last;
	int len;
} List;

List createList();
Node* createNode(int number);
void listInit(List* pList);
void listAddNode(List* pList, int number);
Node* findNodeFrontOf(List* pList, Node* node);
Node* findNodeById(List* l, int index);
Node* findNodeByValue(List* pList, int value);
int getLength(List* pList);
void printList(List* pList);
int delNode(List* pList, Node* del);
int delNodeById(List* pList, int index);
int delNodeByValue(List* pList, int value);
int getNodeValueById(List* pList, int index);
void setNodeValueById(List* pList, int index, int value);
void insertInto(List* pList, int index, int x);
#endif