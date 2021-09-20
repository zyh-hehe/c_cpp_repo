#include"Vec2D.h"

int main(void)
{
	Vec2D v1{ 2,4 }, v2{ 3,5 };
	cout << "v1=" << v1.toString() << endl;
	cout << "v2=" << v2.toString() << endl;
	Vec2D v3 = v1+v2;
	Vec2D v4 = v3 + 10.0;
	cout << "v1+v2=" << v3.toString() << endl;
	cout << "v3+10=" << v4.toString() << endl;
	Vec2D v5 = v2.subtract(v1);
	double v6 = v2.dot(v1);
	Vec2D v7 = v3.multiply(2.1);
	Vec2D v8 = v2.negative();
	cout << "v2-v1=" << v5.toString() << endl;
	cout << "жиди v2-v1=" << (v2 - v1).toString() << endl;
	cout << "v2 . v1=" << v6 << endl;
	cout << "v3*2.1=" << v7.toString() << endl;
	cout << "2.1*v3=" << (2.1 * v3).toString() << endl;
	cout << "-v2=" <<(-v2). toString() << endl;
	cout << "++v8=" << (++v8).toString() << endl;
	cout << "v8++=" << (v8++).toString() << endl;
	cout << "v8" << v8.toString() << endl;
	cout << "--v2=" << v2.decrease().toString()<<endl;
	cout << "v1._x=" << v1[0]<< endl;
	cout << "v1._y=" << v1[1] << endl;
	cout << "v1.magnitude=" << v1.magnitude() << endl;
	cout << "double(v1) = " << static_cast<double>(v1) << endl;
	cout << "v1.direction=" << v1.direction() << endl;
	cout << "v1 compare v2:" << v1.compareTo(v2) << endl;
	cout << "v1=" << v1.toString() << endl;
	v1 += 3;
	cout << "v1+=3 =" << v1.toString() << endl;
	cout << "v2=" << v2.toString() << endl;
	cout << "v2 -=3 = " << (v2-=3).toString() << endl;
	cout << "v3=" << v3.toString() << endl;
	cout << "v3 *=3 = " << (v3*=3).toString() << endl;
	cout << "v3+=v3 = " << (v3 += v3).toString() << endl;
	cout <<"v4.x_="<< v4[0] << endl;
	v4[0] = 100;
	cout << "change v4.x_ to 100:" << v4[0] << endl;
	cout << "please input a vec2d:" << endl;
	Vec2D v9{};
	cin >> v9;
	cout << v9 << endl;
}