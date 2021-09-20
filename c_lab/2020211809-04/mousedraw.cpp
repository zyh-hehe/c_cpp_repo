#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include<math.h>
#include"struct.SHAPE.h"

void choosecolor(void);
void get2point(void);
void restore(void);

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern  SHAPE shape[10000];
extern unsigned int count;

//���ǻ������εĺ���
void drawbar(void)
{
	choosecolor();//����ѡ��ɫ
	get2point();//������������棬������ȡ�����㲢���������д���Ӧ�Ľṹ������

	if (shape[count].fill)//�����ȡ����������Ҫ��䣬�ͻ�һ����䳤����
		bar(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y2);
	else//���򣬾ͻ��ĸ����γ�һ�������ĳ�����
	{
		//��������õ������껭�ĸ��ߣ��γ�һ�������ĳ�����
		line(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y1);
		line(shape[count].x1, shape[count].y1, shape[count].x1, shape[count].y2);
		line(shape[count].x1, shape[count].y2, shape[count].x2, shape[count].y2);
		line(shape[count].x2, shape[count].y2, shape[count].x2, shape[count].y1);
	}
	restore();//�������Ҳ�����棬��Ϊ�˰�������ɫ�������ɫ���ûس�ʼֵ
}

//���ǻ�Բ�ĺ���
void drawcircle(void)
{
	int a;//���a����ֻ�������䵱�ڼ���뾶ʱ���м�ֵ�������������ﲢû���õ��������Ұ����������˺�������һ���ֲ�����
	choosecolor();//����ѡ��ɫ
	get2point();//������������棬������ȡ�����㲢���������д���Ӧ�Ľṹ������

	shape[count].centerx = (shape[count].x1 + shape[count].x2) / 2;//����Բ�ĵ�X����
	shape[count].centery = (shape[count].y1 + shape[count].y2) / 2;//����Բ�ĵ�Y����
	a = (shape[count].x1 - shape[count].x2) * (shape[count].x1 - shape[count].x2) + (shape[count].y1 - shape[count].y2) * (shape[count].y1 - shape[count].y2);//���ɶ�����㺯���뾶
	shape[count].radius = sqrt(a) / 2;//���ɶ������뾶

	if (shape[count].fill)//�����ȡ����������Ҫ��䣬�ͻ�һ�����Բ
		//��EGE���ﲢû�л����Բ�ĺ�����������ֻ�ܻ�һ����������ȵ���Բ�γ�һ��Բ
		fillellipse(shape[count].centerx, shape[count].centery, shape[count].radius, shape[count].radius);
	else//���򣬾ͻ�һ��Բ
		circle(shape[count].centerx, shape[count].centery, shape[count].radius);
	restore();//�������Ҳ�����棬��Ϊ�˰�������ɫ�������ɫ���ûس�ʼֵ
}

//���ǻ��ߵĺ���
void drawline(void)
{
	choosecolor();//����ѡ��ɫ
	get2point();//������������棬������ȡ�����㲢���������д���Ӧ�Ľṹ������
	line(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y2);
	restore();//�������Ҳ�����棬��Ϊ�˰�������ɫ�������ɫ���ûس�ʼֵ
}

//���ǻ������εĺ���
void drawtriangle(void)
{
	choosecolor();
	//�����ε�����ȷ���ǿ����������꣬�ͳ����Σ�Բ���ߵĵ��ȡ�߼���ͬ������Ҫ����д�����������ȡ������
	int i = 0;
	mouse_msg msg;
	for (; is_run(); delay_fps(120))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
			msg = getmouse();
		//�����ǻ�ȡ��갴��ȥʱ������λ��
		if (i == 0 && msg.is_left() && msg.is_down())
		{
			shape[count].x1 = msg.x;
			shape[count].y1 = msg.y;
			i++;
		}
		//�����ǻ�ȡ����ɿ�ʱ������λ��
		else if (i == 1 && msg.is_left() && msg.is_down())
		{
			shape[count].x2 = msg.x;
			shape[count].y2 = msg.y;
			i++;
		}
		else if (i == 2 && msg.is_left() && msg.is_down())
		{
			shape[count].x3 = msg.x;
			shape[count].y3 = msg.y;
			i++;
		}
		if (i == 3)
			break;
	}

	//����ȡ������д�����������ʱ���飬Ȼ��3���ߵĶ����
	int pt[8] =
	{
		shape[count].x1,shape[count].y1,
		shape[count].x2,shape[count].y2,
		shape[count].x3,shape[count].y3,
		shape[count].x1,shape[count].y1,
	};

	if (shape[count].fill)//�����ȡ������������䣬�ͻ�һ�����������
		fillpoly(4, pt);
	else//���򣬾ͻ�һ��������������
		drawpoly(4, pt);
	restore();//�������Ҳ�����棬��Ϊ�˰�������ɫ�������ɫ���ûس�ʼֵ
}

//�����ܻ�ȡ����������ĺ������������˻������Σ��ߺ�Բ�ĺ�����
void get2point(void)
{
	int i = 0;
	mouse_msg msg;
	for (; is_run(); delay_fps(120))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
			msg = getmouse();
		//�����ǻ�ȡ��갴��ȥʱ������λ��
		if (i == 0 && msg.is_left() && msg.is_down())
		{
			shape[count].x1 = msg.x;
			shape[count].y1 = msg.y;
			i++;
		}
		//�����ǻ�ȡ����ɿ�ʱ������λ��
		else if (i == 1 && msg.is_left() && msg.is_up())
		{
			shape[count].x2 = msg.x;
			shape[count].y2 = msg.y;
			i++;
		}
		//��ȡ��������Ϳ��Գ�����
		if (i == 2)
			break;
	}
}

//���ǽ���ɫ���ó�ʼ���ĺ������Է�֮�������������ɫ������ڵ�
void restore(void)
{
	setcolor(BLACK);
	setfillcolor(WHITE);
	//����������Ϊ�˸��ǵ�ѯ����ɫ���Ǿ仰
	xyprintf(0, 90, "                                                                 ");
}