#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define NUMBER 100
#define RANGE  100
int Q1(int a[],int low,int high)
{
	int m=a[low];
     while (low<high)
	 {
		 while (low<high&&a[high]>=m)
			     --high;
          a[low] =a[high] ;
		 while (low<high&&a[low]<=m)
			     ++low;
          a[high] =a[low] ;
	 }
	 a[low] =m;
	 return low;
}
void Q2(int a[],int low,int high)
{
	int p;
	if(low<high)
	{
		p=Q1(a,low,high);    //½«µÚÒ»´ÎÅÅÐòµÄ½á¹û×÷ÎªÊàÖá
        Q2(a,low,p-1); //µÝ¹éµ÷ÓÃÅÅÐò ÓÉlow µ½prvotloc-1
        Q2(a,p+1,high); //µÝ¹éµ÷ÓÃÅÅÐò ÓÉ prvotloc+1µ½ high
	}
}
void quicksort(int a[],int n)
{
	Q2(a,1,n); //µÚÒ»¸ö×÷ÎªÊàÖá £¬´ÓµÚÒ»¸öÅÅµ½µÚn¸ö
}
int main()
{
     ifstream filein;
     int i;
     int a[NUMBER+1];
     filein.open("random_number.txt");//¶ÁÎÄ¼þ
     if(!filein){
     	cerr<<"Can not open file 'random_number'";
     	return -1;
     }
     for(i=1;i<=NUMBER;i++)
     {
        filein>>a[i];//½«ÎÄ¼þÐ´ÈëÊý×é
     }
     filein.close();
     for(i=1;i<=NUMBER;i++)
     {
         cout<<a[i]<<"\t";
     }
     quicksort(a,NUMBER);
     cout<<"``````````````````````````````````````````````````````````````````````````````"<<endl;
     for(i=1;i<=NUMBER;i++){
         cout<<a[i]<<"\t";
     }
}
