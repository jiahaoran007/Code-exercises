#include <iostream>
using namespace std;

class Point{
public:
    Point(){};
    Point (int x, int y): x(x),y(y) {};
    friend Point operator+(const Point &, const Point &);
    friend ostream &operator<<(ostream &out , const Point &a);
    Point& operator++(){ //前置++运算符，需要引用返回，不需要参数。返回自增后的值，且返回的是一个左值 
        this->x ++;
        this->y ++;
        return *this;
    }
     //const 修饰返回值不能修改  
    const Point operator++(int){//后置++，不需要引用返回，需要参数区分。返回自增前的值，且返回的是一个右值
        Point temp(x,y);       //因为后置++，是先使用，后自++，所以这里要保存一个临时值，再++，返回的是临时值。
        this->x ++;
        this->y ++;
        return temp;
    }
private:
    int x,y;
};

Point operator+(const Point &a,const Point &b){
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
}

ostream &operator<<(ostream &out , const Point &a){
    out << "<Point>(" << a.x << " , " << a.y << ")";
    return out;
}


int main() {
    Point a(2,4),b(5,3);
    Point c = a + b;
    cout << c << endl;
    c++;
    cout << c << endl;
    ++c;
    cout << c << endl;
    system("pause");
}
