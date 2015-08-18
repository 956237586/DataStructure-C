/*���Ա�����ʵ��*/
#include <stdio.h>
#include "1.2.linearlist.h"

int main(){
	List tlist;
	List* list = &tlist;
	int i = 0;

	printf("�����ձ�\n");
	tlist = createList(10);
	printAll(list);


	printf("����Ԫ�أ�\n");
	for (i = 0; i < 10; i++)
		listAddNode(list, i);
	printAll(list);
	printf("��Ϊ%d\n", getLength(list));

	printf("ɾ����3����\n");
	delNodeById(list, 3 - 1);
	printAll(list);

	printf("�ڵ�1��֮ǰ����һ��111��\n");
	insertInto(list, 1 - 1, 111);
	printAll(list);

	printf("�����1��֮ǰ����һ��222��\n");
	insertInto(list, getLength(list) - 1, 222);
	printAll(list);

	printf("�ڵ�6��֮ǰ����һ��10��\n");
	insertInto(list, 6 - 1, 10);
	printAll(list);

	printf("ɾ����1����\n");
	delNodeById(list, 1 - 1);
	printAll(list);

	printf("��������333��\n");
	listAddNode(list, 333);
	printAll(list);

	printf("ɾ�����1����\n");
	delNodeById(list, getLength(list) - 1);
	printAll(list);

	system("pause");
	return 0;
}

// ��ʼ��һ������Ϊ0���Ա�
List createList(){
	List* pList;
	pList = (List*)malloc(sizeof(List));
	listInit(pList);
	return *pList;
}

//��ʼ������Ϊ0
void listInit(List* pList){
	pList->head = pList->last = NULL;
	pList->len = 0;
}

//����һ���ڵ�
Node* createNode(int number){
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	return p;
}

//ȡ��ָ���ڵ��ǰһ��
Node* findNodeFrontOf(List* pList, Node* node){
	Node* t = pList->head;
	Node* ret = NULL;
	if (t != node){//�������ͷ���
		while (t){
			if (t->next == node){
				ret = t;
				break;
			}
			t = t->next;
		}
	}
	return ret;//�����ͷ���
}

//����λ��inde,������Ӧ�ڵ��ָ�룬�Ҳ�������NULL
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

//����value�ҵ������еĽڵ㣬�Ҳ�������NULL
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

//�������Ա�L�ĳ���n��
int getLength(List* pList){
	return pList->len;
}

//��ӡ���б�Ԫ��
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

//ɾ��ָ���Ľڵ�
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

// ����λ��index��������ӦԪ��,ʧ�ܷ���-1��
int getNodeValueById(List* pList, int index){
	return findNodeById(pList, index)->value;
}

// ����λ��index��������ӦԪ��,ʧ�ܷ���-1��
void setNodeValueById(List* pList, int index, int value){
	findNodeById(pList, index)->value = value;
}

//��β�����һ���ڵ�
void listAddNode(List* pList, int number)
{
	insertInto(pList, getLength(pList), number);
}

//��λ��indexǰ����һ����Ԫ��x��
void insertInto(List* pList, int index, int x){
	Node* newNode = createNode(x);
	Node* node = NULL;
	if (index >= 0 && index <= getLength(pList)){
		if (pList->len == 0){//����ǿձ�
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
