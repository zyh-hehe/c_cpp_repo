#pragma once
#include<string>
#include<iostream>
#include<cmath>//�������ѧ����Ŀ�
#include<istream>
#include<ostream>
using namespace std;
class Vec2D
{
private:
	double x_;
	double y_;
public:
	Vec2D();
	Vec2D(double x, double y);
	
	// ������ת��Ϊ�ַ�����ʾ
	std::string toString();
	
	// �����ӷ�
	Vec2D add(Vec2D secondVec2D);
	Vec2D add(double number);
	Vec2D operator+(const Vec2D& secondVec2D);//���ﴫ���ò�����Ϊ�˼��ٴ��εĿ���
	Vec2D operator+(const double number);//double���Ͳ������������ÿ�����࣬const��Ϊ�˱�֤����������Ĳ��������ı�
	Vec2D& operator +=(double x);//+=��ʵ�ֽ���Ǳ������ˣ��ı���ԭ�������Դ�����������������
	Vec2D& operator += (const Vec2D& secondVec2D);
	
	// ��������
	Vec2D subtract(Vec2D secondVec2D);//��ȻҲ���Բ������ã�ֻ�ǿ�����һ��
	Vec2D subtract(double numble);//��ȻҲ���Բ�const��ֻ�ǿ��ܻ�ı�number��ֵ������Ϊ�˱�֤��ȫ���ຯ����û���const
	Vec2D operator-(const Vec2D& secondVec2D);
	Vec2D operator-(const double number);
	Vec2D& operator -=(double x);//ͬ+=
	Vec2D& operator -= (const Vec2D& secondVec2D);
	
	// �������
	double dot(Vec2D secondVec2D);//��˽����һ����������������������ѧ�������
	double operator*(const Vec2D& secondVec2D);
	
	// ��������
	Vec2D multiply(double x);
	Vec2D& operator *= (double x);//ͬ+=
	friend Vec2D operator*(double x, Vec2D vec2d);
	//�������һ�����friend����������һ��������ǰ�����һ���������ں���ˣ��������һ���ģ�
	//����һ��������һ������������2.0*v2������˺���û�а취���������صģ�����Ҫ��������Ԫ������
	//�������������������࣬�����ſ���������ʱ����������������һ����һ�������ڶ�����һ����������
	
	// ����ȡ��
	Vec2D negative();
	Vec2D operator - (void);//����д�ĺ�֮ǰ+=��Щ�е㲻һ����������ȡ������ֻ�ǵ�����ȡ����û�аѸö�����为�����Է���һ����ʱVec2D����
	
	// ��������
	Vec2D& increase();
	Vec2D& operator ++();
	Vec2D    operator ++(int dummy);
	//���++�������Ǻ���++����������β�dummyֻ����Ϊһ����ʶ��/ռλ����
	//��ʵ��û�вμӺ����߼����壬�����ڵ���ʱҲ����Ҫ��Ĵ���ȥ
	//��Ϊʲô����++�����û�д���һ�������أ�
	//������Ϊ����++���������ִ��������������߼�����ԭʼ��(int)++��һ����
	//���Է��ص�ʵ������û��������ԭ����ִ�����������
	
	// �����Լ�
	Vec2D& decrease();
	Vec2D& operator --();
	Vec2D    operator --(int dummy);//ͬ��
	
	// ��ȡ���޸�ĳ��Ԫ�ص�ֵ
	double& at(int x);//x�������0���ͷ���x_��ֵ��1�ͷ���y_��ֵ
	double& operator [](int x);//����֮���Դ���������������Ϊ�˰������������ֵ��һ�������޸ĵĴ���ֵ��Ϊ��ֵ���ã����Խ����޸�
	
	// ��������ģ��
	double magnitude();
	operator double();//����ת�����������double���ķ���ֵ��Ϊ�����������Բ���Ҫд����ֵ����

	// ������������
	double direction();
	
	// �Ƚ���������
	int compareTo(Vec2D secondVec2D);//��ȷ���0��С�˷���-1�����˷���1

	//��������ȡ/��������
	friend ostream& operator<<(ostream& os, const Vec2D& vec2d);//����ȡ�������ֻ�����ͣ�����������const
	friend istream& operator>>(istream& is, Vec2D& vec2d);//�����������������Ҫ�ı�����ֵ�ģ����Եô�����������
	//����֮������������Ԫ����������Ϊ������������ں��������õ�ʱ���Ҫд��vec2d<<cout�����ӣ�
	//����֣�������������Ԫ����,�Ա����������������һ����i/o�����ڶ�����Vec2D
};

