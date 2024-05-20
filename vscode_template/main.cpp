#include <iostream>
using namespace std;

class Point{
public:
    Point(){};
    Point (int x, int y): x(x),y(y) {};
	Point(const Point &a) //���ƹ��캯��
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

    friend Point operator+(const Point &a, const Point &b);   //���������Ԫ����
    int x,y;
	static int count ;
	friend ostream &operator<<(ostream &out, Point &a);  
};

Point operator+(const Point &a,const Point &b){//��������,��������غ�����Ϊ�����Ԫ����
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
	Point::count++;
	cout << "��"<< Point::count << "�ε���" << endl;
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
	//cout << "Point��x����Ϊ" << a.x;
	//cout << "Point��y����Ϊ" << a.x << endl;
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

	if(a < b) cout << "a��xֵ��С" << endl;
	else cout << "b��xֵ��С" << endl;

	system("pause");
}
