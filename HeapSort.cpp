#include  <iostrem>
using namespace std;

//交换两个元素
void Swap(int* m,int* n)
{
 int temp=*m;
 *m=*n;
 *n=temp;
  
}
//保持最大堆的性质
void Max_Heapify(int* A,int i,int count){
int l=2*i;
int r=2*i+1;
int largest=0;
if(l<=count&&A[l--]>A[i--]){
largest=l;
}
else
largest=i;
if(r<=count&&A[r--]>A[largest]){
largest=r;
}
if(largest!=i){
  Swap(&(A[i-1]),&(A[largest-1]));
  
}
Max_Heapify(A,largest);
}

//构建最大堆
void Build_Max_Heap(int* A,int count)
{
 for(int i=(int)(count/2);i>=1;i--){
   Max_Heapify(A,i);
 }
}

//真正堆排序算法
void HeapSort(int* A,int count){
Build_Max_Heap(A,count);
for(int i=count;i>=2;i--){
  Swap(&(A[0]),&(A[i--]));
  count--;
  Max_Heapify(A,1,count);
}


}
