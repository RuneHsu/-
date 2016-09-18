// ref: 

//这题应该是用快排的思想：例如找49个元素里面第24大的元素，那么按如下步骤：
// 1.进行一次快排（将大的元素放在前半段，小的元素放在后半段）,假设得到的中轴为p
// 2.判断 p - low + 1 == k ，如果成立，直接输出a[p]，（因为前半段有k - 1个大于a[p]的元素，故a[p]为第K大的元素）
// 3.如果 p - low + 1 > k， 则第k大的元素在前半段，此时更新high = p - 1，继续进行步骤1
// 4.如果p - low + 1 <  k， 则第k大的元素在后半段， 此时更新low = p + 1, 且 k = k - (p - low + 1)，继续步骤1.
// 由于常规快排要得到整体有序的数组，而此方法每次可以去掉“一半”的元素，故实际的复杂度不是o(nlgn), 而是o(n)。

class Finder{
public:
  int findKth(vector<int> a, int n, int K)
  {
    return quickFind(a, 0, n - 1, K);
  }
  
  int quickFind(vector<int> &a, int left, int right, int k)
  {
    int i = left;
    int j = right;
    int mark = a[left];
    while(i < j)
    {
     while(i < j && a[j] <= mark)
      {
        --j;
      }                             // when this loop stopped, a[j] > mark > a[j++]
      
      a[i] = a[j];                  // move the larger one to left
        
      while(i < j && a[i] >= mark)
      {
        i++;
      }                             
       a[j] = a[i];                 // move the smaller one to right
    }
    
    mark = a[i];
    
    int big_num = i - left;
    
    if (k - big_num - 1 == 0)
      return mark;
    else if (k - big_num - 1 > 0)         // if there is more than k elements larger than mark
      quickFind(a, i + 1, right, k - big_num - 1);
    else
      quickFind(a, left, i - 1, k);  // if there is smaller number of elements larger than mark
  }
};
