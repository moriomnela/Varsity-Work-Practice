#include<stdio.h>
int binarySearch(int arr[],int l,int r,int x){
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==x){
            return m;
        }
        if(arr[m]<=x){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return -1;
}
int main(){
   int arr[]={2,3,4,5,6,9,10,20,30,40};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x;
      printf("Enter the element to search:");
      scanf("%d",&x);
   int result=binarySearch(arr,0,n-1,x);
   if(result !=-1){
      printf("Element find at index %d",result);
   }else{
       printf("Element not found");
   }return 0;
}
