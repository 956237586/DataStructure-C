#ifndef stack1_h
#define stack1_h
#include <stdlib.h>
typedef struct _stack {
	int* elements;
	int size;
	int top;
} Stack;

Stack*  createStack(int maxSize); //创建栈
int isFull(Stack* s); //判断堆栈S是否已满；
void push(Stack* s, int item); // 将元素item压入堆栈；
int isEmpty(Stack* s); // 判断堆栈S是否为空；
int pop(Stack* s); // 删除并返回栈顶元素；
void printAll(Stack* s); //预览栈当前状态
#endif