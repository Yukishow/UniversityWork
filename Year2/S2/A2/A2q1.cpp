/*
Problem A2q1
Design and implement the improved and D&C version of the maximum subarray sum algorithm.
*/
#include <bits/stdc++.h>
using namespace std;

//Solution
int Sumofarray(vector<int> &arr){
    int sum = 0;
    for (auto num : arr)
        sum += num;
    return sum;
}

vector<int> MidArraySum(vector<int> &arr,int front,int mid,int end){
    int resultleft = mid,resultright = mid;
    int tmp = 0,max = INT_MIN;
    for (int i=mid;i>=front;i--){
        tmp += arr[i];
        if (tmp > max){
            max = tmp;
            resultleft = i;
        } 
    }
    tmp = 0;max = INT_MIN;
    for (int i=mid+1;i<=end;i++){
        tmp += arr[i];
        if (tmp > max){
            max = tmp;
            resultright = i;
        } 
    }
    vector<int> result;
    for (int i=resultleft;i<=resultright;i++)
        result.push_back(arr[i]);
    return result;
}

vector<int> Maxsubarray(vector<int> &arr,int front,int end){
    if (front < end){
        int mid = front + (end - front)/2;
        vector<int> left = Maxsubarray(arr,front,mid);
        vector<int> right = Maxsubarray(arr,mid + 1,end);
        vector<int> middle =  MidArraySum(arr,front,mid,end);
        if (Sumofarray(left) > Sumofarray(middle) && Sumofarray(left) > Sumofarray(right))
            return left;
        else if (Sumofarray(middle) > Sumofarray(left) && Sumofarray(middle) > Sumofarray(right))
            return middle;
        else    
            return right;
    }
    return {arr[front]};
}
//check result
int main(){
    vector<int> arr = {5,4,-1,7,8};
    vector<int> check = Maxsubarray(arr,0,arr.size() - 1);
    for (auto num : check)
        cout << num << " ";
    cout << endl;

    return 0;
}