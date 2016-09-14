/******************************************************************************************************** 
  如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
  {1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
  {1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。  
  现在给出一个数字序列，允许使用一种转换操作：
  选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
  现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

  输入描述:

  输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
  第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


  输出描述:

  输出一个数，表示最少需要的转换次数

  输入例子:

  4
  1 1 1 3

  输出例子:

  2
*******************************************************************************************************/

//利用递归，两端不论怎样都要相等或者最终合成为同一个数
#include <iostream>
using namespace std;
int comb(int* nums, int head, int tail) {
    int times = 0;
    int left = nums[head], right = nums[tail];
    while (head < tail && left != right) {
        if (left < right) left += nums[++head], times++;
        else right += nums[--tail], times++;
    }
    if (head >= tail) return times;
    else return times += comb(nums, ++head, --tail);
}
int main(){
    int n = 0;
    int nums[50] = {0};
    cin >> n;
    for( int i = 0; i < n; i++)
        cin >> nums[i];
    cout << comb(nums, 0, n-1);
}


/*思路：分别使用两个指针，从两头向中间靠拢。如果两个指针处的数值相等，两个指针同时向中间移动。
 
如果left指针处的值较小，让left指针处的数值不断地与后面的元素相加，直至>=right处的数值，
然后将得到的和存放在left指针处，在加的过程中，加的次数就合并的次数。
 
如果right指针处的数值较小，让right不断地与前面的数值相加，直至和>=left处的数值，
然后将和保存在right指针处，在加的过程中，加的次数就是合并的次数。*/

#include <isotream>
#include <vector>

using namespace std;

int fun(int n, vector<int> arr)
{
    int times = 0;
    if (n <= 1)
      return 0;
    head = 0;
    tail = n - 1;
    left = arr[head];
    right = arr[tail];
    while (head < tail)
    {
      if (left < right)
      {
        left += arr[++head];
        times++;
      }
      else if (left > right)
      {
        right += arr[--tail];
        times++;
      }
      else 
      {
        ++head;
        --tail;
        left = arr[head];
        right = arr[tail];
      }
    }
    return times;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  
  cout << fun(n, arr);
  
  return 0;
}
