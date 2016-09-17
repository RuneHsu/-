// ref: http://www.nowcoder.com/test/question/done?tid=5129854&qid=36489#summary


// pay attention to the line condition

#include <iostream>
#include <math.h>

using namespace std;

void scan(vector<vector<int>> field, int N, int M, int result[])
{
  for (int i = 0; i < N -2; ++i)      // scan the whole grid
  {
    for (int j = 0; j < M - 2; ++j)
    {
      int temp = 0;
      for (int p = i; p < i + 3; ++p)   // scan the 3*3 grid
      {
        for (int q = j; q < j + 3; ++q)
        {
          if (field[p][q] > 0)    // if there is a mushroom in a square
          {
            temp++;
          }
        }
      }
      if (result[0] < temp)   // the newly found mushrooms are more than older
      {
        result[0] = temp;
        result[1] = i;
        result[2] = j;
      }
    }
  }
}

int main()
{
  int N, M, K;
  int x, y;
  while(cin >> N >> M >> K)
  {
    if (N < 3)
      N = 3;
    if (M < 3)
      M = 3;
    vector<vector<int>> field(N, vector<int> M);  // record the grid
    for (int i = 0; i < N; ++i)   
    {
      for (int j = 0; j < M; ++j)
      {
        while(--K)                        // record the square that has mushroom
        {
          cin >> x >> y;
          field(x - 1, y - 1)++;
        }
      }
    }
    
    int first[3] = {0};   // f[0] means the mushrooms in the scaned grid, f[1] is coordinate x, f[2] is coordinate y
    int second[3] = {0};
    
    scan(field, N, M, first);
    
    for (int i = first[1]; i < first[1] + 3; ++i)     // delete the mushroom scaned in the first time
    {
      for (int j = first[2]; j < first[2] + 3; ++j)
      {
        if (field[i][j] > 0)
        {
          --field[i][j];
        }
      }
    }
    
    scan(field, N, M, second);
    
    cout << first[0] + second[0] << endl;
  }
}
