#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;

SHAPE* readfile(void);
void clearandredraw(void);

//����ѯ���Ƿ��ȡ���л���ĺ���
int choice_whetherreadFile(char choice_readFile)
{
	while (is_run())
	{
		if (choice_readFile == 'q')
			closegraph();
		else if (choice_readFile == '1')
		{
			setviewport(0, 30, 1000, 1000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			//������һ��ִ�е�Ŀ�������������Ļ
			if (readfile() == NULL)//���û��ȡ��ԭ�ļ�������ʾ��ȡʧ��
			{
				xyprintf(0, 0, "��ӭ�������������ݻ���3.0��");
				xyprintf(0, 30, "ԭ�л��岻����,��ȡʧ�ܣ�");
				line(0, 125, 12800, 130);
				return 0;
			}
			else//�����ȡ�ɹ�������ʾ�Ѿ���ȡ
			{
				clearandredraw();
				xyprintf(0, 0, "��ӭ�������������ݻ���3.0��");
				xyprintf(0, 30, "�Ѿ���ȡ�����еĻ����ļ�Ŷ");
				line(0, 125, 12800, 130);
				return 1;//����1�����ȡ�ɹ�
			}
		}

		else if (choice_readFile == '2')
		{
			setviewport(0, 30, 1000, 1000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			//������һ��ִ�е�Ŀ�������������Ļ
			xyprintf(0, 0, "��ӭ�������������ݻ���3.0��");
			xyprintf(0, 30, "û�ж�ȡ���еĻ����ļ�Ŷ");
			line(0, 125, 12800, 130);
			return 0;
		}
		else
			choice_readFile = getch();
	}
	return 0;
}

//�������û���ȡ�ļ���ѯ���Ƿ�Ҫ�ػ��ĺ���
void redraw(int return_choice_whetherbegindraw)
{
	char choice_whetherredraw;
	if (return_choice_whetherbegindraw)
	{
		xyprintf(0, 60, "����Ҫ�ػ���");
		xyprintf(0, 90, "����1���ػ�������2�ǲ��ػ�");
		line(0, 125, 12800, 130);
		while (is_run())
		{
			choice_whetherredraw = getch();
			if (choice_whetherredraw == '1')
			{
				setviewport(0, 30, 10000, 10000);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0, 0, 10000, 10000);
				count = 1;//�ػ��˾Ͱ�ͼ�θ�������
				polycount = 1;
				//������һ��ִ�е�Ŀ�������������Ļ
				xyprintf(0, 0, "��ӭ�������������ݻ���3.0��");
				xyprintf(0, 30, "��ӭ�������������ݣ�");
				line(0, 125, 12800, 130);
				break;
			}
			else if (choice_whetherredraw == '2')
				break;
		}
	}
}

//����ѯ���Ƿ�ʼ�����ĺ���
void choice_whetherbegindraw(char choice_begindraw)
{
	while (is_run())
	{
		switch (choice_begindraw)
		{
		case '1':
			setviewport(0, 0, 10000, 10000);
			break;
		case '2':
			setviewport(0, 30, 10000, 10000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			xyprintf(0, 0, "��ӭ�������������ݻ���3.0��");
			xyprintf(0, 30, "�Ѿ��������ĻŶ");
			//ûɶ��˵�ģ��������
			xyprintf(0, 60, "����1�ǿ�ʼ����������2�������Ļ������ûʲô�ã�������q���˳�");
			line(0, 125, 12800, 130);
			count = 1;
			polycount = 1;//�����˾Ͱ�ͼ�θ�������
			choice_begindraw = getch();
			break;
		case'q':
			closegraph();
			break;
		default:
			choice_begindraw = getch();
		}
		if (choice_begindraw == '1')
			break;
	}
}