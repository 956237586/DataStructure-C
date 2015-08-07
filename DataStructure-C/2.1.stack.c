#include <stdio.h>
#include "2.1.stack.h"
int main() {
	Stack* stack = NULL;
	int i = 0, size = 10;

	printf_s("������ջ��\n");
	stack = createStack(size);
	printAll(stack);

	printf_s("����Ԫ�أ�\n");
	while (isFull(stack) == 0) {
		push(stack, i++);
		printAll(stack);
	}

	printf("�߽���ԣ���m��ջ״̬�¼���push��\n");
	push(stack, 10);

	printf_s("pop * 5��\n");
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	printAll(stack);

	printf_s("push * 2��\n");
	push(stack, 111);
	push(stack, 222);
	printAll(stack);

	printf("pop�������ݣ�\n");
	while (isEmpty(stack) == 0) {
		pop(stack);
		printAll(stack);
	}

	printf("�߽���ԣ��ڿ�ջ״̬�¼���pop��\n");
	pop(stack);//�߽����

	system("pause");
	return 0;
}

//����ջ
Stack*  createStack(int maxSize) {
	Stack* stack = malloc(sizeof(Stack));
	if(stack != NULL){
		stack->size = maxSize;
		stack->top = -1;
		stack->elements = malloc(maxSize * sizeof(int));
	}
	return stack;
}
//�ж϶�ջS�Ƿ�����
int isFull(Stack* s) {
	return s->top == s->size - 1;
}

// ��Ԫ��itemѹ���ջ
void push(Stack* s, int item) {
	//if (isFull(s) == 0) {
	if (!isFull(s)) {
		s->top++;
		s->elements[s->top] = item;//ע���������˳��
		printf("push %d\n", item);
	} else {
		printf_s("Stack is already full!\n");
	}
}

// �ж϶�ջS�Ƿ�Ϊ�գ�
int isEmpty(Stack* s) {
	return s->top == -1;
}

// ɾ��������ջ��Ԫ��
int pop(Stack* s) {
	int ret;
	//if (isEmpty(s) == 0) {
	if (!isEmpty(s)) {
		ret = s->elements[s->top];
		s->top--;//ע���������˳��
		printf("pop %d\n", ret);//Ϊ����۲�Ч����ӡ���
	} else {
		printf_s("Stack is  already empty!\n");
	}
	return -1;//����ֵ����־����
}

//Ԥ��ջ��ǰ״̬
void printAll(Stack* s) {
	int i = 0;
	if (!isEmpty(s)) {
		for (i = s->top; i >= 0; i--) {
			printf_s("elements[%d] = %d\n", i, s->elements[i]);
		}
	} else {
		printf_s("Empty Stack\n");
	}
	printf_s("\n");
}