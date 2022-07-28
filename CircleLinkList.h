#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//先创建链表的小结点  只有一个域
typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

//链表的结构体 接下来所有的操作都针对于这个结构体来说
typedef struct CIRCLELINKLIST
{
	//头结点
	CircleLinkNode head;
	int size;

}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
//这个回调函数是判断两个是否相等  参数两个  用来比较
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

//这个回调函数是用来打印输出结果的函数  参数一个  直接打印输出
typedef void(*PRINTNODE)(CircleLinkNode*);
//编写针对链表结构体操作的API函数
//初始化链表函数
CircleLinkList* Init_CircleLinkList();
//插入函数  参数 链表 位置（下标 从0开始） 数据类型 是个小结点
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
//获得第一个元素  返回值是CircleLinkNode* 类型
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
//删除  根据位置删除
void Remove_Bypos_CircleLinkList(CircleLinkList* clist, int pos);
//删除  根据值删除  不知道值是什么类型的  要交给用户 我们调用回调函数
void Remove_Byval_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data,COMPARENODE compaer);
//获取链表长度
int Size_CircleLinkList(CircleLinkList* clist);
//判断是否为空  用宏定义 true false 
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//查找  根据值
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compaer);
//打印结点 打印值不确定 交给用户
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);
//释放内存
void Free_CircleLinkList(CircleLinkList* clist);
