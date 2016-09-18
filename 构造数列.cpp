// ref: http://www.nowcoder.com/test/question/done?tid=5149200&qid=46127#summary


//将顺序序列处理得出结果
//比如1 2 3 4 5，先将5插入到3、4之间（隔1），得到1 2 3 5 4，再将4插入到2、3之间（隔2），得到1 2 4 3 5，再将5插入
//到1、2之间（隔3），得到1 5 2 4 3，最后将3插入到1前面（隔4），得到最终结果：3 1 5 2 4
//从上面例子可看出，不断的将最后一个元素插入到前面，规律为相隔元素个数依次递增，上面是从1到4

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> list;
        for (int i = 1; i <= n; ++i)
        {
            list.push_back(i);
        }
        
            for(int i = 1; i < n; ++i)
            {
                int tmp = *(list.end() - 1);    // record the last element
                list.insert(list.end() - i - 1, tmp);       // insert it into the position
                list.pop_back();                // remove the last element(already inserted into previous)
            }
        for (int i = 0; i < n - 1; ++i)
        {
            cout << list[i] << " ";
        }
        cout << list[n - 1] << endl;
    }
}
