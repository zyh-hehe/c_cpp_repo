#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"
//�������֣����ｫÿһ�������õ��ı���ֱ�Ӹ����˸ú������棬��Ϊ�˷����Ķ�
void initialsettings(void);
int choice_whetherreadFile(char);
char choice_readFile;
void choice_whetherbegindraw(char);
char choice_begindraw;
void draw(void);
void redraw(int);

unsigned int count = 1;//�Ǹ����ͱ���count���ڼ����Ѿ����˶��ٸ��Ƕ����ͼ��
SHAPE shape[10000];//������һ�����Է�10000��ͼ�����ݵ�SHAPE���ͽṹ������
unsigned int polycount = 1;//�Ǹ����ͱ���polycount���ڼ����Ѿ����˶��ٸ������

//����������
int main(void)
{
	//��ʼ�����������С��ɫ�ͻ��屳��ɫ,���������initialsettingsfunction.cpp��
	initialsettings();

	//����Ϊ��һ����Ļ��������ݣ������û�ѡ���Ƿ��ȡ���л���
	xyprintf(0, 0, "��ӭ�������������ݻ���3.0�����Ȱ�shift�ر����뷨��");
	xyprintf(0, 30, "���Ƿ�Ҫ��ȡ���еĻ����ļ���");
	xyprintf(0, 60, "����1�Ƕ�ȡ���л����ļ�������2�ǲ���ȡ���л����ļ�������q���˳�");
	line(0, 125, 12800, 130);

	choice_readFile = getch();
	redraw(choice_whetherreadFile(choice_readFile));
	/*��choice_readFile���ֵ����choice_whetherreadFile������
	�ٽ���ķ���ֵ����redraw��������������������menu.cpp��*/

	//����Ϊ�ڶ�����Ļ��������ݣ������û�ѡ���Ƿ�ʼ����
	xyprintf(0, 60, "����������Ҫ��ʼ������");
	xyprintf(0, 90, "����1�ǿ�ʼ����������2�������Ļ������ûʲô�ã�������q���˳�");
	line(0, 125, 12800, 130);

	choice_begindraw = getch();
	choice_whetherbegindraw(choice_begindraw);
	//��choice_begindraw��ֵ����choice_whetherbegindraw�������������Ҳ��menu.cpp��

	//����Ϊ��������Ļ��������ݣ������û�ѡ��ʲô����һ�λ�һֱ��ʾ
	xyprintf(0, 0, "��ӭ�������������ݻ���3.0����ͼʱ�������벻Ҫ̫�죡��!");
	xyprintf(0, 30, "                                              ");
	xyprintf(0, 30, "����������Ҫ����ɶ�أ�");
	xyprintf(0, 60, "����:1.������ 2.Բ  3.������ 4.��  5.�����  6.�����Ļ c.����һ�� q.�˳���");
	xyprintf(0, 90, "                                                                 ");
	line(0, 125, 12800, 130);
	//���������Կ�ʼ�����ˣ����������choosedrawwhat.cpp��
	//����ʵ�ֵ�ֻ��һ��ǰ����ʾ�Ĺ��ܣ���Ҫ������ͼ�ĺ�������draw()������
	draw();
}