#include <bits/stdc++.h>
using namespace std;

//Solution
int Search(vector<int> &arr,int target,int front,int end){
   if (front < end){
        int p1 = front + (end - front)/3,p2 = end - (end - front)/3;
        
        if (arr[p1] == target)      
            return p1;
        else if (arr[p2] == target)     
            return p2;
        //target in right subarray
        else if (arr[p1] > target)            
            return Search(arr,target,front,p1 - 1);
        //target in left subarray
        else if (arr[p2] < target)
            return Search(arr,target,p2 + 1,end);
        //target in middle subarray
        else
            return Search(arr,target,p1 + 1,p2 - 1);
    }

    return -1;
}

//check result
int main(){
    vector<int> arr = {1,2,3,6,7,9,11,15,45,47,
    48,49,50,51,56,58,61,69,70,75,80,88,90,100};
    int n = arr.size() - 1;
    cout << Search(arr,81,0,n) << endl;
    cout << Search(arr,1,0,n) << endl;
    cout << Search(arr,15,0,n) << endl;
    cout << Search(arr,45,0,n) << endl;
    cout << Search(arr,48,0,n) << endl;
    cout << Search(arr,50,0,n) << endl;
    cout << Search(arr,58,0,n) << endl;
    cout << Search(arr,75,0,n) << endl;
    cout << Search(arr,100,0,n) << endl;

    return 0;
}