#ifndef stack1_h
#define stack1_h
#include <stdlib.h>
typedef struct _stack {
	int* elements;
	int size;
	int top;
} Stack;

Stack*  createStack(int maxSize); //����ջ
int isFull(Stack* s); //�ж϶�ջS�Ƿ�������
void push(Stack* s, int item); // ��Ԫ��itemѹ���ջ��
int isEmpty(Stack* s); // �ж϶�ջS�Ƿ�Ϊ�գ�
int pop(Stack* s); // ɾ��������ջ��Ԫ�أ�
void printAll(Stack* s); //Ԥ��ջ��ǰ״̬
#endif