#ifndef stack2_h
#define stack2_h
#include <stdlib.h>

typedef struct _node {
	int element;
	struct _node* next;
} Node;

typedef struct _stack {
	int currentSize;//当前元素个数
	Node top;//拿一个节点当头指针用，数据域代表栈的大小
} Stack;

Stack*  createStack(int maxSize); //创建栈
int isFull(Stack* s); //判断堆栈S是否已满；
void push(Stack* s, int item); // 将元素item压入堆栈；
int isEmpty(Stack* s); // 判断堆栈S是否为空；
int pop(Stack* s, int* i); // 删除并返回栈顶元素,失败返回0,成功的话变量会被存到i；
						   //如果传NULL给i，那么就顶元素就不会被存到i
void printAll(Stack* s); //预览栈当前状态
#endif