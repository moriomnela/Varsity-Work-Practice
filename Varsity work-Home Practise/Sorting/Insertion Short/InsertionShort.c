#include<stdio.h>
void insertion_sort(int arr[],int size){
   for(int s=1; s<size; s++){
    int j = s-1;
    int key = arr[s];
   while(j>=0 && key<arr[j]){
    arr[j+1] = arr[j];
       j--;
   }
   arr[j+1] = key;
 }
}
int main(){
   int arr[]={10,20,3,6,8,2};
   int size = sizeof(arr)/sizeof(arr[0]);
   insertion_sort(arr,size);
   printf("Sorted array:\n");
   for(int i = 0; i<size; i++){
    printf("%d\n", arr[i]);
   }
   return 0;
}
