#include<iostream>
using namespace std;
int main(){
    int i,k,j;
    int temp;
    int a[10] = {5,3,2,8,6,9,0,4,1,7};
    int d;
    for(d = 5;d>=1;d/=2){
        for(i = d;i<10;i++){
            if(a[i-d]>a[i]){
                temp = a[i];
                for(j = i-d;j>=0&&a[j]>temp;j-=d){
                    a[j+d] = a[j];
                }
                a[j+d] = temp;
            }
        }
    }
    for(k = 0;k<10;k++)
        cout<<a[k]<<" ";
return 0;
}
