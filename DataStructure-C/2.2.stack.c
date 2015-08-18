/*栈的链表实现*/
#include <stdio.h>
#include "2.2.stack.h"
int main() {
	Stack* stack = NULL;
	int i = 0, size = 10;

	printf("创建空栈：\n");
	stack = createStack(size);
	printAll(stack);

	printf("设置元素：\n");
	while (isFull(stack) == 0) {
		push(stack, i++);
		printAll(stack);
	}

	printf("边界测试，在满栈状态下继续push：\n");
	push(stack, 10);

	printf("pop * 5：\n");
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	printAll(stack);

	printf("push * 2：\n");
	push(stack, 111);
	push(stack, 222);
	printAll(stack);

	printf("pop所有内容：\n");
	while (isEmpty(stack) == 0) {
		pop(stack, NULL);
		printAll(stack);
	}

	printf("边界测试，在空栈状态下继续pop：\n");
	pop(stack, NULL);//边界测试

	system("pause");
	return 0;
}

//创建栈
Stack*  createStack(int maxSize) {
	Stack* stack = malloc(sizeof(Stack));
	if (stack != NULL) {
		stack->top.element = maxSize;
		stack->top.next = NULL;
		stack->currentSize = 0;
	}
	return stack;
}
//判断堆栈S是否已满
int isFull(Stack* s) {
	return s->currentSize == s->top.element;
}

// 将元素item压入堆栈
void push(Stack* s, int item) {
	Node* newItem = NULL;
	//if (isFull(s) == 0) {
	if (!isFull(s)) {
		newItem = malloc(sizeof(Node));
		newItem->element = item;
		newItem->next = s->top.next;
		s->top.next = newItem;
		s->currentSize++;
		printf("push %d\n", item);
	} else {
		printf("Stack is already full!\n");
	}
}

// 判断堆栈S是否为空；
int isEmpty(Stack* s) {
	return s->currentSize == 0;
}

// 删除并返回栈顶元素,失败返回0,成功的话变量会被存到i；
int pop(Stack* s, int* i) {
	int ret;
	Node* t = s->top.next;
	//if (isEmpty(s) == 0) {
	if (!isEmpty(s)) {
		if (i != NULL) {
			*i = s->top.next->element;
		}
		printf("pop %d\n", s->top.next->element);//为方便观察效果打印结果
		s->top.next = t->next;
		free(t);
		s->currentSize--;
		ret = 1;
	} else {
		printf("Stack is  already empty!\n");
		ret = 0;//特殊值，标志错误
	}
	return ret;
}

//预览栈当前状态
void printAll(Stack* s) {
	Node* t = s->top.next;
	int i = s->currentSize - 1;
	
	if (t == NULL) {
		printf("Empty Stack\n");
	} else {
		while (t != NULL) {
			printf("elements[%d] = %d\n", i--, t->element);
			t = t->next;
		}
	}
	printf("\n");
}