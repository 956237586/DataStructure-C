#include <stdio.h>
#include "1.1.linearlist.h"

int main(){
	List tlist;
	List* list = &tlist;
	int i = 0;

	printf_s("创建空表：\n");
	tlist = createList(10);
	printAll(list);
	printf_s("表长为%d\n", getLength(list));

	printf_s("设置元素：\n");
	for (i = 0; i < getLength(list); i++)
		set(list, i, i);
	printAll(list);

	printf_s("删除第3个：\n");
	deleteElementAt(list, 3 - 1);
	printAll(list);

	printf_s("在第6个之前插入一个10：\n");
	insertInto(list, 6 - 1, 10);
	printAll(list);
	printf_s("10在第%d个位置：\n\n", indexOf(list, 10) + 1);

	system("pause");
	return 0;
}

// 初始化一个长度为lenth线性表；
List createList(int lenth){
	List list;
	int i = 0;
	list.lenth = lenth;
	list.elements = malloc(sizeof(int) * lenth);

	//初始化内容为0
	for (i = 0; i < lenth; i++){
		list.elements[i] = 0;
	}
	return list;
}

// 根据位序index，返回相应元素,失败返回-1；
int get(List* l, int index){
	if (index < getLength(l)){
		return l->elements[index];
	} else{
		return -1;
	}
}

// 根据位序index，设置相应元素,失败返回-1；
int set(List* l, int index, int x){
	if (index < getLength(l)){
		return l->elements[index] = x;
	} else{
		return -1;
	}
}
//在线性表l中查找x的第一次出现位置；
int indexOf(List* l, int x){
	int i = 0;
	for (i = 0; i < getLength(l); i++){
		if (l->elements[i] == x)
			break;
	}
	return i;
}

//在位序index前插入一个新元素x；
void insertInto(List* l, int index, int x){
	int *telements = NULL;
	int i = 0;
	if (index < getLength(l)){
		l->lenth++;//表长度+1
		telements = malloc(sizeof(int) * getLength(l));//分配新的内存空间
		for (i = 0; i < getLength(l); i++){//生成插入后新表
			if (i < index){//在index之前的元素直接复制
				telements[i] = l->elements[i];
			} else if (i == index){//等于index时候插入新的x
				telements[i] = x;
			} else{//index后面的部分照抄，注意位置
				telements[i] = l->elements[i - 1];
			}
		}
		free(l->elements);//释放旧的内存
		l->elements = telements;//换成新的表
	}
}

//删除指定位序index的元素；
void deleteElementAt(List * l, int index){
	int i = 0;
	if (index < getLength(l)){
		for (i = 0; i < getLength(l); i++)
			if (i == index)
				break;
		for (; i < getLength(l) - 1; i++)
			l->elements[i] = l->elements[i + 1];
		l->lenth--;
	}
}

//返回线性表L的长度n。
int getLength(List* l){
	return l->lenth;
}

//打印所有表元素
void printAll(List* l){
	int i = 0;
	for (i = 0; i < getLength(l); i++)
		printf_s("element[%d] = %d\n", i, l->elements[i]);
	printf_s("\n");
}