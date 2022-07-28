/*
* ���⣺m����Χ��һȦ�����ȵ�һ���˴�1��ʼ��һ����һ���˵İ���˳ʱ�뱨����������n���ˣ�������У�Ȼ��
* ����һ���˿�ʼ��1˳ʱ�뱨����������n���ˣ���������У��Դ����ƣ������˳��
* 
* ���� m  = 8  n = 3  �ӵ�ǰ1 ��ʼ��
*/
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM
{
	//�ڵ� �� ֵ
	CircleLinkNode node;  //������и�С�ڵ�
	int val;

}MyNum;

void MyPrint(CircleLinkNode*data)
{
	MyNum* num = (MyNum*)data;
	printf("%d ", num->val);
}
//����  ��������
int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2)
{
	//�ȰѴ��������ת���� �ٱȽ�
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
	//�ȴ���һ��ѭ������
	CircleLinkList* clist = Init_CircleLinkList();
	//���������������  12345678  ��Ϊ�õ�����ҵ���� Ҫд��typedef MyNum
	//��MyNum����һ������
	MyNum num[M];
	for (int i = 0; i < 8; i++)
	{
		//��ֵ�Ž�������
		num[i].val = i + 1;
		//�ٰ�������ݲ��뵽������
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
	}

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	//����Ҫ��¼��ǰ����ǵڼ����� ��N����ϵ  �����ڼ�����
	int index = 1;
	//����ָ�� ����ʶ��ǰλ�� Ҫ��һ���� ��ͷ�ڵ����һ�� ��Ϊͷ�ڵ㲻�������
	CircleLinkNode* pCurrent = clist->head.next;
	//�����������һ �ͼ���ѭ��  �൱��ѭ���������size����һ
	while (Size_CircleLinkList(clist) > 1)
	{
		if (index == N) //����������N���� �൱���ҵ�Ҫ������Ǹ����� Ҫ���
		{
			//��ָ������ǿת��MyNum���� Ȼ�����
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//������Ҫɾ����ǰ����ڵ�  ������Ҫ������һ���ڵ��λ��  ��Ȼһɾ���ͶϿ���
			//�����ɾ���ڵ����һ���ڵ� Ҫɾ���Ľڵ���pCurrent
			CircleLinkNode* pNext = pCurrent->next;
			//����ֵȥɾ��
			Remove_Byval_CircleLinkList(clist, pCurrent, MyCompare);
			//ɾ���� ָ�����
			//���ʱ��Ҫ�ж�pNext�ǲ��ǵ���ͷ�ڵ� ������� Ҫ����
			pCurrent = pNext;
			if (pCurrent = &(clist->head))
			{
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		pCurrent = pCurrent->next;
		//�ж��Ƿ�ͷ�ڵ�
		if (pCurrent = &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		index = 1;
		index++;

	}
	if (Size_CircleLinkList(clist) == 1)
	{
		//��߾�ʣ��һ��Ԫ���� ֱ�ӷ��ؽ����е�Ԫ�ؾ���
		MyNum* tempnum = (MyNum*)Front_CircleLinkList(clist);
		printf("%d ", tempnum->val);

	}
	else
	{
		printf("����\n");
	}
	//�ͷ������ڴ�
	Free_CircleLinkList(clist);

	return 0;
}