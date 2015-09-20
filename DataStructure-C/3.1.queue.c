/*���е�����ʵ�֣�ѭ�����У�*/
#include <stdio.h>
#include "3.1.queue.h"
int main() {
	Queue* queue = NULL;
	int i = 0, size = 10;

	printf("�����ն��У�\n");
	queue = creatQueue(size);
	printAll(queue);

	printf("����Ԫ�أ�\n");
	while (isFull(queue) == 0) {
		append(queue, i++);
		printAll(queue);
	}

	printf("�߽���ԣ���������״̬�¼���add��\n");
	append(queue, 10);

	printf("delete * 5��\n");
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	printAll(queue);

	printf("add * 2��\n");
	append(queue, 111);
	append(queue, 222);
	printAll(queue);

	printf("delete�������ݣ�\n");
	while (isEmpty(queue) == 0) {
		serve(queue, NULL);
		printAll(queue);
	}

	printf("�߽���ԣ��ڿ�״̬�¼���delete��\n");
	serve(queue, NULL);//�߽����

	system("pause");
 	return 0;
}

//���ɳ���ΪMaxSize�Ŀն��У�
Queue* creatQueue(int maxSize) {
	Queue* queue = NULL;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->elements = (int*)malloc(sizeof(int) * maxSize);
	queue->maxSize = maxSize;
	queue->currentSize = 0;
	queue->first = 0;//��һ��Ԫ���������е��±�
	queue->last = -1;
	return queue;
}

// �ж϶���Q�Ƿ�������
int isFull(Queue* q) {
	return q->currentSize == q->maxSize;
}

// ������Ԫ��item�������Q�У�
void append(Queue* q, int item) {
	if (!isFull(q)) {
		q->last = ++q->last % q->maxSize;
		//Ϊ�˳�����ÿռ�ͼ��ٷ����������ƶ�
		//�±����1������󳤶�ȡ��
		//��������ʵ������ѭ���Ĵ�����������
		q->elements[q->last] = item;
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
int serve(Queue* q, int* firstItem) {
	int ret;
	if (!isEmpty(q)) {
		if (firstItem != NULL) {
			*firstItem = q->elements[q->first];
		}
		printf("delete %d\n", q->elements[q->first]);
		q->first = ++q->first % q->maxSize;
		//Ϊ�˷���۲��ӡ��Ϣ
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
	int i = q->first;
	int j = 0;
	if (!isEmpty(q)) {
		while (j < q->currentSize) {
			printf("element[%d] = %d\n", j++, q->elements[i]);
			i = ++i % q->maxSize;
		}
	} else {
		printf("Empty Queue\n");
	}
	printf("\n");
}