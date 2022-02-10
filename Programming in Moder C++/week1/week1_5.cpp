#include<iostream>
using namespace std;

//code to reverse all the strings present in the matrix and return it

int reverse(int str[10][], int r, int c){
    int i, j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << str[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            str[i][j] = str[i][c-j-1];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << str[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


int main() {
    int str[10][20];
    reverse(str, 10, 20);
    return 0;
}