#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include"struct.SHAPE.h"

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern  SHAPE shape[10000];
extern unsigned int count;
char whetherfill;//�����ȡֵ���ڴ���bool���͵�fill��ֵ

void choose_whetherfill(void)
{
	xyprintf(0, 90, "��Ҫ����𣿰�1����䣬��2�ǲ����");//ѯ���Ƿ�Ҫ���
	while (is_run())//���ѭ��ȷ��ֻ���ڻ�ȡ����ȷֵʱ���ܽ�����һ��
	{
		whetherfill = getch();//��ȡ��������ֵ

		if (whetherfill == '1')//���������1���Ͱ�trueд����Ӧ�Ľṹ�����������Ҫ��䣻
		{
			shape[count].fill = true;
			break;
		}
		else if (whetherfill == '2')//���������2���Ͱ�falseд����Ӧ�Ľṹ�������������䣻
		{
			shape[count].fill = false;
			break;
		}
	}
}