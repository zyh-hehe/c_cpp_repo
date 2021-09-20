#include"Vec3D.h"

int main(void)
{
	Vec3D v(1.5, 2.5, 3.5);
	try {
		cout << (v / 1.0)[3] << endl;
		//ע�������䡣�����϶��ԣ������������catchӦ�����ж�ִ�е�һ������ִ�еڶ���
		//��ʵ���ϣ����д��(v/0.0)[3]���������쳣���У�����ֱ��ִ��ZeroException���catch
		//ԭ���ǣ�(v/0.0)[3]����ִ�е��ǳ������㣬���������0.0��ֱ���׳��쳣�ˣ������ֲ����׳�Խ���쳣
	}
	catch (RangeException& e)
	{
		cout << e.what() << endl;
		//��ע�������䡣���what���õ��������ض����what��������RangeException::what()������out_of_range::what()
		//ԭ��Ҫ�Ӷ�̬����ȥ��⣬�漰����̬���ࡣ�ǵø�ϰ��̬�͸�д������Ҫ��
		//����ִ�������麯��ʱ�����������/ָ�����ʵ����(��������������)ȥ���ò�ͬ���ض��庯��
		//���ԣ�����ֻ����ʽ�İ�eת��Ϊout_of_range��(��������/ָ��)���Ż����out_of_range::what()
		cout << "dimension: " << e.getDimension() << endl;
		cout << "index: " << e.getIndex() << endl;
	}
	catch (ZeroException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

//