#include<iostream>
using namespace std;

class minHeap
{
    int *hrr;
    int size;
    int heap_size;
    
public:
 minHeap(int x)
 {
    size=x;
    heap_size=0;
    hrr= new int[size];
    
 }
 
void insertKey(int x)
{
    if(heap_size==size)
    {
        cout<<"oberflow";
    }
    heap_size++;
    int i=heap_size-1;
    hrr[i]=x;
    while (i != 0 && hrr[parent(i)] > hrr[i]) 
    { 
       swap(&hrr[i], &hrr[parent(i)]); 
       i = parent(i); 
    } 
    
    
    
}
 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}  
 void minHeapify(int index)
 {
    int l=left(index);
    int r=right(index);
    if(hrr[index]>hrr[l]&& l<heap_size)
    {
        swap(&hrr[index],&hrr[l]);
        minHeapify(l);
        
    }    
    else if(hrr[index]>hrr[r]&& r<heap_size)
    {
        swap(&hrr[index],&hrr[r]);
        minHeapify(r);
        
    }
 }
 
 int parent(int i) { return (i-1)/2; } 
  
 int left(int i) { return (2*i + 1); } 
  
 int right(int i) { return (2*i + 2); }
 int getMin() { return hrr[0]; } 
   
 int extractMin()
 {
     if(heap_size==1)
     {
        heap_size--;
     return hrr[heap_size];
        }      
    // if (heap_size <= 0) 
      //  return INT_MAX; 
        
    int root = hrr[0];
    hrr[0]=hrr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
        
 }


};


int main() 
{ 
    minHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
   // h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(0); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
   // h.decreaseKey(2, 1); 
//    cout << h.getMin(); 
    return 0; 
} 