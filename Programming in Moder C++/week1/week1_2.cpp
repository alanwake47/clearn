#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int i, int j){
    return i < j;
}

int main(){
    int arr[] = {4, 2, 6, 1, 7, 5};
    sort(&arr[0], &arr[0]+4, compare);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}