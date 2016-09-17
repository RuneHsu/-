// ref: http://www.nowcoder.com/test/question/done?tid=5140815&qid=26023

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct score_hour
{
    long score;
    long hour;
};

bool cmp(score_hour a, score_hour b)
{
    return a.hour < b.hour;
}

int main()
{
    long n, r, avg;
    while(cin >> n >> r >> avg)
    {
        vector<score_hour> courses;
        long cur_score = 0;
        score_hour tmp;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp.score >> tmp.hour;
            courses.push_back(tmp);
           // cin >> courses[i].score >> courses[i].hour;   NOT EXECUTABLE????
            cur_score += courses[i].score;
        }
        long target = avg * n;
        
        if (cur_score >= target)
            cout << 0 << endl;
        else
        {
            sort(courses.begin(),courses.end(), cmp);
        
            long sumTime = 0;
        
            for (int i = 0; i < n; ++i)
            {
                cur_score += (r - courses[i].score);
                if (cur_score >= target)
                {
                    cur_score -= (r - courses[i].score);
                    sumTime += (target - cur_score) * courses[i].hour;
                    cout << sumTime << endl;
                }
                else
                    sumTime += (r - courses[i].score) * courses[i].hour;
            }
        }
    }
}
