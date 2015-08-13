#ifndef stack2_h
#define stack2_h
#include <stdlib.h>

typedef struct _node {
	int element;
	struct _node* next;
} Node;

typedef struct _stack {
	int currentSize;//��ǰԪ�ظ���
	Node top;//��һ���ڵ㵱ͷָ���ã����������ջ�Ĵ�С
} Stack;

Stack*  createStack(int maxSize); //����ջ
int isFull(Stack* s); //�ж϶�ջS�Ƿ�������
void push(Stack* s, int item); // ��Ԫ��itemѹ���ջ��
int isEmpty(Stack* s); // �ж϶�ջS�Ƿ�Ϊ�գ�
int pop(Stack* s, int* i); // ɾ��������ջ��Ԫ��,ʧ�ܷ���0,�ɹ��Ļ������ᱻ�浽i��
						   //�����NULL��i����ô�Ͷ�Ԫ�ؾͲ��ᱻ�浽i
void printAll(Stack* s); //Ԥ��ջ��ǰ״̬
#endif