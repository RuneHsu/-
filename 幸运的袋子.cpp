// ref: http://www.nowcoder.com/test/question/done?tid=5192513&qid=45839#summary

#include <iostream>
#include <stdlib.h>

using namespace std;

int n;
int nums[1000];

int cmp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int DFS(int nums[], int index, long sum, long multi)
{
    int count = 0;
    for(int i = index; i < n; i++)
    {
        sum += nums[i];
        multi *= nums[i];
        if (sum > multi)
            count += 1 + DFS(nums, i + 1, sum, multi);
        else if (nums[i] == 1)
            count += DFS(nums, i + 1, sum, multi);
        else
            break;
        
        sum -= nums[i];
        multi /= nums[i];
        // skip the duplicates
        while(i < n - 1 && nums[i] == nums[i+1])
            ++i;
    }
    return count;
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        
        // sort them ascendingly
        qsort(nums, n, sizeof(int), cmp);
        cout << DFS(nums, 0, 0, 1) << endl;
    }
    return 0;
}
