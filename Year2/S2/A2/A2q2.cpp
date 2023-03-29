/*
Problem A2q2
The Closest Pair of Points problem is to find the closest pair of points in a set of points in x-y plane.
Design and implement a D&C algorithm to solve the problem.

The Closest Pair of Points problem:
The closest pair is the minimum of the closest pairs within each half and the closest pair between the two halves.
To split the point set in two,we find the x-median of the points and use that as a pivot.
Finding the closest pair of points in each half is subproblem that is solved recursively
*/
/*
Refer to geeksforgeeks :
https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
video :
https://www.youtube.com/watch?v=0W_m46Q4qMc&t=1s&ab_channel=GeeksforGeeks
*/


#include <bits/stdc++.h>
#define INP 2147483647
using namespace std;

struct point{
    int x,y;
};

bool cmpx(point p1,point p2){
    return p1.x < p2.x;
}

bool cmpy(point p1,point p2){
    return p1.y < p2.y;
}

double dist(point p1,point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + 
    (p1.y - p2.y)*(p1.y - p2.y));
}
//judge middle closeset points distance
double closeststrip(vector<point> strip,int count,double mindist){
    sort(strip.begin(),strip.end(),cmpy);
    for (int i=0;i<count;i++){
        for (int j=i+1;j<count && ((strip[j].y - strip[i].y) < mindist);j++){
            if (dist(strip[i],strip[j]) < mindist)
                mindist = dist(strip[i],strip[j]);
        }
    }
    return mindist;
}

double closestdist(vector<point> &arr,int front,int end){
    if (end - front <= 1){
        //one point return a largeset distance
        if (end - front == 0) return INP;
        //return distance between two points
        return (dist(arr[front],arr[end]));
    }
    int mid = front + (end - front)/2;
    point midpoint = arr[mid];
    double left = closestdist(arr,front,mid);
    double right = closestdist(arr,mid + 1,end);
    double mindist = left < right ? left : right;
    vector<point> strip(end - front);
    int count = 0;
    for (int i=0;i<(end - front);i++){
        if (abs(arr[i].x - midpoint.x) < mindist){
            strip[count] = arr[i];
            count++;
        }
    }
    return mindist < closeststrip(strip,count,mindist) ? mindist : closeststrip(strip,count,mindist);
}
//check result
int main(){
    vector<point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sort(points.begin(),points.end(),cmpx);
    cout << closestdist(points,0,points.size() - 1) << endl;

    return 0;
}