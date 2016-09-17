

#include <iostream>
#include <math.h>

using namespace std;

inline int sqr(int x)
{
  return x * x;
}

int main()
{
  int R, x[6], y[6];
  while (scanf("d", R) != EOF)
  {
    for (int i = 0; i < 4; i++)
    {
      scanf("%d%d", x[i], y[i]);
    }
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
      if (sqr(x[3] - x[i]) + sqr(y[3] - y[i]) >= sqr(R))
        res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
