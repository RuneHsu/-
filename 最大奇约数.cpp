// ref: http://www.nowcoder.com/test/question/done?tid=5073179&qid=46577#summary

// Original way 

#include <iostream>
#include <math.h>

using namespace std;

int maxDivisor(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i += 2)
    {
        if (n % i == 0 && i > res)
        {
            res = i;
            if ( n / i != i)
            {
                if (n/i > i)
                    res = n/i;
            }
        }
    }
    return res;
}

int sumOfDivisor(int n)
{
    int res = 0;
    int div = 0;
    for (int i = 1; i <= n; i++)
    {
        div = maxDivisor(i);
        res += div;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDivisor(n) << endl;
    return 0;
}

// Consider that when the num is odd, the max odd divisor is itself
// else, if the num is even, divide by 2, untill the remainer is odd

#include <iostream>
#include <math.h>

int main()
{
    long long n;
    cin >> n;
    long long res = 0;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            res += n;
            --n;
            continue;
        }
        else
        {
            int divisor = n;
            while (divisor % 2 == 0)
            {
                divisor /= 2;
            }
            res += divisor;
            --n;
        }
    }
    cout >> res << endl;
    return 0;
}


// advanced
/* 
    1.判断n是否为奇数，如果为奇数，求所有奇数的和
    2.如果为偶数，求最后一个偶数的最大质约数，在求前n-1的奇数和
    3.在n减半，依次循环求和
    最后时间复杂度为lg（n）到lg（n）*lg（n）之间
*/
#include <iostream>
using namespace std;
int main()
{
    long long n;
    while(cin>>n){
        long long sum = 0;
        while(n > 0)
        {
            if (n%2 == 0)
            {
                long long temp = n;
                while(temp!=1){
                    temp /= 2;
                    if(temp%2 == 1)
                        break;
                }
                sum += temp;
                n = n-1;
            }
            sum += (n+1)*(n+1)/4;
            n /= 2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
