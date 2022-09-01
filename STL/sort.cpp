#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length()>b.length();
}

int main(){
    int n;
    cin>>n;
    //consume any extra /n 
    cin.get();

    string s[100];

    //sort the string 
    for(int i = 0 ; i < n;i++){
        //to take string input
        getline(cin,s[i]);
    }
    sort(s,s+n);

    //custom sorting can be done too , sort by length 
    sort(s,s+n,compare);
    for(int i = 0 ;i<n;i++){
        cout<<s[i]<<endl;
    }

     
}