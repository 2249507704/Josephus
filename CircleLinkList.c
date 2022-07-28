#include "CircleLinkList.h"
CircleLinkList* Init_CircleLinkList()
{
	//�õ�����ҵ���� ֻҪ������ṹ������ڴ����
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));

	//������ڵ�ָ���Լ�  ��Ϊ��ֵ��ָ��  �����ұ�Ҫȡ��ַ
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

	//����λ�ò���  ��Ҫ��ֵָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//�����ݲ�������
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
	//����pos�ҽڵ�
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//ɾ��  Ҫ���Ȼ��浱ǰ�ڵ� pNext��Ҫɾ���Ľڵ�
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

	//�����ѭ������ ��������ֵָ�����  ��Ϊ����Ǹ���ֵ�ж�  ��һ���ڵ㲻������� ���Դ�ͷ�ڵ��next��ʼ
	//
	CircleLinkNode* pPrev = &(clist->head); //��ɾ���ڵ��ǰһ���ڵ�
	CircleLinkNode* pCurrent = pPrev->next;
	int i = 0;
	int flag = -1;
	for ( i = 0; i < clist->size; i++)
	{
		//ͨ���ص��������Ƚ�PCurrent��data�Ƿ���ͬ
		if (compaer(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		//û�ҵ��Ļ� ָ�����  ����������
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
	////��ʼɾ������ pNext��Ҫɾ���Ľڵ�
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
	//��ʼ����
	int i = 0;
	int flag = -1;
	CircleLinkNode* pCurrent = clist->head.next;
	for ( i = 0; i < clist->size; i++)
	{
		if (compaer(pCurrent,data) == CIRCLELINKLIST_TRUE) //˵���ҵ��� ����һ��flag����
		{
			flag = i;
			break;
		}
		else
		{
			pCurrent = pCurrent->next;
		}
	}
	return flag;  //�����Ƿ��ҵ��ı�־
}

void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}
	//��ӡ���  ��ʼ����  ��Ҫһ������ָ��
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		//ʹ�ûص����� ������ָ�����
		print(pCurrent);
		//ָ��������
		pCurrent = pCurrent->next;
	}
	////���Ҫ��ӡ����
	//for (int i = 0; i < clist->size * 2; i++)
	//{
	//	if (i == clist->size)  //����Ҳ������ָ��������  pCurrent == &(clist->head)
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
