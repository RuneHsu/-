// ref: http://www.nowcoder.com/test/question/done?tid=5129854&qid=36487

// The most important thing is to find gcd

#include <iostream>
#include <math.h>

using namespace std;

int gcd(int m, int n)
{
  if (n == 0)
    return m;
  else
    return gcd(n, m % n);
}

int main()
{
  int a, n;
  while (scanf("%d %d", &n, &a) != EOF)
  {
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &b);
      if (b < a)
        a += b;
      else
        a += gcd(b, a);
    }
    prinf("d", a);
  }
  return 0;
}
