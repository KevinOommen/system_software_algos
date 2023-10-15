#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEFT 0
#define RIGHT 1
#define SIZE 8
int DISK_SIZE=200;
int track[SIZE]= { 176, 79, 34, 60, 92, 11, 41, 114 };
int left_arr[SIZE],right_arr[SIZE];
int seek_arr[SIZE];
int seek_count=0;
int head;
int s=0;
void sort(int *arr,int n){
    int i,j;
    int temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if(*(arr+j)>*(arr+j+1)){
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
        
    }
    
}
void scan(int initial_dir){
    int l=0,r=0;
    int run=2;
    int curr_track,distance;
    int direction=initial_dir;
    if(initial_dir==LEFT){
        left_arr[0]=0;
        l=1;
    }
        
    else if(initial_dir==RIGHT){
        right_arr[0]=DISK_SIZE-1;
        r=1;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if(track[i]<head){
            left_arr[l++]=track[i];
        }
        else if (track[i]>head)
        {
            right_arr[r++]=track[i];
        }
        
    }
    sort(left_arr,l);
    sort(right_arr,r);
    //print left_arr
    printf("Left array:-");
    for (int i = 0; i < l; i++)
    {
        printf("%d-->",left_arr[i]);
    }
    //print right_arr
    printf("\nRight array:-");
    for (int i = 0; i < r; i++)
    {
        printf("%d-->",right_arr[i]);
    }
    
    while (run-->0)
    {
        if (direction==LEFT)
        {   
            for (int i = l-1; i >=0; i--)
            {
                curr_track=left_arr[i];
                seek_arr[s++]=curr_track;
                distance=abs(head-curr_track);
                seek_count+=distance;
                head=curr_track;
            }
            direction=RIGHT;      
        }
        else if(direction==RIGHT){
            for (int i = 0; i < r; i++)
            {   
                curr_track=right_arr[i];
                seek_arr[s++]=curr_track;
                distance=abs(head-curr_track);
                seek_count+=distance;
                head=curr_track;
            }
            direction=LEFT;
        }
    }
    

}
void main(){
    int initial_direction = LEFT;
    head=50;
    scan(initial_direction);
    printf("Seek count:%d",seek_count);
    printf("/nSeek sequence:-");
    for (int i = 0; i < s; i++)
    {
        printf("%d-->",seek_arr[i]);
    }
    
}