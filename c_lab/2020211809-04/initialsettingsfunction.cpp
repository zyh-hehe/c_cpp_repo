#include<stdio.h>
#include"graphics.h"
//��ʼ�����ú���
void initialsettings(void)
{
	initgraph(-1, -1);//����Ϊȫ��
	setbkcolor(WHITE);//����Ϊ��ɫ
	setcolor(BLACK);//�����Ǻڵ�
	setfont(30, 0, "����");//�����С����������
}