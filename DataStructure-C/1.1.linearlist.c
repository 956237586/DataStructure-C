/*���Ա�����ʵ��*/
#include <stdio.h>
#include "1.1.linearlist.h"

int main(){
	List tlist;
	List* list = &tlist;
	int i = 0;

	printf("�����ձ�\n");
	tlist = createList(10);
	printAll(list);
	printf("��Ϊ%d\n", getLength(list));

	printf("����Ԫ�أ�\n");
	for (i = 0; i < getLength(list); i++)
		set(list, i, i);
	printAll(list);

	printf("ɾ����3����\n");
	deleteElementAt(list, 3 - 1);
	printAll(list);

	printf("�ڵ�1��֮ǰ����һ��111��\n");
	insertInto(list, 1 - 1,111);
	printAll(list);

	printf("�����1��֮ǰ����һ��222��\n");
	insertInto(list, getLength(list)- 1, 222);
	printAll(list);

	printf("�ڵ�6��֮ǰ����һ��10��\n");
	insertInto(list, 6 - 1, 10);
	printAll(list);
	printf("10�ڵ�%d��λ�ã�\n\n", indexOf(list, 10) + 1);

	printf("ɾ����1����\n");
	deleteElementAt(list, 1 - 1);
	printAll(list);

	printf("��������333��\n");
	add(list, 333);
	printAll(list);

	printf("ɾ�����1����\n");
	deleteElementAt(list,getLength(list) - 1);
	printAll(list);

	system("pause");
	return 0;
}

// ��ʼ��һ������Ϊlenth���Ա�
List createList(int lenth){
	List list;
	int i = 0;
	list.lenth = lenth;
	list.elements = malloc(sizeof(int) * lenth);

	//��ʼ������Ϊ0
	for (i = 0; i < lenth; i++){
		list.elements[i] = 0;
	}
	return list;
}

// ����λ��index��������ӦԪ��,ʧ�ܷ���-1��
int get(List* l, int index){
	if (index >= 0 && index < getLength(l)){
		return l->elements[index];
	} else{
		return -1;
	}
}

// ����λ��index��������ӦԪ��,ʧ�ܷ���-1��
int set(List* l, int index, int x){
	if (index >= 0 && index < getLength(l)){
		return l->elements[index] = x;
	} else{
		return -1;
	}
}

//�����Ա�l�в���x�ĵ�һ�γ���λ��,�Ҳ�������-1
int indexOf(List* l, int x){
	int ret = -1;
	int i = 0;
	for (i = 0; i < getLength(l); i++){
		if (l->elements[i] == x){
			ret = i;
			break;
		}
	}
	return ret;
}

//��λ��indexǰ����һ����Ԫ��x��
void insertInto(List* l, int index, int x){
	int i = 0;
	if (index >= 0 && index <= getLength(l)){
		l->lenth++;//����+1
		l->elements = realloc(l->elements, (getLength(l) + 1)* sizeof(int));
		for (i = getLength(l) - 1; i > index; i--) //index����Ĳ����ճ���ע��λ��
			l->elements[i] = l->elements[i - 1];
		l->elements[index] = x;
	}
}

/*/
//��λ��indexǰ����һ����Ԫ��x��
void insertInto(List* l, int index, int x){
	int *telements = NULL;
	int i = 0;
	if (index >= 0 && index < getLength(l)){
		l->lenth++;//����+1
		telements = malloc(sizeof(int) * getLength(l));//�����µ��ڴ�ռ�
		for (i = 0; i < getLength(l); i++){//���ɲ�����±�
			if (i < index){//��index֮ǰ��Ԫ��ֱ�Ӹ���
				telements[i] = l->elements[i];
			} else if (i == index){//����indexʱ������µ�x
				telements[i] = x;
			} else{//index����Ĳ����ճ���ע��λ��
				telements[i] = l->elements[i - 1];
			}
		}
		free(l->elements);//�ͷžɵ��ڴ�
		l->elements = telements;//�����µı�
	}
}
//*/

//��������һ��Ԫ��x
void add(List* l, int x){
	insertInto(l, getLength(l), x);
}
//ɾ��ָ��λ��index��Ԫ�أ�
void deleteElementAt(List * l, int index){
	int i = 0;
	if (index >= 0 && index < getLength(l)){
		for (i = 0; i < getLength(l); i++)
			if (i == index)
				break;
		for (; i < getLength(l) - 1; i++)
			l->elements[i] = l->elements[i + 1];
		l->lenth--;
	}
}

//�������Ա�L�ĳ���n��
int getLength(List* l){
	return l->lenth;
}

//��ӡ���б�Ԫ��
void printAll(List* l){
	int i = 0;
	for (i = 0; i < getLength(l); i++)
		printf("element[%d] = %d\n", i, l->elements[i]);
	printf("\n");
}