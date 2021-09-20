#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//����ṹ�������������mainfunction.cpp��������ⲿ��������
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;
FILE* file;//�ļ�ָ��

//������������˳�ʱѯ���Ƿ񱣴����л���
void savefile(SHAPE* shape)
{
	int j;//����ѭ������ʱ����
	file = fopen("SHAPE.txt", "w+");//���ļ��ķ�ʽ�ǿɶ���д
	fprintf(file, "%d\n", count);//�����ļ����ӡ�м���ͼ�Σ�û��ͼ��countΪ1
	//������������Ϊ�������ɵ��ļ����б�
	fprintf(file, "ͼ������\t��ɫ\t�Ƿ����\tx1\ty1\tx2\ty2\tx3\ty3\tԲ��x\tԲ��y\t�뾶\t����\tpx1\tpy1\tpx2\tpy2\tpx3\tpy3\tpx4\tpy4\tpx5\tpy5\tpx6\tpy6\tpx7\tpy7\tpx8\t");
	fprintf(file, "py8\tpx9\tpy9\tpx10\tpx11\tpy11\tpx12\tpy12\tpx13\tpy13\tpx14\tpy14\tpx15\tpy15\tpx16\tpy16\tpx17\tpy17\tpx18\tpy18\tpx19\tpy19\tpx20\tpy20\n");
	shape++;//��Ϊ��һ��ͼ�ε��±���1��������ָ���һָ��ṹ������ĵڶ���
	
	for (j = 1; j < count; j++, shape++)//ÿ��ȡһ�Σ�ѭ��������һ��ָ�������һ����ַ
	{
		//�����ǰ�˳��д��ȥ
		fprintf(file, "%d\t", shape->type);
		fprintf(file, "%d\t", shape->color);
		fprintf(file, "%d\t", shape->fill);
		fprintf(file, "%d\t", shape->x1);
		fprintf(file, "%d\t", shape->y1);
		fprintf(file, "%d\t", shape->x2);
		fprintf(file, "%d\t", shape->y2);
		fprintf(file, "%d\t", shape->x3);
		fprintf(file, "%d\t", shape->y3);
		fprintf(file, "%d\t", shape->centerx);
		fprintf(file, "%d\t", shape->centery);
		fprintf(file, "%d\t", shape->radius);
		fprintf(file, "%d\t", shape->side);
		//side��Ϊ0����Ϊ����Σ������д��
		if (shape->side != 0)
		{
			int k;
			for (k = 0; k < shape->side; k++)
			{
				fprintf(file, "%d\t", shape->point[k][0]);
				fprintf(file, "%d\t", shape->point[k][1]);
			}
			fprintf(file, "\n");
		}
		else
			fprintf(file, "\n");
	}
	fprintf(file, "��ע����ɫ���Ƿ���䣬ͼ��������������ʽ�����ļ������庬��������struct.SHAPE.h��������Ϊ������ݴ����䲻����");
	fclose(file);
}

//��������������ڶ�ȡ�ļ�
SHAPE* readfile(void)
{
	int r = 0;
	int j, k;//������������ѭ������ʱ������������
	char rubbish[10];//��Ϊ�ļ���ǰһ���з����ݲ��֣�������һ���ַ��������
	j = 1;
	if (fopen("SHAPE.txt", "r") == NULL)//���ԭ�ļ������ڣ��ͷ���һ����ָ��
		return NULL;
	file = fopen("SHAPE.txt", "r");
	fscanf(file, "%d", &count);
	for (; r < 52; r++)
		fscanf(file, "%s", rubbish);//��ȡ��ǰ������ķ�������Ϣ
	for (; j < count; j++)
	{
		//����˳���ȡ�ļ�����
		fscanf(file, "%d", &shape[j].type);
		if (shape[j].type == 5)
			polycount++;//����Ƕ���Σ�polycount��һ
		fscanf(file, "%d", &shape[j].color);
		fscanf(file, "%d", &shape[j].fill);
		fscanf(file, "%d", &shape[j].x1);
		fscanf(file, "%d", &shape[j].y1);
		fscanf(file, "%d", &shape[j].x2);
		fscanf(file, "%d", &shape[j].y2);
		fscanf(file, "%d", &shape[j].x3);
		fscanf(file, "%d", &shape[j].y3);
		fscanf(file, "%d", &shape[j].centerx);
		fscanf(file, "%d", &shape[j].centery);
		fscanf(file, "%d", &shape[j].radius);
		fscanf(file, "%d", &shape[j].side);
		//����Ƕ���Σ��Ͱ�˳�����
		if (shape[j].side != 0)
		{
			for (k = 0; k < shape[j].side; k++)
			{
				fscanf(file, "%d", &shape[j].point[k][0]);
				fscanf(file, "%d", &shape[j].point[k][1]);
			}
		}
	}
	fclose(file);
	return shape;//��ȡ��ɺ󣬷���ָ�������һ��Ԫ�ص�ָ��
}