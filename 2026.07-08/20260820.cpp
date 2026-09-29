// 实验一_有序线性表插入删除.cpp
// 编译环境：C++11 及以上
// 功能：生成N个随机整数，构建有序表，按原序删除，计时比较N=100和N=400

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int MAX_CAPACITY = 1000;   // 线性表最大容量

// 生成N个0~999随机数，存入指定文件（每行一个数）
void generateData(int N, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "无法创建文件: " << filename << endl;
        exit(1);
    }
    srand((unsigned)time(nullptr));   // 用系统时间播种
    for (int i = 0; i < N; ++i) {
        int num = rand() % 1000;      // 0~999
        fout << num << endl;
    }
    fout.close();
    cout << "已生成 " << N << " 个随机数，保存至 " << filename << endl;
}

// 将元素b插入有序数组L（非递减），n为当前长度，保持有序
void insertSorted(int L[], int& n, int b) {
    if (n >= MAX_CAPACITY) {
        cerr << "溢出！" << endl;
        return;
    }
    int i = n - 1;
    while (i >= 0 && L[i] > b) {
        L[i + 1] = L[i];
        --i;
    }
    L[i + 1] = b;
    ++n;
}

// 从数组L中删除第一个值为b的元素，n为当前长度，成功返回true，否则false
bool deleteElem(int L[], int& n, int b) {
    if (n == 0) {
        cerr << "表空！" << endl;
        return false;
    }
    int i = 0;
    while (i < n && L[i] != b) ++i;
    if (i == n) {
        cerr << "元素 " << b << " 未找到！" << endl;
        return false;
    }
    for (int j = i; j < n - 1; ++j) {
        L[j] = L[j + 1];
    }
    --n;
    return true;
}

// 打印线性表（每行10个）
void printList(const int L[], int n, const string& title = "") {
    if (!title.empty()) cout << title << endl;
    for (int i = 0; i < n; ++i) {
        cout << L[i] << '\t';
        if ((i + 1) % 10 == 0) cout << endl;
    }
    if (n % 10 != 0) cout << endl;
    cout << "当前表长: " << n << endl;
}

int main() {
    int N;
    cout << "请输入随机数个数 N (例如 100 或 400): ";
    cin >> N;
    if (N > MAX_CAPACITY) {
        cout << "N 超过最大容量 1000，请重新输入。" << endl;
        return 1;
    }

    string filename = "data_" + to_string(N) + ".txt";
    // 1. 生成随机数文件
    generateData(N, filename);

    // 2. 定义有序表并初始化
    int L[MAX_CAPACITY] = {0};
    int n = 0;

    // 记录插入与删除的总耗时（时钟周期）
    clock_t start = clock();

    // 3. 从文件中读取N个整数，逐个插入有序表
    ifstream fin(filename);
    if (!fin) {
        cerr << "无法打开文件: " << filename << endl;
        return 1;
    }
    int b;
    for (int i = 0; i < N; ++i) {
        if (!(fin >> b)) {
            cerr << "文件数据不足！" << endl;
            break;
        }
        insertSorted(L, n, b);
    }
    fin.close();

    // 打印插入后的有序表（仅当N较小时显示，避免输出过长）
    if (N <= 100) {
        printList(L, n, "插入完成后的有序线性表：");
    } else {
        cout << "插入完成，表长为 " << n << "（因N较大，不打印全部内容）" << endl;
    }

    // 4. 按原随机顺序删除元素（重新读文件）
    fin.open(filename);
    if (!fin) {
        cerr << "无法重新打开文件: " << filename << endl;
        return 1;
    }
    vector<int> origin;          // 保存原始顺序，用于删除时对照（其实直接从文件读即可）
    while (fin >> b) origin.push_back(b);
    fin.close();
    // 若origin长度大于N，只取前N个
    if (origin.size() > N) origin.resize(N);

    // 逐个删除
    for (int i = 0; i < (int)origin.size(); ++i) {
        bool ok = deleteElem(L, n, origin[i]);
        if (!ok) {
            cerr << "删除 " << origin[i] << " 失败！" << endl;
            // 继续尝试删除其余元素
        }
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;  // 秒

    cout << "\n删除完成，表空？ " << (n == 0 ? "是" : "否，剩余 " + to_string(n) + " 个元素") << endl;
    cout << "总耗时: " << elapsed << " 秒" << endl;

    return 0;
}