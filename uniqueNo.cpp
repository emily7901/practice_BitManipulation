#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int unique(int arr[], int n)
{
    int xorsum=0;
    for(int i=0; i<n; i++)
    {
        xorsum= xorsum^arr[i];
    }
    return xorsum;
}



int setBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}

void unique2NO(int arr[], int n)
{
    int xorsum=0;
    for(int i=0; i<n; i++)
    {
        xorsum= xorsum^arr[i];
    }
    int tempxor= xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >>1;
    }
    int newxor=0;
    for(int i=0; i<n; i++)
    {
        if(setBit(arr[i],pos-1))
        {
            newxor = newxor^arr[i];
        }
    }
    cout<< newxor << endl;
    int xor2= tempxor^newxor;
    cout<< xor2 << endl;
}



bool getBit(int n, int pos)
{
    return ((n & (1<<pos))!=0);
}

int SetBit(int n, int pos)
{
    return (n |( 1<<pos));
}

int unique3NO(int arr[], int n)
{   
    int result=0;
    for(int i=0; i<64; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            if(getBit(arr[j],i))
            {
                sum++;
            }
        }
        if (sum%3!=0)
        {
            result = SetBit(result, i);
        }
    }
    return result;
}

int main(){

   // int arr[]= {1,2,5,7,5,1,2};
   // cout<< unique(arr,7) <<endl;

   // int arr[]= {1,2,4,5,5,4,2,1,6,8};
   // unique2NO(arr,10);

   int arr[]={ 1,2,3,4,1,2,3,1,2,3};
   cout<< unique3NO(arr,10)<<endl;
    return 0;
}