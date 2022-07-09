#include <iostream>
using namespace ::std;


void insertionSort(int arr[],int n){
int i=0,j=0,key=0;

for(i=1;i<n;i++){
    key=arr[i];//picking the element
    j=i-1;//intialzing the operator

    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];//copying higher values in the higher places
        j=j-1;
    }
    arr[j+1]=key;//returning the small value in lower boxes.
}
cout<<"The sorted Array is as follows "<<endl;
for(int k=0;k<n;k++){
    cout<<arr[k]<<"\t";
}
}

 
int main()
{
int n;
cout<<"Enter the size of Array"<<endl;
cin>>n;
int *arr=new int(n);
cout<<"Enter the elements for Sorting (insertion sort)"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

insertionSort(arr,n);
    return 0;
}