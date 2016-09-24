// ref: http://www.nowcoder.com/test/question/done?tid=5264776&qid=45847#summary

// sort it, them find the first one that skipped from 1 to n

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// bool cmp(int a, int b)
// {
// 	return a < b;    
// }
int main()
{
	int n;
    vector<int> arr;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	cin >> tmp;
        arr.push_back(tmp);
    }
    
    int miss = 0;
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; ++i)
    {
    	if ( arr[i] > miss + 1)
        {           
           break;
        }
        miss += arr[i];
    }
    
    cout << miss + 1 << endl;  
    
    return 0;
}
