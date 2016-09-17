// ref: http://www.nowcoder.com/test/question/done?tid=5140815&qid=26024#summary

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    long long n, l;
    while(cin >> n >> l)
    {
        vector<long long> lamps(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> lamps[i];
        }
        
        sort(lamps.begin(), lamps.end());
        
        double d = max(2*lamps[0], 2*(l - lamps[n - 1]));
        for (int i = 1; i < n; ++i)
        {
            
            if (lamps[i] - lamps[i - 1] > d)
            {
                d = (lamps[i] - lamps[i - 1]);
            }
            
        }
        printf("%.2f", d/2);
    }
    return 0;
}
