// ref: http://www.nowcoder.com/test/question/done?tid=5073179&qid=46578#summary

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    if ((n % 2 != 0) || n = 10 || n < 6 )   // if n is odd or < 6 or = 10, it is not possible
        res = -1;
    else if ( n % 8 == 0)                   // if n is multipler of 8, just divided it by 8
        res = n/8;
    else 
        res = n/8 + 1;                      // consider the mod by 8 can be 2, 4, 6, 8. If it is 2 or 4, 
                                            // just take out 2 apples from the previous 1 or 2 bags to compose 6 as a new bag
    return 0;
}
