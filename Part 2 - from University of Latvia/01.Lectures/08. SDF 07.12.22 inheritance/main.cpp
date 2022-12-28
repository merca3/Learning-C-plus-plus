#include <iostream>
using namespace std;

class person
{
    string name;
    int birthyear;

public:
    person(const string &n, int b)
    {
        name = n;
        birthyear = b;
    }
    virtual void print(char e = '\n')
    {
        cout << name << " " << birthyear << e;
    }
};

class student : public person
{
    int studyyear;

public:
    student(const string &n, int b, int s) : person(n, b)
    {
        studyyear = s;
    }
    void print(char e = '\n')
    {
        person::print(' ');
        cout << studyyear << e;
    }
};
class teacher : public person
{
    string position;

public:
    teacher(const string &n, int b, const string &p) : person(n, b)
    {
        position = p;
    }
    void print(char e = '\n')
    {
        person::print(' ');
        cout << position << e;
    }
};
int main()
{
    // person p("Peter", 1995);
    // p.print();
    // student s("Ann", 2000, 1);
    // s.print();
    // teacher t("John", 1971, "professor");
    // t.print();

    // using dynamic objects
    person *p = new person("Peter", 1995);
    p->print();
    delete p;
    person *s = new student("Ann", 2000, 1);
    s->print();
    delete s;
    person *t = new teacher("John", 1971, "professor");
    t->print();
    delete t;
}
