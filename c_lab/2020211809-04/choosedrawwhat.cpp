#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include"struct.SHAPE.h"

void drawbar(void);
void drawcircle(void);
void drawline(void);
void drawtriangle(void);
void clearandredraw(void);
void choose_whetherfill(void);
void draw_poly(void);//�����draw_poly����drawpoly,���������Ƿ�ֹ��EGE�Դ��Ļ�����εĺ�������
void savefile(SHAPE*);

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;

//���������������ĺ������������Ϊ���ǻ��������������
void draw(void)
{
	while (is_run())
	{
		flushkey();//��ռ��̻��棬��ֹ�������ڰ���ζ�����bug
		//��ӡһ����ʾ�������û��Ѿ����˶��ٸ�ͼ��
		xyprintf(900, 0, "���Ѿ�����%d��ͼ����", count - 1);
		xyprintf(900, 30, "���Ѿ�����%d���������", polycount - 1);

		char choice_drawwhat;//���Ȼ�ȡ���룬����û�����
		choice_drawwhat = getch();
		switch (choice_drawwhat)
		{
		case'q':
			if (count != 1)
			{
	          xyprintf(0, 90, "��Ҫ�����㻭�Ļ��𣿰���1�Ǳ��棬����2�ǲ�����");
			  char whethersave;
			  whethersave = getch();
			  if (whethersave == '1')
				savefile(shape);
			}
			closegraph();
		case '1':
			shape[count].type = 1;//���ѡ���˳����Σ��Ͱ����͵�ֵ��Ϊ1
			choose_whetherfill();//ѡ���Ƿ����
			drawbar();
			count++;//ͼ������һ
			break;
		case'2':
			shape[count].type = 2;//���ѡ����Բ���Ͱ����͵�ֵ��Ϊ2
			choose_whetherfill();//ѡ���Ƿ����
			drawcircle();
			count++;//ͼ������һ
			break;
		case '3':
			shape[count].type = 3;//���ѡ���������Σ��Ͱ����͵�ֵ��Ϊ3
			choose_whetherfill();//ѡ���Ƿ����
			drawtriangle();
			count++;//ͼ������һ
			break;
		case'4':
			shape[count].type = 4;//���ѡ�����ߣ��Ͱ����͵�ֵ��Ϊ4
			drawline();
			count++;//ͼ������һ
			break;
		case'5':
			shape[count].type = 5;//���ѡ���˶���Σ��Ͱ����͵�ֵ��Ϊ5
			choose_whetherfill();//ѡ���Ƿ����
			draw_poly();
			count++;//ͼ������һ
			polycount++;//���������һ
			break;
		case'6':
			//������ֱ�����������Ļ�����´�ӡ������Ҳ���鷳���԰�
			cleardevice();
			xyprintf(0, 0, "��ӭ�������������ݻ���3.0����ͼʱ�������벻Ҫ̫�죡��!");
			xyprintf(0, 30, "����������Ҫ����ɶ�أ�");
			xyprintf(0, 60, "����:1.������ 2.Բ  3.������ 4.��  5.�����  6.�����Ļ c.����һ�� q.�˳���");
			line(0, 125, 12800, 130);
			//����ȫ������
			count = 1;
			polycount = 1;
			break;
		case 'c':
			//���ǳ���һ���Ĳ���
			//����Ƕ���Σ�����εĸ�����һ
			if (shape[count-1].type == 5)
			{
				if (polycount > 1)//��ֹ���ַǸ���
					polycount--;
			}
			//ͼ������һ
			if (count > 1)//��ֹ���ַǸ���
				count--;
			clearandredraw();//ִ���ػ�����
			xyprintf(0, 0, "��ӭ�������������ݻ���3.0����ͼʱ�������벻Ҫ̫�죡��!");
			xyprintf(0, 30, "����������Ҫ����ɶ�أ�");
			xyprintf(0, 60, "����:1.������ 2.Բ  3.������ 4.��  5.�����  6.�����Ļ c.����һ�� q.�˳���");
			line(0, 125, 12800, 130);
			break;
		}
	}
}
