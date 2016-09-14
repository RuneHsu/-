// ref: http://www.nowcoder.com/test/question/done?tid=5073179&qid=46579#summary

// remember to verify the integer !!!

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x, y, z, w;
    int A, B, C;
    cin >> x >> y >> z >> w;
    A = (x + z) / 2;
    B = A - x;
    C = B - y;
    
    if ( A >= 0 && B >= 0 && C >= 0 && (A - int(A) == 0) && (B - int(B) == 0) && (C - int(C) == 0) && (B + C == w))
        cout << A << " " << B << " " << C << endl;
    else
        cout << "NO" << endl;   
    return 0;
}
