#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//插入排序
void insertsort(int *arr,int len){
    for(int i=0;i<len-1;i++){
        int end = i;
        int tmp = arr[end+1];
        while(end>=0){
            if(arr[end]>tmp){
                arr[end+1] = arr[end];
                --end;
            }
            else{
                break;
            }
        }
        arr[end+1] = tmp;
    }
}

//希尔排序
//先进行预排序，让数组接近于有序，再进行直接插入排序
//多组间隔为整数gap的预排序
void shellsort(int* a,int len)
{
    int gap = len;
    while(gap>1)
    {
        gap=gap/2;//--1

        for(int i=0;i<len-gap;i++){//--2
            int end = i; 
            int tmp = a[end+gap];
            while(end>=0)//--3
            {
                if(a[end]>tmp){
                    a[end+gap] = a[end];
                    end-=gap;
                }
                else{
                    break;
                }
            }
            a[end+gap] = tmp;
        }
    }
}

//快速排序--挖坑法
void quicksort(int*a,int left,int right)
{
    if(left>=right){
        return;
    }
    int begin = left,end = right;
    int pivot = begin;
    int key = a[begin];
    while(begin<end)
    {
        while(begin<end && a[end]>=key){
            end--;
        }
        a[pivot] = a[end];
        pivot = end;

        while(begin<end && a[begin]<=key){
            begin++;
        }
        a[pivot] = a[begin];
        pivot = begin;
    }
    pivot = begin;
    a[pivot] = key;

    quicksort(a,left,pivot-1);
    quicksort(a,pivot+1,right);
}

//归并排序


int main(){
    int arr[5] = {5,4,3,2,1};
    quicksort(arr,0,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
