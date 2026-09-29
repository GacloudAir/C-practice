#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double random1_100()
{
    srand(static_cast<unsigned int>(time(0))); // 设置随机种子
    return rand() % 100 + 1; // Generate a random number between 1 and 100
}

int main() {
    double num = random1_100();
    cout << "Random number: " << num <<endl;
    return 0;
}
