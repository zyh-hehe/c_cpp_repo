#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;
FILE* file;//文件指针

//这个函数用于退出时询问是否保存已有画板
void savefile(SHAPE* shape)
{
	int j;//用于循环的临时变量
	file = fopen("SHAPE.txt", "w+");//打开文件的方式是可读可写
	fprintf(file, "%d\n", count);//先在文件里打印有几个图形，没有图形count为1
	//下面这两行是为了在生成的文件里列表
	fprintf(file, "图形类型\t颜色\t是否填充\tx1\ty1\tx2\ty2\tx3\ty3\t圆心x\t圆心y\t半径\t边数\tpx1\tpy1\tpx2\tpy2\tpx3\tpy3\tpx4\tpy4\tpx5\tpy5\tpx6\tpy6\tpx7\tpy7\tpx8\t");
	fprintf(file, "py8\tpx9\tpy9\tpx10\tpx11\tpy11\tpx12\tpy12\tpx13\tpy13\tpx14\tpy14\tpx15\tpy15\tpx16\tpy16\tpx17\tpy17\tpx18\tpy18\tpx19\tpy19\tpx20\tpy20\n");
	shape++;//因为第一个图形的下标是1，所以让指针加一指向结构体数组的第二个
	
	for (j = 1; j < count; j++, shape++)//每读取一次，循环变量加一，指针向后移一个地址
	{
		//下面是按顺序写进去
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
		//side不为0，即为多边形，就逐个写点
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
	fprintf(file, "备注：颜色，是否填充，图形类型以数字形式存入文件，具体含义见代码的struct.SHAPE.h；点坐标为零的数据代表其不存在");
	fclose(file);
}

//下面这个函数用于读取文件
SHAPE* readfile(void)
{
	int r = 0;
	int j, k;//这三个是用于循环的临时变量，无意义
	char rubbish[10];//因为文件的前一段有非数据部分，就先用一个字符数组存着
	j = 1;
	if (fopen("SHAPE.txt", "r") == NULL)//如果原文件不存在，就返回一个空指针
		return NULL;
	file = fopen("SHAPE.txt", "r");
	fscanf(file, "%d", &count);
	for (; r < 52; r++)
		fscanf(file, "%s", rubbish);//读取掉前面的中文非数据信息
	for (; j < count; j++)
	{
		//按照顺序读取文件内容
		fscanf(file, "%d", &shape[j].type);
		if (shape[j].type == 5)
			polycount++;//如果是多边形，polycount加一
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
		//如果是多边形，就按顺序读点
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
	return shape;//读取完成后，返回指向数组第一个元素的指针
}