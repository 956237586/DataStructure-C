#ifndef queue2_h
#define queue2_h
#include <stdlib.h>
typedef struct _node {
	int element;
	struct _node* next;
} Node;

typedef struct _queue {
	int currentSize;//��ǰԪ�ظ���
	int maxSize;
	Node* first;//ָ���һ���ڵ��ָ��
	Node* last;
} Queue;

Queue* creatQueue(int maxSize); //���ɳ���ΪMaxSize�Ŀն��У�
int isFull(Queue* q); // �ж϶���Q�Ƿ�������
void add(Queue* q, int item);// ������Ԫ��item�������Q�У�
int isEmpty(Queue* q);// �ж϶���Q�Ƿ�Ϊ�գ�
int delete(Queue* q, int* firstItem); // ����ͷ����Ԫ�شӶ�����ɾ�������ء�
void printAll(Queue* q); //Ԥ�����е�ǰ״̬
#endif