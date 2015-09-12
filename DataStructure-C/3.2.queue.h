#ifndef queue2_h
#define queue2_h
#include <stdlib.h>
typedef struct _node {
	int element;
	struct _node* next;
} Node;

typedef struct _queue {
	int currentSize;//当前元素个数
	int maxSize;
	Node* first;//指向第一个节点的指针
	Node* last;
} Queue;

Queue* creatQueue(int maxSize); //生成长度为MaxSize的空队列；
int isFull(Queue* q); // 判断队列Q是否已满；
void add(Queue* q, int item);// 将数据元素item插入队列Q中；
int isEmpty(Queue* q);// 判断队列Q是否为空；
int delete(Queue* q, int* firstItem); // 将队头数据元素从队列中删除并返回。
void printAll(Queue* q); //预览队列当前状态
#endif