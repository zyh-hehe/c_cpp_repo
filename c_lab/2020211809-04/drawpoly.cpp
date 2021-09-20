#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include"struct.SHAPE.h"

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern  SHAPE shape[10000];
extern unsigned int count;

void choosecolor(void);
void choose_whetherfill(void);
void restore(void);

void draw_poly(void)
{
	choosecolor();
	int polypt[42];//�����һ����ʱ���飬������ʱ����������
	char side[10];//����һ����ʱ�ַ����飬������ʱ����ӶԻ����ȡ������
	//����һ���Ի���
	inputbox_getline("�����˹��������ѧϰ�����ھ�Ķ�������ݼ���Ի���",
		"������������Ҫ���Ķ���εı���(���20����)��",
		side,
		sizeof(side) / sizeof(*side));

	while (is_run())
	{
		//�������if�ж���Ϊ��ȷ������ֵ�Ϸ���������Ƿ���3��20�ں��Ƿ�Ϊ����
		if (atoi(side) >= 3 && atoi(side) <= 20 && (atoi(side)) - atof(side) == 0)
		{
			shape[count].side = atoi(side);//������ֵת��Ϊ����ֵ�����Ӧ�Ľṹ������
			break;
		}

		else//������Ϸ�������ʾ����ֵ�Ƿ���Ҫ����������
		{
			inputbox_getline("�����˹��������ѧϰ�����ھ�Ķ�������ݼ���Ի���",
				"������������Ҫ���Ķ���εı���(���20����)\n������ֵ�Ƿ���������һ������3��20֮�������ֵ������",
				side,
				sizeof(side) / sizeof(*side));
		}
	}
	xyprintf(300, 300, "%d", shape[count].side);//��ʱ�����������Ҳ���ʱ�����ݣ�ûɶ��

	while (is_run())
	{
		int k;//��ʱ������ֻ�����������ѭ����Ŀ���ǵ���ȡ��Ŀ�����������ͽ�����ȡ
		for (k = 0; k < shape[count].side; k++)
		{
			char temppoint[15];//����һ����ʱ���飬������ʱ��������
			//����һ���Ի���
			inputbox_getline("�����˹��������ѧϰ�����ھ�Ķ�������ݼ���Ի���",
				"���������Ŀ�����εĵ����꣬��ʽ����\n\np.s����С��ֵΪ1�������ֵ����ʾ����С�й�\n\n\t\t   x,y",
				temppoint,
				sizeof(temppoint) / sizeof(*temppoint));

			char* p;//����һ����ַ����������ķָ��
			while (is_run())
			{
				p = strtok(temppoint, ",");//�ָ����Ƕ���
				if (p && atoi(p) > 0 && (atoi(p)) - atof(p) == 0)//�жϷָ����һ���ַ����Ƿ�Ϸ�
				{
					shape[count].point[k][0] = atoi(p);//����Ϸ�����ֱ��д����Ӧ�Ľṹ������
					p = strtok(NULL, ",");
					if (p && atoi(p) > 0 && (atoi(p)) - atof(p) == 0)
					{
						shape[count].point[k][1] = atoi(p);//����Ϸ�����ֱ��д����Ӧ�Ľṹ������
						xyprintf((300), (330 + 30 * k), "%d,%d", shape[count].point[k][0], shape[count].point[k][1]);//��ʱд�ĺ����������Ҳ���ʱ�����ݣ�ûɶ��
						break;//��ȡ����ֵ�Ϸ�������ȥ
					}
				}
				//�������ֵ���ִ��󣬾ͱ���Ҫ������
				inputbox_getline("�����˹��������ѧϰ�����ھ�Ķ�������ݼ���Ի���",
					"������Ƿ������������룡��������\n���������Ŀ�����εĵ����꣬��ʽ����\np.s����С��ֵΪ1�������ֵ����ʾ����С�й�\n\n\t\t   x,y",
					temppoint,
					sizeof(temppoint) / sizeof(*temppoint));
			}
		}
		break;
	}
	int l;
	int m;//����������������ʱ�������������潫ֵд����ʱ����������
	for (l = 0, m = 0; m < shape[count].side; l = l + 2, m = m + 1)
	{
		polypt[l] = shape[count].point[m][0];
		polypt[l + 1] = shape[count].point[m][1];
	}
	//��������һ����������ĵ�һ����
	polypt[(2 * shape[count].side)] = shape[count].point[0][0];
	polypt[(2 * shape[count].side) + 1] = shape[count].point[0][1];
	//�������ǻ�ͼ�׶�
	setviewport(0, 125, 10000, 10000);//�����ӿ�
	if (shape[count].fill)//�����ȡ����������Ҫ��䣬�ͻ�һ���������
		fillpoly(shape[count].side + 1, polypt);
	else
		drawpoly(shape[count].side + 1, polypt);//���򣬾ͻ�һ�������Ķ����
	setviewport(0, 0, 10000, 10000);//���ӿ����û���
	restore();//���������Ϊ�˰�������ɫ�������ɫ���ûس�ʼֵ
}