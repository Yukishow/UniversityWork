#include <bits/stdc++.h>
using namespace std;

void Sort(vector<int> &arr,int front,int end){
    if (front >= end) return;
    
    int p1 = front + (end - front)/3;
    int p2 = end - (end - front)/3;
    Sort(arr,front,p1);
    Sort(arr,p1 + 1,p2);
    Sort(arr,p2 + 1,end);

    vector<int> left,mid,right;
    for (int i = front;i <= p1;i++)
        left.push_back(arr[i]);
    for (int i = p1 + 1;i <= p2;i++)
        mid.push_back(arr[i]);
    for (int i = p2 + 1;i <= end;i++)
        right.push_back(arr[i]);

    //push large number for compare three numbers
    left.push_back(INT_MAX);
    mid.push_back(INT_MAX);
    right.push_back(INT_MAX);
    
    int indexleft = 0,indexmid = 0,indexright = 0;
    for (int i=front;i<=end;i++){
        if (left[indexleft] < mid[indexmid] && left[indexleft] < right[indexright]){
            arr[i] = left[indexleft];
            indexleft++;
        }
        else if(mid[indexmid] < left[indexleft] && mid[indexmid] < right[indexright]){
            arr[i] = mid[indexmid];
            indexmid++;
        }
        else{
            arr[i] = right[indexright];
            indexright++;
        }
    }
}

void print(vector<int> &arr){
    for (const auto k : arr)
        cout << k << " ";
    cout << endl;
}
//check result
int main(){
    vector<int> input = {12,11,13,5,6,7,14,45,87,123,654,
    84,22,66,4,8,2,9,10,17,23,31,29,53,87,97,500};
    Sort(input,0,input.size() - 1);
    print(input);

    return 0;
}