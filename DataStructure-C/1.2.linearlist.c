/*线性表，链表实现*/
#include <stdio.h>
#include "1.2.linearlist.h"

int main(){
	List tlist;
	List* list = &tlist;
	int i = 0;

	printf("创建空表：\n");
	tlist = createList(10);
	printAll(list);


	printf("设置元素：\n");
	for (i = 0; i < 10; i++)
		listAddNode(list, i);
	printAll(list);
	printf("表长为%d\n", getLength(list));

	printf("删除第3个：\n");
	delNodeById(list, 3 - 1);
	printAll(list);

	printf("在第1个之前插入一个111：\n");
	insertInto(list, 1 - 1, 111);
	printAll(list);

	printf("在最后1个之前插入一个222：\n");
	insertInto(list, getLength(list) - 1, 222);
	printAll(list);

	printf("在第6个之前插入一个10：\n");
	insertInto(list, 6 - 1, 10);
	printAll(list);

	printf("删除第1个：\n");
	delNodeById(list, 1 - 1);
	printAll(list);

	printf("在最后加入333：\n");
	listAddNode(list, 333);
	printAll(list);

	printf("删除最后1个：\n");
	delNodeById(list, getLength(list) - 1);
	printAll(list);

	system("pause");
	return 0;
}

// 初始化一个长度为0线性表；
List createList(){
	List* pList;
	pList = (List*)malloc(sizeof(List));
	listInit(pList);
	return *pList;
}

//初始化内容为0
void listInit(List* pList){
	pList->head = pList->last = NULL;
	pList->len = 0;
}

//创建一个节点
Node* createNode(int number){
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	return p;
}

//取得指定节点的前一个
Node* findNodeFrontOf(List* pList, Node* node){
	Node* t = pList->head;
	Node* ret = NULL;
	if (t != node){//如果不是头结点
		while (t){
			if (t->next == node){
				ret = t;
				break;
			}
			t = t->next;
		}
	}
	return ret;//如果是头结点
}

//根据位序inde,返回相应节点的指针，找不到返回NULL
Node* findNodeById(List* l, int index){
	Node * node = l->head;
	Node * ret = NULL;
	int i = 0;
	if (index >= 0 && index < getLength(l)){
		while (node){
			if (i++ == index){
				ret = node;
				break;
			}
			node = node->next;
		}
	}
	return ret;
}

//根据value找到链表中的节点，找不到返回NULL
Node* findNodeByValue(List* pList, int value){
	Node* node = pList->head;
	Node* ret = NULL;
	while (node){
		if (node->value == value){
			ret = node;
			break;
		}
		node = node->next;
	}
	return ret;
}

//返回线性表L的长度n。
int getLength(List* pList){
	return pList->len;
}

//打印所有表元素
void printAll(List* pList){
	Node* t = NULL;
	int i = 0;
	t = pList->head;
	while (t){
		printf("element[%d] = %d\n", i++, t->value);
		t = t->next;
	}
	printf("\n");
}

//删除指定的节点
int delNode(List* pList, Node* del){
	int ret = -1;
	if (del){
		if (del == pList->head){
			pList->head = del->next;
		} else if (del == pList->last){
			pList->last = findNodeFrontOf(pList, del);
			pList->last->next = NULL;
		} else {
			findNodeFrontOf(pList, del)->next = del->next;
		}
		if (pList->len == 1 && pList->head == del){
			listInit(pList);
		}
		pList->len--;
		free(del);
		ret = 1;
	}
	return ret;
}

int delNodeById(List* pList, int index)
{
	Node* del = findNodeById(pList, index);
	return delNode(pList, del);
}

int delNodeByValue(List* pList, int value){
	Node* del = findNodeByValue(pList, value);
	return delNode(pList, del);
}

// 根据位序index，返回相应元素,失败返回-1；
int getNodeValueById(List* pList, int index){
	return findNodeById(pList, index)->value;
}

// 根据位序index，设置相应元素,失败返回-1；
void setNodeValueById(List* pList, int index, int value){
	findNodeById(pList, index)->value = value;
}

//在尾部添加一个节点
void listAddNode(List* pList, int number)
{
	insertInto(pList, getLength(pList), number);
}

//在位序index前插入一个新元素x；
void insertInto(List* pList, int index, int x){
	Node* newNode = createNode(x);
	Node* node = NULL;
	if (index >= 0 && index <= getLength(pList)){
		if (pList->len == 0){//如果是空表
			pList->head = pList->last = newNode;
		} else if (index == 0){
			newNode->next = pList->head;
			pList->head = newNode;
		}else{
			node = findNodeById(pList, index - 1);
			newNode->next = node->next;
			node->next = newNode;
		}
	}
	pList->len++;
}
