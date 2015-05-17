#include <stdio.h>
#include "1.2.linearlist.h"

int main(){
	List tlist;
	List* list = &tlist;
	int i = 0;

	printf_s("�����ձ�\n");
	tlist = createList();
	printf_s("����Ԫ�أ�\n");
	for (i = 0; i < 10; i++)
		listAddNode(list, i);
	printList(list);
	printf_s("��Ϊ%d\n", getLength(list));

	printf_s("ɾ����3����\n");
	delNodeById(list, 3 - 1);
	printList(list);

	printf_s("�ڵ�6��֮ǰ����һ��10��\n");
	insertInto(list, 6 - 1, 10);
	printList(list);

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

//��β�����һ���ڵ�
void listAddNode(List* pList, int number)
{
	Node *p = createNode(number);
	if (pList->last){
		pList->last->next = p;
		pList->last = pList->last->next;
	} else{
		pList->head = pList->last = p;
	}
	pList->len++;
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
	Node* t = pList->head;
	Node* ret = NULL;
	while (t){
		if (t->value == value){
			ret = t;
			break;
		}
		t = t->next;
	}
	return ret;
}

//�������Ա�L�ĳ���n��
int getLength(List* pList){
	return pList->len;
}

//��ӡ���б�Ԫ��
void printList(List* pList){
	Node* t = NULL;
	int i = 0;
	t = pList->head;
	while (t){
		printf("%5d %5d\n", i++, t->value);
		t = t->next;
	}
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
	int ret = 0;
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

//��λ��indexǰ����һ����Ԫ��x��
void insertInto(List* pList, int index, int x){
	Node* node2 = findNodeById(pList, index);
	Node* node1 = findNodeFrontOf(pList, node2);
	Node* newNode = createNode(x);
	if (index == 0){
		newNode->next = pList->head;
		pList->head = newNode;
	} else{
		newNode->next = node2;
		node1->next = newNode;
	}
	pList->len++;
}
