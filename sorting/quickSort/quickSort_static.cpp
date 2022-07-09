#include<iostream>
using namespace ::std;

int partition(int arr[],int s,int e){
    int pivot=arr[e];
    int pIndex=s;

    for(int i=s;i<e;i++){

        if(arr[i]<pivot){
            arr[i]=arr[i]+arr[pIndex];
            arr[pIndex]=arr[i]-arr[pIndex];
            arr[i]=arr[i]-arr[pIndex];
            pIndex++;
        }

    }
            arr[e]=arr[e]+arr[pIndex];
            arr[pIndex]=arr[e]-arr[pIndex];
            arr[e]=arr[e]-arr[pIndex];

            return pIndex;
}


void quickSort(int arr[],int s,int e){

    if(s<e){
        int p=partition(arr,s,e);
        quickSort(arr,s,p-1);
        quickSort(arr,p+1,e);
    }
}


int main(){
int arr[6]={72,48,96,12,34,58};
cout<<"Before Sorting -->"<<endl;
for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
quickSort(arr,0,5);
cout<<"after Sorting -->"<<endl;
for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}