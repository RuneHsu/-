// ref: http://www.nowcoder.com/test/question/done?tid=5192513&qid=45838

/************************************************************************
* 题目翻译理解

* ok，这道题翻译过来，就是进行多次输入，每次输入n个数，将这些数之间进行多次xor（异或操作），其中一个数可能被xor多次，看最后能剩余多少不重复的数，输出数量即可。
*
* 解题思路
*
* 在C++中，将两个数进行xor，用的是^符号，但是实际上是将十进制转换为二进制之后，再进行xor，这样，这n个十进制的数，就被转换成了n个二进制的包含1，0的字符串，将每个数转换成二进制之后单成一行，位数小的前面被补全0，这样这n个数就变成了n行矩阵，由于1 ≤ xi ≤ 1,000,000,000，而2的30次幂是10亿多，所以这个矩阵最大是n＊30的矩阵。
*
* 现在将这个矩阵列出来，如：
*
* 101010
* 111010
* 101101
* 110110
*
* 然后进行行与行之间的xor，其中1^1=0;  0^0=0;  1^0=1; 0^1=1;
* 有没有发现这种运算很像求矩阵的秩？相同的相减为0，不同的相减为1.
* 
* 矩阵的秩定义：是其行向量或列向量的极大无关组中包含向量的个数。
* 矩阵的秩求法：用初等行变换化成梯矩阵, 梯矩阵中非零行数就是矩阵的秩.
*
* 所以这道题就被转化成了求矩阵的秩, 求法如下。
********************************************************************/

// 矩阵的秩就是不能被其他表达的，变成梯形有杂项。 因为不可能可以由小的数异或得大的数，所以必须由最大的两个来异或看能不能得到小的。
// 如果最大的那个的最高位无法消除，则他无法通过任何数来得到，则必须购买
// 否则可以继续放在colors里面看能不能之后得到



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getHighBit(int num)
{
    int highBit = 0;
    while(num)
    {
        num >>= 1;
        highBit++;
    }
    return highBit;
}

int main()
{
    vector<int> colors;
    int n;
    
    while (cin >> n)
    {
        colors.clear();
        int result = 0;
        int temp;
        int i = n;
        while(--i)              // store the n colors
        {
            cin >> temp;
            colors.push_back(temp);
        }
        
        sort(colors.begin(), colors.end());         // sort them asendly
        int last, second;
        last = n - 1;           // last points to the last one which is the biggest one
        second = last - 1;      // second points to the one before the last
        
        while (colors.size() > 2)
        {
            // 如果两者的最高位相同，说明最高位可以消掉，
            // 将两者 xor ，或者说将矩阵两行相减消掉最高位
            if (getHighBit(colors[last]) == getHighBit(colors[second]))
            {
                int tem = colors[last]^colors[second];
                
                // 因为现在 xor 的是两个最大的数，而且最高位已被消掉，所以 xor 得到的结果一定比这两个数小
                // 如果temp这个比最大两个数小的数没有被找到，则将 temp 加到 colors 数组中，进行再次 xor
                // 找不到的话，返回 colors.end 应该是固定用法
                
                if (find(colors.begin(), colors.end(), tem) == colors.end())
                {
                    colors.push_back(tem);
                    sort(colors.begin(), colors.end());
                    last++;         // 因为 colors 中多了一个数，所以需要位数＋ 1
                    second++;
                }
            }
            else
            {
                result++;
            }
            
            // 如果两者最高位不同，说明已经所有数的最高位已经只有最大的那个数是 1 了，这样它已经不可能被消掉了，结果＋ 1
            // 如果两个最大数的最高位可以消掉，那么消除之后，最大数已被消掉，没有用了
            // 如果两个最大数的最高位不可以消掉，那么结果＋ 1 ，最大数也没有用了。
            // 弹出最大数
            colors.pop_back();
            
             // 因为弹出了一个数，所以 bigger 和 smaller 都要相应－ 1
            --last;
            --second;
        }
        cout << result + 2 << endl;
    }
}
