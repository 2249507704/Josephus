/*
* 例题：m个人围成一圈，首先第一个人从1开始，一个人一个人的按照顺时针报数，报到第n个人，令其出列，然后
* 从下一个人开始从1顺时针报数，报到第n个人，再令其出列，以此类推，求出列顺序
* 
* 假设 m  = 8  n = 3  从当前1 开始数
*/
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM
{
	//节点 和 值
	CircleLinkNode node;  //这里边有个小节点
	int val;

}MyNum;

void MyPrint(CircleLinkNode*data)
{
	MyNum* num = (MyNum*)data;
	printf("%d ", num->val);
}
//参数  两个数据
int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2)
{
	//先把传入的数据转换了 再比较
	MyNum* num1 = (MyNum*)data1;
	MyNum* num2 = (MyNum*)data2;
	if (num1->val == num2->val)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;

}
int main()
{
	//先创建一个循环链表
	CircleLinkList* clist = Init_CircleLinkList();
	//往链表里插入数据  12345678  因为用的是企业链表 要写个typedef MyNum
	//用MyNum创建一个数组
	MyNum num[M];
	for (int i = 0; i < 8; i++)
	{
		//把值放进数组里
		num[i].val = i + 1;
		//再把这个数据插入到链表里
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	//打印
	Print_CircleLinkList(clist, MyPrint);

	//首先要记录当前这个是第几个人 和N有联系  报到第几个人
	int index = 1;
	//辅助指针 来标识当前位置 要第一个人 是头节点的下一个 因为头节点不存放数据
	CircleLinkNode* pCurrent = clist->head.next;
	//如果人数大于一 就继续循环  相当于循环链表里的size大于一
	while (Size_CircleLinkList(clist) > 1)
	{
		if (index == N) //报数报到第N个了 相当于找到要输出的那个人了 要输出
		{
			//把指针类型强转成MyNum类型 然后输出
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//输出完后要删除当前这个节点  所以先要缓存下一个节点的位置  不然一删掉就断开了
			//缓存待删除节点的下一个节点 要删除的节点是pCurrent
			CircleLinkNode* pNext = pCurrent->next;
			//根据值去删除
			Remove_Byval_CircleLinkList(clist, pCurrent, MyCompare);
			//删掉后 指针后移
			//这个时候要判断pNext是不是等于头节点 如果等于 要跳过
			pCurrent = pNext;
			if (pCurrent = &(clist->head))
			{
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		pCurrent = pCurrent->next;
		//判断是否头节点
		if (pCurrent = &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		index = 1;
		index++;

	}
	if (Size_CircleLinkList(clist) == 1)
	{
		//里边就剩下一个元素了 直接返回仅仅有的元素就行
		MyNum* tempnum = (MyNum*)Front_CircleLinkList(clist);
		printf("%d ", tempnum->val);

	}
	else
	{
		printf("出错！\n");
	}
	//释放链表内存
	Free_CircleLinkList(clist);

	return 0;
}