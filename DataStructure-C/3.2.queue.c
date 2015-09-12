/*队列的链表实现*/
#include <stdio.h>
#include "3.2.queue.h"
int main() {
	Queue* queue = NULL;
	int i = 0, size = 10;

	printf("创建空队列：\n");
	queue = creatQueue(size);
	printAll(queue);

	printf("设置元素：\n");
	while (isFull(queue) == 0) {
		add(queue, i++);
		printAll(queue);
	}

	printf("边界测试，在满队列状态下继续add：\n");
	add(queue, 10);

	printf("delete * 5：\n");
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	printAll(queue);

	printf("add * 2：\n");
	add(queue, 111);
	add(queue, 222);
	printAll(queue);

	printf("delete所有内容：\n");
	while (isEmpty(queue) == 0) {
		delete(queue, NULL);
		printAll(queue);
	}

	printf("边界测试，在空状态下继续delete：\n");
	delete(queue, NULL);//边界测试

	system("pause");
 	return 0;
}

//生成长度为MaxSize的空队列；
Queue* creatQueue(int maxSize) {
	Queue* queue = NULL;
	queue = malloc(sizeof(Queue));
	queue->maxSize = maxSize;
	queue->currentSize = 0;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

// 判断队列Q是否已满；
int isFull(Queue* q) {
	return q->currentSize == q->maxSize;
}

// 将数据元素item插入队列Q中；
void add(Queue* q, int item) {
	Node* t = NULL;
	if (!isFull(q)) {
		t = malloc(sizeof(Node));
		t->element = item;
		t->next = NULL;
		if (isEmpty(q))	q->first = q->last = t;
		else q->last->next = t;
		q->last = t;
		q->currentSize++;
		printf("add %d\n", item);
		//为了方便观察打印信息
	} else {
		printf("Queue is Full!\n");
	}
}

// 判断队列Q是否为空；
int isEmpty(Queue* q) {
	return q->currentSize == 0;
}

// 将队头数据元素从队列中删除并返回。
int delete(Queue* q, int* firstItem) {
	int ret;
	Node* t = q->first;
	if (!isEmpty(q)) {
		if (firstItem != NULL) {
			*firstItem = q->first->element;
		}
		printf("delete %d\n", q->first->element);
		//为了方便观察打印信息
		q->first = q->first->next;
		free(t);
		q->currentSize--;
		ret = 1;
		
	} else {
		printf("Queue is Empty!\n");
		ret = 0;
	}
	return ret;
}

//预览队列当前状态
void printAll(Queue* q) {
	int i = 0;
	Node* t = NULL;
	if (!isEmpty(q)) {
		t = q->first;
		while (t != NULL) {
			printf("element[%d] = %d\n", i++, t->element);
			t = t->next;
		}
		
	} else {
		printf("Empty Queue\n");
	}
	printf("\n");
}