#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    int a[10] = {4,3,6,5,7,1,9,8,2,0};
    int temp = a[0];
    for(i = 1;i<10;i++){
        if(a[i] <a[i-1]){
            temp = a[i];
            for(j = i-1;j>=0&&a[j]>temp;j--){
                a[j+1] = a[j];
            }
            a[j+1] = temp;
        }
    }
    for(k = 0;k<10;k++){
        cout<<a[k]<<" ";
    }
return 0;
}
