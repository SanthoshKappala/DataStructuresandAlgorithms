#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[], int l, int m, int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int partition(int arr[], int low, int high){
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *original=(int*)malloc(n*sizeof(int));
    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&original[i]);

    int *arr1=(int*)malloc(n*sizeof(int));
    int *arr2=(int*)malloc(n*sizeof(int));
    int *arr3=(int*)malloc(n*sizeof(int));
    int *arr4=(int*)malloc(n*sizeof(int));
    int *arr5=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        arr1[i]=arr2[i]=arr3[i]=arr4[i]=arr5[i]=original[i];
    }

    bubbleSort(arr1,n);
    printf("Bubble Sort: ");
    printArray(arr1,n);

    selectionSort(arr2,n);
    printf("Selection Sort: ");
    printArray(arr2,n);

    insertionSort(arr3,n);
    printf("Insertion Sort: ");
    printArray(arr3,n);

    mergeSort(arr4,0,n-1);
    printf("Merge Sort: ");
    printArray(arr4,n);

    quickSort(arr5,0,n-1);
    printf("Quick Sort: ");
    printArray(arr5,n);

    free(original);
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);

    return 0;
}
