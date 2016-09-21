// ref: http://www.nowcoder.com/test/question/done?tid=5192513&qid=45842#summary

#include <iostream>
#include <string>

using namespace std;

bool huiWen(string str)
{
  int len = str.length();
  len -= 1;
  
  for (int i = 0; i < len / 2 ; ++i)
  {
    if (str[i] != str[len-i])
      return false;
  }
  return true;
}

int main()
{
  string str1, str2;
  cin >> str1 >> str2;
  int count = 0;
  string tmp;
  for (int i = 0; i <= str1.length(); ++i)    // pay attention that the str2 can be inserted in to the tail
  {
    tmp = str1;
    tmp.insert(i, str2);
    if  (huiWen(tmp))
    {
      count++;
    }
  }
  cout << count << endl;
  
  return 0;
}
