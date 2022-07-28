#include "CircleLinkList.h"
CircleLinkList* Init_CircleLinkList()
{
	//用的是企业链表 只要给链表结构体分配内存就行
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));

	//让这个节点指向自己  因为左值是指针  所以右边要取地址
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > clist->size)
	{
		return;
	}

	//根据位置查找  需要赋值指针变量
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//把数据插入链表
	data->next = pCurrent->next;
	pCurrent->next = data;
	clist->size++;
}

CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}

void Remove_Bypos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		return;
	}
	//根据pos找节点
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//删除  要事先缓存当前节点 pNext是要删除的节点
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	clist->size--;
}

void Remove_Byval_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compaer)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//这个是循环链表 先来个赋值指针变量  因为这个是根据值判断  第一个节点不存放数据 所以从头节点的next开始
	//
	CircleLinkNode* pPrev = &(clist->head); //被删除节点的前一个节点
	CircleLinkNode* pCurrent = pPrev->next;
	int i = 0;
	int flag = -1;
	for ( i = 0; i < clist->size; i++)
	{
		//通过回调函数来比较PCurrent和data是否相同
		if (compaer(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		//没找到的话 指针后移  交叉往后移
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
	////开始删除操作 pNext是要删除的节点
	//CircleLinkNode* pNext = pCurrent->next;
	//pCurrent->next = pNext->next;
	//clist->size--;
}

int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}

int IsEmpty_CircleLinkList(CircleLinkList* clist)
{
	if (clist->size == 0)
	{
		return 1;
	}
	return 0;
}

int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compaer)
{
	if (clist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	//开始遍历
	int i = 0;
	int flag = -1;
	CircleLinkNode* pCurrent = clist->head.next;
	for ( i = 0; i < clist->size; i++)
	{
		if (compaer(pCurrent,data) == CIRCLELINKLIST_TRUE) //说明找到了 增加一个flag变量
		{
			flag = i;
			break;
		}
		else
		{
			pCurrent = pCurrent->next;
		}
	}
	return flag;  //返回是否找到的标志
}

void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}
	//打印输出  开始遍历  需要一个辅助指针
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		//使用回调函数 将辅助指针放入
		print(pCurrent);
		//指针往后移
		pCurrent = pCurrent->next;
	}
	////如果要打印两次
	//for (int i = 0; i < clist->size * 2; i++)
	//{
	//	if (i == clist->size)  //这里也可以用指针来表述  pCurrent == &(clist->head)
	//	{
	//		pCurrent = pCurrent->next;
	//	}
	//	print(pCurrent);
	//	pCurrent = pCurrent->next;
	//}
}

void Free_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}
