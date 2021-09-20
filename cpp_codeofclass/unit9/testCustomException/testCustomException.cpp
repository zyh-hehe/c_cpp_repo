#include"Vec3D.h"
int main(void)
{
	Vec3D v;
	try
	{
		cout << v[4] << endl;
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
		if (typeid(e) == typeid(RangeException))
		{
			RangeException r=dynamic_cast<RangeException&>(e);
			cout << r.what() << endl;
			cout << "dimension: " << r.getDimension() << endl;
			cout << "index: " << r.getIndex() << endl;
		}
	}
	return 0;
}
