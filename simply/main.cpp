#include <iostream>

using namespace std;
class a
{
public:
    virtual void show()=0;
};

class b:public a
{
public:
    void show()
    {
        cout<<"THIS IS A IN B";
    }
};
int main()
{
    a *q;
    b w;
    q=&w;

    q->show();
    return 0;
}
