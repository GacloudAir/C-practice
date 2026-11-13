// placenew1.cpp -- new, placement new, no delete
#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0)
    {words = s; number = n; cout << words << " constructed\n"; }
    ~JustTesting() { cout << words << " destroyed\n";}
    void Show() const { cout << words << ", " << number << endl;}
};

int main()
{
    char * buffer = new char[BUF];       //创建了一个存储内存的数组

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;      //创建了一个内存位于数组内的对象
    pc2 = new JustTesting("Heap1", 20);  // place object on heap

    cout << "Memory block addresses:\n" << "buffer: "
        << (void *) buffer << "    heap: " << pc2 <<endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6); //创建的对象指向pc1的内存,pc1被覆盖,形成野指针
                                                   //正常使用时应该以pc1的大小进行偏移
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
                                         //pc1和pc3指向的并非堆内存,不能直接使用delete释放
                                         //但是pc3内的string对象的析构函数未被调用,会造成内存泄漏
    delete pc1;                          
    delete pc2;                          // free Heap1
    delete pc4;                          // free Heap2
    delete [] buffer;                    
    cout << "Done\n";
    return 0;
}