/*栈的数组实现*/
#include <stdio.h>
#include "2.1.stack.h"
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
		printf("Stack is already full!\n");
	}
}

// 判断堆栈S是否为空；
int isEmpty(Stack* s) {
	return s->top == -1;
}

// 删除并返回栈顶元素,失败返回0,成功的话变量会被存到i；
int pop(Stack* s, int* i) {
	int ret;
	//if (isEmpty(s) == 0) {
	if (!isEmpty(s)) {
		if (i != NULL) {
			*i = s->elements[s->top];
		}
		printf("pop %d\n", s->elements[s->top]);//为方便观察效果打印结果
		s->top--;//注意这两句的顺序
		ret = 1;
	} else {
		printf("Stack is  already empty!\n"); 
		ret = 0;//特殊值，标志错误
	}
	return ret;
}

//预览栈当前状态
void printAll(Stack* s) {
	int i = 0;
	if (!isEmpty(s)) {
		for (i = s->top; i >= 0; i--) {
			printf("elements[%d] = %d\n", i, s->elements[i]);
		}
	} else {
		printf("Empty Stack\n");
	}
	printf("\n");
}