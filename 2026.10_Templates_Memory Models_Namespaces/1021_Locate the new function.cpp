// newplace.cpp -- using placement new
#include <iostream>
#include <new>            // for placement new
const int BUF = 512;
const int N = 5;
char buffer[BUF];         // chunk of memory
int main()
{
    using namespace std;
    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];           //创建一个新数组,自动分配内存
    pd2 = new (buffer) double[N];  //使用buffer的内存块中的部分内存(前五位)创建一个新数组
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Memory addresses:\n" << "  heap: " << pd1
         << "  static: " << (void *) buffer  <<endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3= new double[N];            //自动分配内存,可能会分配到不同位置
    pd4 = new (buffer) double[N];  //仍使用buffer创建数组,地址一致,会覆盖pd2
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1= new double[N];                               //自动分配内存,可能会分配到不同位置
    pd2 = new (buffer + N * sizeof(double)) double[N];//继续使用buffer,但是使用了偏移量(N*单项长度),防止覆盖
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    delete [] pd1;//因为定位new的本质是将已经被划分好的内存临时划分给另外的对象
    delete [] pd3;//所以千万不要对定位new分配的对象使用delete
    return 0;
}