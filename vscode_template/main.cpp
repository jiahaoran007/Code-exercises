#include <iostream>
using namespace std;

class Point{
public:
    Point(){};
    Point (int x, int y): x(x),y(y) {};
	Point(const Point &a) //复制构造函数
	{
		this->x = a.x;
		this->y = a.y;
	}
	Point operator+(Point &a)
	{
		Point rhs;
		rhs.x = this->x + a.x;
		rhs.y = this->y + a.y;
		return rhs;
	}

	Point operator-(Point &a);
	Point &operator++()
	{
		this->x++;
		this->y++;
		return *this;

	}
	const Point operator++(int)
	{
		Point rhs;
		//rhs.x = this->x++;
		//rhs.y = this->y++;

		//rhs.x++;
		//rhs.y++;

		this->x++;
		this->y++;
		return rhs;

	}

	bool operator<(const Point &a) const
	{
		return this->x < a.x;
	}

    friend Point operator+(const Point &a, const Point &b);   //声明类的友元函数
    int x,y;
	static int count ;
	friend ostream &operator<<(ostream &out, Point &a);  
};

Point operator+(const Point &a,const Point &b){//类外重载,运算符重载函数作为类的友元函数
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
	Point::count++;
	cout << "第"<< Point::count << "次调用" << endl;
    return ret;
}

Point Point:: operator-(Point &a)
{
		Point rhs(x,y);
		rhs.x = this->x - a.x;
		rhs.y = this->y - a.y;
		return rhs;
}

ostream &operator<<(ostream &cout, Point &a)
{
	cout << "Point(" << a.x << "," << a.y << ")";
	//cout << "Point的x坐标为" << a.x;
	//cout << "Point的y坐标为" << a.x << endl;
	return cout;
}

int Point::count = 0;
//static int count = 0;

int main() {
    Point a(2,4),b(5,3),d(20,8);
    Point c = a + b + d; 
	Point e = a - b - d;    
	cout<< "x :" << c.x << endl;
    cout<< "y :" << c.y << endl;
	cout<< "x :" << e.x << endl;
    cout<< "y :" << e.y << endl;

	cout << endl;
	cout << c << endl;

	Point p1 = c;
	cout << p1 << endl;

	++c;
	cout << c << endl;
	//cout << c++ << endl;

	//c++;
	cout << c << endl;

	if(a < b) cout << "a的x值更小" << endl;
	else cout << "b的x值更小" << endl;

	system("pause");
}
