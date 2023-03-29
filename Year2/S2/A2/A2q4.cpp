#include <bits/stdc++.h>
using namespace std;

//Solution
int Maxinarray(vector<int> &arr,int front,int end){
    if (front < end){
        int mid = front + (end - front)/2;
        int left = Maxinarray(arr,front,mid);       //leftsubarray max
        int right = Maxinarray(arr,mid + 1,end);    //rightsubarray max
        return left > right ? left : right;         //return max of them
    }
    //if it can't divde,return array value
    return arr[front];
}

//check result
int main(){
    vector<int> arr = {1,2,3,6,7,9,11,15,45,47,
    48,49,50,51,56,150,61,156,70,75,80,88,90,100};
    cout << Maxinarray(arr,0,arr.size() - 1) << endl;
    return 0;
}