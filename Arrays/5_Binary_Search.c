#include <stdio.h>
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    
    return -1;

}

int main()
{
int arr[]= {1,3,5,6,7,8,9,10,13,61,77};
int size = sizeof(arr)/sizeof(int);
int element = 7;
int searchindex = binarySearch(arr,size ,element);
printf("The element %d was found at index %d \n",element,searchindex);
    return 0;
}