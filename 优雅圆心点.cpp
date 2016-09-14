/* ref: http://www.nowcoder.com/test/question/done?tid=5073179&qid=46573#summary  */

/**** 四个象限都可以根据其中一个来判定其他三个（正负号改变而已）****/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int r;
    cin >> r;
    int nums = 0;
    for (int i = 0; i <= sqrt(r); i++)
    {
      double j = sqrt(r - i*i);           // in case of exceed the size of double
      if ((int) j >= j)                   // use >= to make sure the converting of decimal fraction won't effect the result
      {
        nums++;
      }
    }
    cout << 4*nums << endl;
    return 0;
}


/****** original solution(stupid solution) *************/
#include <iostream>
#include <math.h>
using namespace std;

int cal(int r)
{
    int num = 0;
    
    for (int i = -r; i <= r; i++)
    {
        for (int j = -r; j <= r; j++)
        {
            if (i^2 + j^2 == r^2)
                num++;
        }
    }
    return num;
        
}

int main()
{
    int r_square;
    cin >> r_square;
    int r = sqrt(r_square);
    cout << cal(r);
}

