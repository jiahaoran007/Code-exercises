#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        string name;
        int sex;
        int age;
    public:
        Person();
        Person(string name_, int sex_, int age_):name(name_),sex(sex_),age(age_) {}
        void setInfo(string name_, int sex_, int age_)
        {
            name = name_;
            //strcpy(name, name_);
            sex = sex_;
            age = age_;
        }
        void getInfo()
        {
            cout << "姓名：" << name << endl;
            cout << "性别：" << sex << endl;
            cout << "年龄：" << age << endl;
        }
        virtual void IntrouduceSelf()
        {
            cout << "I am a Person" << endl;
        }
        virtual void getCurrentNum() = 0;
 };

class Student: public Person
{
    //Student(string n, int s, int a, int course_):Person(n,s,a), course(course_) {}
    private:
        int course;
    public:
        Student(string n, int s, int a, int course_):Person(n,s,a), course(course_) {}
        virtual void IntrouduceSelf()
        {
            cout << "I am a Student" << endl;
        }
        virtual void getCurrentNum()
        {
            cout <<  "课程数是" << course << endl;
        }
};

class Teacher: public Person
{
    private:
        int time;
    public:
        Teacher(string n, int s, int a, int time_):Person(n,s,a), time(time_) {}
            virtual void IntrouduceSelf()
        {
            cout << "I am a Teacher" << endl;
        }
        virtual void getCurrentNum()
        {
            cout <<  "授课时长是" << time << endl;
        }
};

int main()
{
    Student a1("xiaowang",1,17,5);
    Student a2("xiaozhang",2,19,4);
    a1.IntrouduceSelf();
    a1.getCurrentNum();
    a1.getInfo();
    cout << endl;
    a2.IntrouduceSelf();
    a2.getCurrentNum();
    a2.getInfo();
    cout << endl;

    

    system("pause");
}


