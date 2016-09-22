// ref: http://www.nowcoder.com/test/question/done?tid=5245966&qid=45845#summary


//
//  main.cpp
//  小易喜欢的单词
//
//  Created by Hang.Xu on 22/09/2016.
//  Copyright © 2016 Hang.Xu. All rights reserved.
//

#include <iostream>
#include <set>

// #include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> type;

int hasubseq(string &str)
{
    set<type> seg;      // piar(start, end)
    unordered_set<char> hash;
    for (int i = 0; i < str.length(); ++i)
    {
        if (hash.find(str[i]) != hash.end())
            continue;
        hash.insert(str[i]);
        for(int j = str.length()-1; j > i; --j)
        {
            if (str[i] != str[j])
                continue;
            for(set<type>::iterator it = seg.begin(); it != seg.end(); ++it)
            {
                if (it->second > i && it->second < j) return 1;
                if (it->first > i && if->first < j) return 1;
            }
            seg.insert(make_pair(i, j));
            break;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    for(string str; cin >> str;)
    {
        int flag = 1;
        if (flag)   // ABBA
        {
            for (int i = 1; i < str.length(); ++i)
            {
                if (str[i] == str[i-1])
                {
                    cout << "Dislikes" << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            if (hasubseq(str))
            {
                cout << "Dislikes" << endl;
                flag = 0;
            }
        }
        if (flag)
        {
            map<char, int> m;
            for(int i = 0; i < str.length(); ++i)
            {
                m[str[i]]++;
                if (m[str[i]] > 3)
                {
                    cout << "Dislikes" << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << "Likes" << endl;
    }
    return 0;
}
// my idea
