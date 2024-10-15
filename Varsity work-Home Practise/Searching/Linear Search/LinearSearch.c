#include<stdio.h>
int main(){
   int arr[]={2,3,4,5,6,8,9};
   int size= sizeof(arr)/sizeof(arr[0]);
   int x;
   printf("Enter the element to search:");
   scanf("%d",&x);
   for(int i=0; i<size;i++){
    if(arr[i]==x){
        printf("Found");
        return 0;
    }
    }
    printf("Not Found");
   }

