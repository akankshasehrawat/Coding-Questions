#include<iostream>

using namespace std ;

int main()
{int p,i,t;
char a ;
cout <<"choose 'a' for interest and 'b' for no interest"<<endl;
cin>>a;
if (a=='a')
   {
    cout<< "enter the principle amount"<<endl;
    cin>>p;
    cout <<"enter the interest rate "<<endl;
    cin>>i;
    cout<<"enter the time period "<<endl;
    cin>>t;
    int m =p+ p*i*t*0.01;
    cout<<"final amount using compound interest ="<<m;}
    else cout<<"thank you";
    return 0;

}
