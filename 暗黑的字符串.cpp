/* ref: http://www.nowcoder.com/questionTerminal/7e7ccd30004347e89490fefeb2190ad2 */

#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  long long dp[31] = {0};
  dp[1] = 3;
  dp[2] = 9;
  for (int i = 3; i < n; i++)
  {
    dp[i] = 2 * dp[i-1] + dp[i-2];
  }
  
  cout << dp[n] << endl;
}

