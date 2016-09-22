// ref: 

#include <iostream>

using namespace std;

int main()
{
  int N, l, r, f0, f1, f;
  f0 = 0;
  f1 = 1;
  cin >> N;
  while(1)
  {
    f = f0 + f1;
    f0 = f1;
    f1 = f;
    if ( f < N)
      l = N - f;
    else if ( f > N)
    {
      r = N - f;
      break;
    }
  }
  cout << min(l, r) << endl;
  return 0;
}
