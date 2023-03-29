/*
Problem A1q1
Design an algorithm to find all palindromes of length >=2.
*/
#include <iostream>
using namespace std;

//Solution
bool IsPalindrome(string str){
    int n = str.size();
    for (int i=0;i<n/2;i++){
        if (str[i] != str[n - 1 - i])
            return 0;
    }
    return 1;
}

//To check whether my solution work correctly or not
int main(){
    string input;
    while (cin >> input && input != "0"){
        if (IsPalindrome(input))
            cout << input << " is an palindrome" << endl;
        else
            cout << input << " is not an palindrome" << endl;
    }

    return 0;
}