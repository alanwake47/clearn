#include<iostream>
#include<stack>
using namespace std;

int main(){
    int i;
    int arr[5] = {5,7,3,6,4};
    stack<int> s;

    for(i=0,i<5,i++){
        while(!s.empty()){
            if(s.top() < arr[i]){
                cout << s.top() << " ";
                break;
            }
            else
                s.pop();
        }
        if(s.empty())
            cout << -1 << " ";
        s.push(arr[i]);
    }
    return 0;
}