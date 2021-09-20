#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

void clearandredraw(void);
void redraw_color();

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern  SHAPE shape[10000];
extern unsigned int count;
int j;//���j�������������������ﶼ�õ��ˣ�����д��ȫ�ֱ������������ж�ѭ�������ͺ�ʱ����

//�����߼�������֮���ػ�ͼ���������ڶ���
void clearandredraw(void)
{
	cleardevice();
	//��������ѭ��ʱ�����ػ�ͼ�ε�
	for (j = 1; j < count; j++)
	{
		if (shape[j].type == 1)//ʶ���ͼ�ε�����
		{
			redraw_color();//������������棬������ʶ���ͼ�ε���ɫ
			//�ػ�
			if (shape[j].fill == true)
			{
				redraw_color();//������������棬������ʶ���ͼ�ε���ɫ
				bar(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y2);
			}
			else
			{
				line(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y1);
				line(shape[j].x1, shape[j].y1, shape[j].x1, shape[j].y2);
				line(shape[j].x1, shape[j].y2, shape[j].x2, shape[j].y2);
				line(shape[j].x2, shape[j].y2, shape[j].x2, shape[j].y1);
			}
		}
		else if (shape[j].type == 2)//ʶ���ͼ�ε�����
		{
			redraw_color();//������������棬������ʶ���ͼ�ε���ɫ
			//�ػ�
			if (shape[j].fill == true)
				fillellipse(shape[j].centerx, shape[j].centery, shape[j].radius, shape[j].radius);
			else
				circle(shape[j].centerx, shape[j].centery, shape[j].radius);
		}
		else if (shape[j].type == 3)//ʶ���ͼ�ε�����
		{
			redraw_color();
			//����ȡ������д�����������ʱ���飬Ȼ��3���ߵĶ����
			int pt[8] =
			{
				shape[j].x1,shape[j].y1,
				shape[j].x2,shape[j].y2,
				shape[j].x3,shape[j].y3,
				shape[j].x1,shape[j].y1,
			};
			//�ػ�
			if (shape[j].fill == true)
				fillpoly(4, pt);
			else
				drawpoly(4, pt);
		}
		else if (shape[j].type == 4)//ʶ���ͼ�ε�����
		{
			redraw_color();//������������棬������ʶ���ͼ�ε���ɫ
			//�ػ�
			line(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y2);
		}
		else if (shape[j].type == 5)//ʶ���ͼ�ε�����
		{
			redraw_color();//������������棬������ʶ���ͼ�ε���ɫ
			int l;
			int m;
			int polypt[42];
			for (l = 0, m = 0; m < shape[j].side; l = l + 2, m = m + 1)
			{
				polypt[l] = shape[j].point[m][0];
				polypt[l + 1] = shape[j].point[m][1];
			}
			polypt[(2 * shape[j].side)] = shape[j].point[0][0];
			polypt[(2 * shape[j].side) + 1] = shape[j].point[0][1];
			//�ػ�
			setviewport(0, 125, 10000, 10000);
			if (shape[j].fill)
				fillpoly(shape[j].side + 1, polypt);
			else
				drawpoly(shape[j].side + 1, polypt);
			setviewport(0, 0, 10000, 10000);
		}
	}
	//����ɫ���û���
	setcolor(BLACK);
	setfillcolor(WHITE);
}

void redraw_color(void)//���ݶ�Ӧ����������ɫ
{
	switch (shape[j].color)
	{
	case 1:
		setfillcolor(BLACK);
		setcolor(BLACK);
		break;
	case 2:
		setfillcolor(RED);
		setcolor(RED);
		break;
	case 3:
		setcolor(GREEN);
		setfillcolor(GREEN);
		break;
	case 4:
		setfillcolor(BLUE);
		setcolor(BLUE);
		break;
	case 5:
		setfillcolor(CYAN);
		setcolor(CYAN);
		break;
	}
}
