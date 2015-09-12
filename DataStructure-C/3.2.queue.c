/*���е�����ʵ��*/
#include <stdio.h>
#include "3.2.queue.h"
int main() {
	Queue* queue = NULL;
	int i = 0, size = 10;

	printf("�����ն��У�\n");
	queue = creatQueue(size);
	printAll(queue);

	printf("����Ԫ�أ�\n");
	while (isFull(queue) == 0) {
		add(queue, i++);
		printAll(queue);
	}

	printf("�߽���ԣ���������״̬�¼���add��\n");
	add(queue, 10);

	printf("delete * 5��\n");
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	delete(queue, NULL);
	printAll(queue);

	printf("add * 2��\n");
	add(queue, 111);
	add(queue, 222);
	printAll(queue);

	printf("delete�������ݣ�\n");
	while (isEmpty(queue) == 0) {
		delete(queue, NULL);
		printAll(queue);
	}

	printf("�߽���ԣ��ڿ�״̬�¼���delete��\n");
	delete(queue, NULL);//�߽����

	system("pause");
 	return 0;
}

//���ɳ���ΪMaxSize�Ŀն��У�
Queue* creatQueue(int maxSize) {
	Queue* queue = NULL;
	queue = malloc(sizeof(Queue));
	queue->maxSize = maxSize;
	queue->currentSize = 0;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

// �ж϶���Q�Ƿ�������
int isFull(Queue* q) {
	return q->currentSize == q->maxSize;
}

// ������Ԫ��item�������Q�У�
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
		//Ϊ�˷���۲��ӡ��Ϣ
	} else {
		printf("Queue is Full!\n");
	}
}

// �ж϶���Q�Ƿ�Ϊ�գ�
int isEmpty(Queue* q) {
	return q->currentSize == 0;
}

// ����ͷ����Ԫ�شӶ�����ɾ�������ء�
int delete(Queue* q, int* firstItem) {
	int ret;
	Node* t = q->first;
	if (!isEmpty(q)) {
		if (firstItem != NULL) {
			*firstItem = q->first->element;
		}
		printf("delete %d\n", q->first->element);
		//Ϊ�˷���۲��ӡ��Ϣ
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

//Ԥ�����е�ǰ״̬
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