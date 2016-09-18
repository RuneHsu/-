// ref: http://www.nowcoder.com/test/question/done?tid=5149200&qid=46126#summary

#include <iostream>
#include <math.h>
#include <vector>
 
using namespace std;
 
void shuffle(vector<int> &list, int n)
{
    vector<int> left, right;
     
    for (int i = 0; i < 2*n; ++i)
    {
        if (i < n)
            left.push_back(list[i]);
        else
            right.push_back(list[i]);
    }
     
    int leftnum = 0;
    int rightnum = 0;
     
    for (int i = 0; i < 2*n; ++i)
    {
        if ( i % 2 == 0)
            list[i] = left[leftnum++];
        else
            list[i] = right[rightnum++];
    }
}
 
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> list(2*n, 0);
         
        for (int i = 0; i < 2*n; ++i)
        {
            cin >> list[i];
        }
         
        for (int i = 0; i < k; ++i)
        {
            shuffle(list, n);
        }
         
        for (int i = 0; i < 2*n - 1; ++i)
        {
            cout << list[i] << " ";
        }
        cout << list[2*n - 1] << endl;
    }
     
    return 0;
}
