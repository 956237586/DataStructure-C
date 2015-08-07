#include <stdio.h>
#include "2.1.stack.h"
int main() {
	Stack* stack = NULL;
	int i = 0, size = 10;

	printf_s("创建空栈：\n");
	stack = createStack(size);
	printAll(stack);

	printf_s("设置元素：\n");
	while (isFull(stack) == 0) {
		push(stack, i++);
		printAll(stack);
	}

	printf("边界测试，在m满栈状态下继续push：\n");
	push(stack, 10);

	printf_s("pop * 5：\n");
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	printAll(stack);

	printf_s("push * 2：\n");
	push(stack, 111);
	push(stack, 222);
	printAll(stack);

	printf("pop所有内容：\n");
	while (isEmpty(stack) == 0) {
		pop(stack);
		printAll(stack);
	}

	printf("边界测试，在空栈状态下继续pop：\n");
	pop(stack);//边界测试

	system("pause");
	return 0;
}

//创建栈
Stack*  createStack(int maxSize) {
	Stack* stack = malloc(sizeof(Stack));
	if(stack != NULL){
		stack->size = maxSize;
		stack->top = -1;
		stack->elements = malloc(maxSize * sizeof(int));
	}
	return stack;
}
//判断堆栈S是否已满
int isFull(Stack* s) {
	return s->top == s->size - 1;
}

// 将元素item压入堆栈
void push(Stack* s, int item) {
	//if (isFull(s) == 0) {
	if (!isFull(s)) {
		s->top++;
		s->elements[s->top] = item;//注意这两句的顺序
		printf("push %d\n", item);
	} else {
		printf_s("Stack is already full!\n");
	}
}

// 判断堆栈S是否为空；
int isEmpty(Stack* s) {
	return s->top == -1;
}

// 删除并返回栈顶元素
int pop(Stack* s) {
	int ret;
	//if (isEmpty(s) == 0) {
	if (!isEmpty(s)) {
		ret = s->elements[s->top];
		s->top--;//注意这两句的顺序
		printf("pop %d\n", ret);//为方便观察效果打印结果
	} else {
		printf_s("Stack is  already empty!\n");
	}
	return -1;//特殊值，标志错误
}

//预览栈当前状态
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