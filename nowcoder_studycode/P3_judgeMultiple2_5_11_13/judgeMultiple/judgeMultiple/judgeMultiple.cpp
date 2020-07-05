/* -----------------------------------------------------------------------
 题目： 给出一个数n，求1到n中，有多少个数不是2 5 11 13的倍数。
        本题有多组输入,每行一个数n，1<=n<=10^18。
        每行输出输出不是2 5 11 13的倍数的数共有多少。
        如：输入“15”，输出“4”，说明“1 3 7 9”

思路：  从1-n中的所有数，从小到大依次取出；对2 5 11 13做取余运算，如果是
        相应的倍数，取余结果为0.
注意点：1）如数据i对2 5 11 13取余，只要有一个取余结果为0，则说明i为其倍数
           ，后续则不用对其他取余了；
        2）如数据i对2 5 11 13而言，需要同时对4个都不是倍数，那么需要注意不要
           将该数据重复添加到数据流中。
 ------------------------------------------------------------------------ */
// judgeMultiple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//由于 1<=n<=10^18，且n为整数
//    2^0 = 1 <= n <= 10^18 < 2^64 = 8字节
//    因此，采用的数据类型为：long long类型
#include "stdio.h"
#include "iostream"
#include "vector"
using namespace std;
//------------------   定义一个结构体分别记录不是2 5 11 13的倍数的数的个数
typedef struct NotMultiple {
    long long isnotall;  //总数
    vector<long long> datastream;//说明：数据流
}isnot_multiple;

isnot_multiple isnot_mult_data;  //用于缓存一次判断结果
//------------------   处理函数
void judgeMultipleFuction(long long num)
{
    for (long long i = 1; i < num + 1; i++) {
        if ( (0 != (i % 2)) && (0 != (i % 5)) && (0 != (i % 11)) && (0 != (i % 13))) {
            isnot_mult_data.isnotall ++;
            isnot_mult_data.datastream.push_back(i);
        }
    }
}
int main(int argc, char* argv[])
{
    long long n = 0;
    isnot_multiple result;

    do
    {
        isnot_mult_data.isnotall = 0;
        isnot_mult_data.datastream.clear();//擦除数据

        cout << "请键入n的值..." << endl;
        cin >> n;
        if (0 == n) {//如果键入“0”，则退出
            cout << "键入“0”，退出程序！" << endl;
            break;
        }
        else // 键入1-10^18的数据，则筛选数据
        {
            cout << "键入的n的值为： " << n << endl;

            judgeMultipleFuction(n);

            cout << isnot_mult_data.isnotall << endl; // 1)打印总个数
            for (long long i = 0; i < (isnot_mult_data.datastream.size()); i++)
            {
                cout << isnot_mult_data.datastream[i] << " ";
            }
            cout << endl; // 2)不换行打印数据
        }
    } while (n);
    return 0;

}

//#include<stdio.h>
//#include "iostream"
//using namespace std;
//#define ll long long
//int main()
//{
//    ll n;
//    while ((cin>>n))
//    {
//        ll ans1 = n / 2 + n / 5 + n / 11 + n / 13;
//        ll ans2 = n / 10 + n / 55 + n / 22 + n / 26 + n / 65 + n / 143;
//        ll ans3 = n / 110 + n / 130 + n / 286 + n / 715;
//        ll ans4 = n / 1430;
//        ll ans = ans1 - ans2 + ans3 - ans4;
//        ll ANS = n - ans;
//        printf("%lld\n", ANS);
//
//    }
//    return 0;
//}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
