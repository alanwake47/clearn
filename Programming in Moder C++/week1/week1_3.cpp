#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int i;
    vector<int> arr;
    for (i=1;i<=9;i++)
        arr.push_back(i);

    rotate(arr.begin(), arr.begin()+3, arr.begin()+5);

    for(int i=0;i<arr.size();i++)
        cout << arr[i] << " ";
    return 0;
}