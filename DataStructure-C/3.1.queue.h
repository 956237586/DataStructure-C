#ifndef queue1_h
#define queue1_h
#include <stdio.h>
#include <stdlib.h>
typedef struct _queue {
	int currentSize;//��ǰԪ�ظ���
	int maxSize;
	int first;
	int last;
	int* elements;
} Queue;

Queue* creatQueue(int maxSize); //���ɳ���ΪMaxSize�Ŀն��У�
int isFull(Queue* q); // �ж϶���Q�Ƿ�������
void append(Queue* q, int item);// ������Ԫ��item�������Q�У�
int isEmpty(Queue* q);// �ж϶���Q�Ƿ�Ϊ�գ�
int serve(Queue* q, int* firstItem); // ����ͷ����Ԫ�شӶ�����ɾ�������ء�
void printAll(Queue* q); //Ԥ�����е�ǰ״̬
#endif