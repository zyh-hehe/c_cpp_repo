#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern  SHAPE shape[10000];
extern unsigned int count;

//����ѡ�������ͼ����ɫ�ĺ���
//���������ѡ����ɫʱ������ɫ������ɫһ������ã�����Ϊ�˷���ʵ�ִ��븴�ã�������дһ��ѡ���ɫ�ĺ���
void choosecolor(void)
{
	xyprintf(0, 90, "��Ҫɶ��ɫ�أ�1.��ɫ 2.��ɫ 3.��ɫ 4.��ɫ 5.��ɫ");
	char color;
	while (is_run())
	{
		color = getch();
		if (color == '1')
		{
			//���ǽ���ѡ��ɫ���
			setcolor(RED);
			xyprintf(210, 90, "1.��ɫ");
			//�������뽫���ɫ������ɫ���ú�
			setcolor(BLACK);
			setfillcolor(BLACK);
			shape[count].color = 1;
			break;
		}
		else if (color == '2')
		{
			//���ǽ���ѡ��ɫ���
			setcolor(RED);
			xyprintf(315, 90, "2.��ɫ");
			//�������뽫���ɫ������ɫ���ú�
			setfillcolor(RED);
			shape[count].color = 2;
			break;
		}
		else if (color == '3')
		{
			//���ǽ���ѡ��ɫ���
			setcolor(RED);
			xyprintf(420, 90, "3.��ɫ");
			setcolor(GREEN);
			setfillcolor(GREEN);
			shape[count].color = 3;
			break;
		}
		else if (color == '4')
		{
			//���ǽ���ѡ��ɫ���
			setcolor(RED);
			xyprintf(525, 90, "4.��ɫ");
			//�������뽫���ɫ������ɫ���ú�
			setcolor(BLUE);
			setfillcolor(BLUE);
			shape[count].color = 4;
			break;
		}
		else if (color == '5')
		{
			//���ǽ���ѡ��ɫ���
			setcolor(RED);
			xyprintf(630, 90, "5.��ɫ");
			//�������뽫���ɫ������ɫ���ú�
			setcolor(CYAN);
			setfillcolor(CYAN);
			shape[count].color = 5;
			break;
		}
	}
}

