#include<iostream>
#include<vector>
#include<string>
using namespace std;

int houserob(vector<int> v,int i){
    if(i>=v.size()){
        // cout<<ans;
        return 0;
    }
    
    //  chori kar le 
    int opt1=v[i]+houserob(v,i+2);
    // chori mat kar 
    int opt2=0+houserob(v,i+1);
    
    return max(opt1,opt2);
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);
    v.push_back(10);
    int ans=houserob(v,0);
    cout<<ans;
}