#include<iostream>
using namespace ::std;

int partition(int arr[],int s,int e){
    int pivot=arr[e];
    int pIndex=s;

    for(int i=s;i<e;i++){

        if(arr[i]<pivot){
            int temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }

    }
     
            int temp=arr[e];
            arr[e]=arr[pIndex];
            arr[pIndex]=temp;

             return pIndex;
}


void quickSort(int arr[],int s,int e){

    if(s<e){
        int p =partition(arr,s,e);
        quickSort(arr,s,(p-1));
        quickSort(arr,(p+1),e);
    }
}


int main(){
int size=0;
    cout<<"Enter the size of Array"<<endl;
    cin>>size;
int *arr=new int(size);
cout<<"Enter the elements for sorting"<<endl;
for(int i=0;i<size;i++){
    cin>>arr[i];
}
cout<<"Before Sorting -->"<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
quickSort(arr,0,(size-1));
cout<<"after Sorting -->"<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}