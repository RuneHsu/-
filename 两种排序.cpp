// ref: http://www.nowcoder.com/test/question/done?tid=5245966&qid=45844#summary


#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLexi(vector<string> &vec)
{
    int i = 0;
    
 	while((i+1) < vec.size())
    {
    	if (vec[i+1].compare(vec[i]) < 0)
            return false;
        ++i;
    }
    return true;
}

bool isLength(vector<string> &vec)
{
    int i = 0;
	while((i+1) < vec.size())
    {
    	if (vec[i+1].size() < vec[i].size())
            return false;
        ++i;
    }
    return true;
}

int main()
{
	vector<string>	vec;
    int n;
    string tmp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	cin >> tmp;
        vec.push_back(tmp);
    }

    	bool Lexi = isLexi(vec);
    	bool Length = isLength(vec);
    
    	if (Lexi && Length)
        	cout << "both" << endl;
    	else if (Lexi)
        	cout << "lexicographically" << endl;
    	else if (Length)
        	cout << "lengths" << endl;
    	else
        	cout << "none" << endl;
        
    return 0;
}
