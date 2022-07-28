#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ȴ��������С���  ֻ��һ����
typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

//����Ľṹ�� ���������еĲ��������������ṹ����˵
typedef struct CIRCLELINKLIST
{
	//ͷ���
	CircleLinkNode head;
	int size;

}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
//����ص��������ж������Ƿ����  ��������  �����Ƚ�
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

//����ص�������������ӡ�������ĺ���  ����һ��  ֱ�Ӵ�ӡ���
typedef void(*PRINTNODE)(CircleLinkNode*);
//��д�������ṹ�������API����
//��ʼ��������
CircleLinkList* Init_CircleLinkList();
//���뺯��  ���� ���� λ�ã��±� ��0��ʼ�� �������� �Ǹ�С���
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
//��õ�һ��Ԫ��  ����ֵ��CircleLinkNode* ����
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);
//ɾ��  ����λ��ɾ��
void Remove_Bypos_CircleLinkList(CircleLinkList* clist, int pos);
//ɾ��  ����ֵɾ��  ��֪��ֵ��ʲô���͵�  Ҫ�����û� ���ǵ��ûص�����
void Remove_Byval_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data,COMPARENODE compaer);
//��ȡ������
int Size_CircleLinkList(CircleLinkList* clist);
//�ж��Ƿ�Ϊ��  �ú궨�� true false 
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//����  ����ֵ
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compaer);
//��ӡ��� ��ӡֵ��ȷ�� �����û�
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);
//�ͷ��ڴ�
void Free_CircleLinkList(CircleLinkList* clist);
