// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);       // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;            //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;       //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust;  //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;            //  new customer data
    long turnaways = 0;   //  turned away by full queue
    long customers = 0;   //  joined the queue
    long served = 0;      //  served during the simulation
    long sum_line = 0;    //  cumulative line length
    int wait_time = 0;    //  time until autoteller is free
    long line_wait = 0;   //  cumulative time in line

// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)//模拟一轮时间轴,代表现实中一分钟过去
    {
        if (newcustomer(min_per_cust))  //新顾客到达？
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.enqueue(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty())//柜员机空闲+队里有人？
        {
            line.dequeue (temp);      //队里顾客出列
            wait_time = temp.ptime(); //柜员机进入忙等待
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)//柜员机忙？
            wait_time--;//继续忙
        sum_line += line.queuecount();//累计当前队伍长度,用于最后计算平均长度
    }

// reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); //随机数生成顾客函数,每次调用触发概率为1/x
}