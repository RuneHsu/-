/* ref: http://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8  */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void get_divisor(vector<int> &arr, int n)
{
    for (int i = 2; i <= sqrt(n); i++)     // just need consider half of the value, as the remainning is the reverse (A * B = C)
    {
        if (n % i == 0)
        {
          arr.push_back(i);               // record the A
          if (n / i != i)                       
            arr.push_back(n/i);         // consider the other divisor B
        }
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> res(m+1, 0);     // use res[x] to record reach step x should take how much times.
    res[n] = 1;                 
    
        for (int i = n; i <= m ; i++)
        {
          vector<int> arr;          // use to record the divisor
          if (res[i] == 0)          // cannot be reached
            continue;
          
          get_divisor(arr, i);     // calculate the divisor of step i
          
          for (j = 0; j < arr.size(); j++)
          {
            if (i + arr[j] <= m) && (res[i + arr[j]] != 0)          // if step (i + arr[j]) already being detected, then choose the minimum one
              res[i + arr[j]] = min(res[i + arr[j]], res[i] + 1)    // min(), former is the original one, res[i] + 1 is the newly detected one
            else if (i + arr[j] <= m)
              res[i + arr[j]] = res[i] + 1;
          }
          
        }
    if (res[m] == 0)          // cannot be reached
         cout << -1 << endl;
    else 
         cout << res[m] << endl;
    return 0;
}
