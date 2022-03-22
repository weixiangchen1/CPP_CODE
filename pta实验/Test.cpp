//#include <iostream>
//using namespace std;
//class Point {
//public:
//    Point(){}
//    Point(int x1, int y1) { 
//        x = x1; 
//        y = y1;
//        cout << "Constructor is called." << endl;
//    }
//    Point(Point& p);
//    ~Point() { cout << "Destructor is called." << endl; }
//    int getx() { return x; }
//    int gety() { return y; }
//private:
//    int x, y;
//};
//Point::Point(Point& p) {
//    x = p.x; y = p.y;
//    cout << "Copy constructor is called." << endl;
//}
//int main() {
//    Point p1(3, 4);
//    Point p2(p1);
//    Point p3 = p2;
//    Point p4;
//    Point p5(2);
//    cout << "p3=(" << p3.getx() << "," << p3.gety() << ")" << endl;
//    return 0;
//}
//
//（1）记录程序的运行结果
//（2）将Point类中带有两个参数的构造函数进行修改，在函数体内增加如下语句：
//cout << ”Constructor is called.” << endl;
//重新记录程序的运行结果，并解释输出结果。
//（3）按下列要求进行测试。
//在主函数体内，添加如下语句：

//测试程序会出现什么错误？为什么？如何对已有的构造函数进行适当的修改？
//（4）结合第（2）和第（3）步的修改后，其运行结果是？
//分析创建不同的对象时如何调用适当的构造函数？
//
//#include<iostream>
//using namespace std;
//
//class Point
//{
//public:
//	Point()
//	{
//		_x = 0;
//		_y = 0;
//		_count++;
//	}
//	Point(int x)
//	{
//		_x = x;
//		_y = 0;
//		_count++;
//	}
//	Point(int x, int y)
//		:_x(x),
//		_y(y)
//	{
//		_count++;
//	}
//	Point(Point& p)
//	{
//		_x = p._x;
//		_y = p._y;
//		_count++;
//	}
//	static void showCount()
//	{
//		cout << _count << endl;
//	}
//	int getX()
//	{
//		return _x;
//	}
//	int getY()
//	{
//		return _y;
//	}
//private:
//	int _x;
//	int _y;
//	static int _count;
//};
//
//int Point::_count = 0;
//
///*你的程序将被嵌入在这里*/
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//
//	Point::showCount();
//	Point a(x, y);
//	cout << "Point A: " << a.getX() << "," << a.getY() << endl;
//	Point::showCount();
//
//	Point b(a);
//	cout << "Point B: " << b.getX() << "," << b.getY() << endl;
//	Point::showCount();
//
//	Point c;
//	cout << "Point C: " << c.getX() << "," << c.getY() << endl;
//	Point::showCount();
//
//	Point d(x);
//	cout << "Point D: " << d.getX() << "," << d.getY() << endl;
//	Point::showCount();
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class Circle
//{
//public:
//	friend class Cone;
//	Circle(double radius)
//		:_radius(radius)
//	{}
//
//	Circle()
//		:_radius(0.0)
//	{}
//
//	double getArea()
//	{
//		return 3.14 * _radius * _radius;
//	}
//
//	double getPerimeter()
//	{
//		return 6.28 * _radius;
//	}
//
//private:
//	double _radius;
//};
//
//class Cone
//{
//public:
//	Cone(double height, double radius)
//		:_height(height),
//		_circle(radius)
//	{}
//
//	Cone()
//		:_height(0.0),
//		_circle(0.0)
//	{}
//
//	double getVolume()
//	{
//		return  _circle.getArea() * _height / 3;
//	}
//
//private:
//	double _height;
//	Circle _circle;
//};
//
//int main()
//{
//	double r, h;
//	cin >> r >> h;
//
//	Cone cone(r, h);
//
//	cout << "The volume is " << cone.getVolume() << endl;
//
//	return 0;
//}
//
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//
//class Line;
//class Point
//{
//public:
//	friend double dist(Point& p, Line& l);
//	Point(int x, int y)
//	{
//		_x = x;
//		_y = y;
//	}
//private:
//	int _x;
//	int _y;
//};
//
//class Line
//{
//public:
//	friend double dist(Point& p, Line& l);
//	Line(int a, int b, int c)
//	{
//		_a = a;
//		_b = b;
//		_c = c;
//	}
//
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//double dist(Point& p, Line& l)
//{
//	double retX = abs(l._a * p._x + l._b * p._y + l._c);
//	double retY = sqrt(l._a * l._a + l._b * l._b);
//
//	return retX / retY;
//}
//
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	int a, b, c;
//	cin >> a >> b >> c;
//
//	Point p1(x, y);
//	Line l1(a, b, c);
//	if (dist(p1, l1) == 0)
//		cout << "The distance is: 0" << endl;
//	else
//		cout << "The distance is: " << setiosflags(ios::fixed) << setprecision(2) << dist(p1, l1) << endl;
//
//	return 0;
//}
//


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point;
class Line
{
public:
	friend class Point;
	double dist(Point& p, Line& l);
	Line(double a, double b, double c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

private:
	double _a;
	double _b;
	double _c;
};

class Point
{
public:
	friend class Line;
	friend double Line::dist(Point& p, Line& l);
	Point(double x, double y)
	{
		_x = x;
		_y = y;
	}
private:
	int _x;
	int _y;
};

double Line::dist(Point& p, Line& l)
{
	double retX = abs(l._a * p._x + l._b * p._y + l._c);
	double retY = sqrt(l._a * l._a + l._b * l._b);

	return retX / retY;
}

int main()
{
	double x, y;
	cin >> x >> y;
	double a, b, c;
	cin >> a >> b >> c;

	Point p1(x, y);
	Line l1(a, b, c);

	if (l1.dist(p1, l1) == 0)
		cout << "The distance is 0" << endl;
	else
		cout << "The distance is " << setiosflags(ios::fixed) << setprecision(2) << l1.dist(p1, l1);

	return 0;
}



