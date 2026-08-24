#include <iostream>
using namespace std;
int main(){
    int cp;
    cout<<"Enter a cp: ";
    cin>>cp;
    int sp;
    cout<<"Enter a s5p: ";
    cin>>sp;
    if(sp>cp){
      cout <<"Profit";
    }
     if(sp<cp){
      cout <<"Loss";
    }
    if(sp==cp){
      cout <<"No Profit No Loss";
    }
}