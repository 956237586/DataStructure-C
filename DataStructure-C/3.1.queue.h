#ifndef queue1_h
#define queue1_h

typedef struct _queue {
	int currentSize;//当前元素个数
	int maxSize;
	int first;
	int last;
	int* elements;
} Queue;

Queue* creatQueue(int maxSize); //生成长度为MaxSize的空队列；
int isFull(Queue* q); // 判断队列Q是否已满；
void add(Queue* q, int item);// 将数据元素item插入队列Q中；
int isEmpty(Queue* q);// 判断队列Q是否为空；
int delete(Queue* q, int* firstItem); // 将队头数据元素从队列中删除并返回。
void printAll(Queue* q); //预览队列当前状态
#endif