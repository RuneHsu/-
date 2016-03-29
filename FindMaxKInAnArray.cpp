// 问题：查找大量无序元素中最大的K个数。
// ref: http://blog.csdn.net/xiaoding133/article/details/8037086
// Date: 2016-03-29
/************************************************************************************************************************
 * 解法一：数据量不大可以采用快速排序或者堆排序，时间复杂度为O(N*logN)+O(K)
 *
 * 解法二：避免对前K个数进行排序来获取更好的性能(利用快速排序的原理)。
 *         假设N个数存储在数组S中，从数组中随机找一个元素X，将数组分成两部分Sa和Sb.Sa中的元素大于等于X,Sb中的元素小于X。
 *         出现如下两种情况：
 *         (1)若Sa组的个数大于或等于K，则继续在sa分组中找取最大的K个数字 。
 *         (2)若Sa组中的数字小于K ，其个数为T，则继续在sb中找取 K-T个数字 。
 *         一直这样递归下去，不断把问题分解成小问题，平均时间复杂度为O(N*logK)。
 *
 * 解法三：用容量为K的最小堆来存储最大的K个数。最小堆的堆顶元素就是最大K个数中的最小的一个。
 *         每次扫描一个数据X，如果X比堆顶元素Y小，则不需要改变原来的堆。如果X比堆顶元素大，
 *         那么用X替换堆顶元素Y，在替换之后，X可能破坏了最小堆的结构，需要调整堆来维持堆的性质。
 *         调整过程时间复杂度为O(logK)。 全部的时间复杂度为O(N*logK)。
 *         这种方法当数据量比较大的时候，比较方便。因为对所有的数据只会遍历一次，第一种方法则会多次遍历数组。 
 *         如果所查找的K的数量比较大。可以考虑先求出k，然后再求出看k+1 到 2 * k之间的数据，然后一次求取。
 *         父节点为i,则其子节点分别为2i+1, 2i+2。
 *************************************************************************************************************************/
// 解法二代码：
/*将数组a[s]...a[t]中的元素用一个元素划开，保存中a[k]中*/  
void partition(int a[], int lowIdx,int highIdx,int &k)    
{    
    int i,j,x;    
    x=a[lowIdx];    //取划分元素     
    i=lowIdx;        //扫描指针初值     
    j=highIdx;    
    do    
    {   // floor search
        while((a[j]<x)&&i<j) j--;      //从右向左扫描,如果是比划分元素小，则不动  
        if(i<j) a[i++]=a[j];           //大元素向左边移     
        while((a[i]>=x)&&i<j) i++;     //从左向右扫描，如果是比划分元素大，则不动   
        if(i<j) a[j--]=a[i];           //小元素向右边移     
    
    }while(i<j); //直到指针i与j相等      
    a[i]=x;      //划分元素就位     
    k=i;    
}    
/*查找数组前K个最大的元素，index:返回数组中最大元素中第K个元素的下标(从0开始编号),highIdx为数组最大下标*/  
int FindKMax(int a[],int lowIdx,int highIdx,int k)  
{   
   int q;                                   // partition position
   int index=-1;  
   if(lowIdx < highIdx)    
      {    
        partition(a , lowIdx , highIdx,q);    
        int len = q - lowIdx + 1; //表示第几个位置      
        if(len == k)    
         index=q; //返回第k个位置     
        else if(len < k)      //  if left partition has elements number larger less than k, move the k-len largest elements into left part
         index= FindKMax(a , q + 1 , highIdx , k-len);       
        else   
         index=FindKMax(a , lowIdx , q - 1, k);    
      }    
    return index;  
  
}  
int main()  
{  
    int a[]={20,100,4,2,87,9,8,5,46,26};    
    int Len=sizeof(a)/sizeof(int);   
    int K=4;  
    FindKMax(a , 0 , Len- 1 , K) ;      
    for(int i = 0 ; i < K ; i++)    
      cout<<a[i]<<" ";    
    return 0;  
}  

// 解法三代码：
void heapifymin(int Array[],int i,int size)  
 {  
    if(i<size)  
 {  
  int left=2*i+1;  
  int right=2*i+2;  
  int smallest=i;//假设最小的节点为父结点  
  //确定三个结点中的最小结点  
  if(left<size)  
  {  
    if(Array[smallest]>Array[left])  
    smallest=left;  
  }  
  if(right<size)  
  {  
    if(Array[smallest]>Array[right])  
    smallest=right;  
  }  
  
  //开始交换父结点和最小的子结点  
       if(smallest!=i)  
    {  
     int temp=Array[smallest];  
     Array[smallest]=Array[i];  
     Array[i]=temp;  
     heapifymin(Array,smallest,size);//对调整的结点做同样的交换  
    }  
 }  
 }  
 //建堆过程，建立最小堆,从最后一个结点开始调整为最小堆  
void min_heapify(int Array[],int size)  
 {  
  int i;  
  for(i=size-1;i>=0;i--)  
   heapifymin(Array,i,size);  
    
 }  
 //k为需要查找的最大元素个数，size为数组大小，kMax存储k个元素的最小堆  
void FindMax(int Array[],int k,int size,int kMax[])  
{  
  
   for(int i=0;i<k;i++)  
   kMax[i]=Array[i];  
   //对kMax中的元素建立最小堆  
   min_heapify(kMax,k);  
   printf("最小堆如下所示 : \n");  
   for(i=0;i<k;i++)  
   printf("%4d",kMax[i]);  
   printf("\n");  
  
 for(int j=k;j<size;j++)  
  {  
     if(Array[j]>kMax[0]) //如果最小堆的堆顶元素，替换  
    {  
      int temp=kMax[0];  
      kMax[0]=Array[j];  
      Array[j]=temp;  
      //可能破坏堆结构，调整kMax堆  
      min_heapify(kMax,k);  
    }  
  } 
}  
  
int main()  
{  
      
 int a[]={10,23,8,2,52,35,7,1,12};  
 int length=sizeof(a)/sizeof(int);  
  
    //最大四个元素为23,52,35,12  
/***************查找数组中前K个最大的元素****************/  
 int k=4;  
 int * kMax=(int *)malloc(k*sizeof(int));  
 FindMax(a,k,length,kMax);  
  
   printf("最大的%d个元素如下所示 : \n",k);  
    for(int i=0;i<k;i++)  
        printf("%4d",kMax[i]);  
 printf("\n");  
 return 0;  
}  

