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