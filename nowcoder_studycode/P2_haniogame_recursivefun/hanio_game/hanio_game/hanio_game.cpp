/*------------------------------------------------------------------------------
Hanio汉诺塔问题:
    源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，
    在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘
    从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大
    圆盘，在三根柱子之间一次只能移动一个圆盘。

    我们姑且不去追溯传说的缘由，现考虑一下把64片金片，由一根针上移到另一根针
    上，并且始终保持上小下大的顺序。这需要多少次移动呢?这里需要递归的方法。
    假设有n片，移动次数是f(n).显然f(1)=1,f(2)=3,f(3)=7，且f(k+1)=2*f(k)+1。
    此后不难证明f(n)=2^n-1
--------------------------------------------------------------------------------*/
#include <iostream>//输入输出流，如cin/cout
#include "cstring" //用于封装字符串数据结构，如使用string数据类型
#include "vector"  //添加vector容器

using namespace std;//使用标准命名空间
//----------------      全局参数定义       ------------------
int moveNum = 0;   //移动次数
//---------------- Hanio汉诺塔代码递归实现 ------------------
//----- recursive function ------

void hanio(int n,string A,string B,string C) 
{
    //如果n为1，则直接将圆盘从A柱移动到C柱
    if (n == 1) {
        cout << "move 圆盘 1" << " from " << A << " to " << C << endl;
        moveNum++;
    }
    else { //如果n不为1
            //将所有圆盘从A柱移动至C柱需要三步：
            //   1)将A柱中前n-1个圆盘移动至B柱；
            //   2)将A柱中最下面一个圆盘移动至C柱；
            //   3)将B柱中n-1个圆盘移动至C柱；
        hanio(n - 1, A, C, B); // 1)

        //hanio(1, A, B, C);   // 2)
        cout << "move 圆盘 " << n << " from " << A << " to " << C << endl;
        moveNum++;

        hanio(n - 1, B, A, C); // 3)
    }
}

//----------------           main         --------------------
int main()
{
    string A = "Left ";
    string B = "Mid  ";
    string C = "Right";//定义左-中-右
    int n=0;//定义汉诺塔数量
    cout << "本次汉诺塔游戏将n个圆盘从Left转移到Right柱子！" << endl;

    do
    {
        cout << "请输入汉诺塔数量..." << endl;
        cin >> n;//读取数量

        if (0 == n) { //输入0则退出游戏
            cout << "键入“0” 退出游戏！" << endl;
            break; 
        }
        else {     // 键入汉诺塔圆盘数量
            hanio(n, A, B, C);
            cout << "移动结束！ 移动次数为：" << moveNum << endl;
        }
        moveNum = 0;//清除移动次数
    } while (n);
}

//----------------       采用类     --------------------
class Hanoi {
public:
    const string A = "left";
    const string B = "mid";
    const string C = "right";
    vector<string> vecdata;
    void move(int n, string A, string B, string C) {
        if (1 == n) {
            cout << "move 圆盘 1 from " << A << " to " << C << endl;
            //vecdata.push_back("move 圆盘 1 from "+A+" to "+C);
            vecdata.push_back("move from " + A + " to " + C);
        }
        else {
            move(n - 1, A, C, B);
            cout << "move 圆盘 " << n << " from " << A << " to " << C << endl;
            //vecdata.push_back("move 圆盘 "+(to_string(n))+" from "+A+" to "+C);
            vecdata.push_back("move from " + A + " to " + C);
            move(n - 1, B, A, C);
        }
    }
    vector<string> getSolution(int n) {
        // write code here
        move(n, A, B, C);
        return vecdata;
    }
};





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
