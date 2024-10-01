#include<iostream>
#include<vector>
#include<string>

using namespace std;

void lastocc(string str,char target,int index){
    if(index<0){
        return;
    }
    if(target==str[index]){
        cout<<"char found at index : "<<index;
        return;
    }
    else{
        lastocc(str,target,--index);
    }

}

// reversing a string 
void rev(string str,int start,int end){
    if(start>=end){
        cout<<"reversed string is : "<<str;
        return;
    }
    char c=str[end];
    str[end]=str[start];
    str[start]=c;
    rev(str,++start,--end);
}


int convert(string n,int index,int ans){
    if(index>=n.length()){
        return ans;
    }
    // char c=n[index];
    int a=n[index]-'0';
    ans= ans * 10 + a;
    // cout<<ans<<"  ";
    ans=convert(n,++index,ans);
    return ans;

}
string addStrings(string num1, string num2) {
    int ans1=0,ans2=0;
    int n1=convert(num1,0,ans1);
    int n2=convert(num2,0,ans2);
    // cout<<n1<<endl<<n2<<endl;
    int sum=n1+n2;
    // string sr=string(sum);
    // cout<<'"sr"';
    cout<<sum;
    // string ans;
    // ans.push_back(sum);
    // string a="'" + sum ;
    string ans="";
    return ans ; 
}


void pallindrome(string str,int s,int e){
    if(s>=e){
        cout<<"pallindrome ";
        return;
    }
    if(str[s]!=str[e]){
        cout<<"not a pallindrome ";
        return ;
    }
    pallindrome(str,++s,--e);
}

void subarray(int a[],int i,int size, string ans){
    if(i>=size){
        cout<<ans<<endl;
        return;
    }
    // excluding 

    subarray(a,++i,size,ans);


    // including 
    ans.push_back('0'+a[--i]);
    subarray(a,++i,size,ans);
}

// remove all occurance of string 
string removeOccurrences(string s, string part) {
        // int n=part.length();
    while(s.find(part) != string::npos){
        s.erase(s.find(part),part.length());
    }
    return s;
        
}
// house robber problem
int houserob(vector<int> v,int i,int ans){
    if(i>=v.size()){
        // cout<<ans;
        return ans;
    }
    ans+=v[i];
    i=i+2;
    int opt1=houserob(v,i,ans);
    i--;
    int opt2=houserob(v,i,ans);
    
    return max(opt1,opt2);
}


int main(){

    // // 1.last occurance of a character in a string 
    // string a="kishankumar";
    // char target='a';
    // int n=a.length();
    // lastocc(a,target,n-1);

    // // 2.reversing  a string 
    // string str="kishan";
    // int start=0;
    // int end=str.length()-1;
    // rev(str,start,end);

    // // 3.adding to string
    // string n1="2";
    // string n2="98";
    // string ans ;
    // ans=addStrings(n1,n2);
    // cout<<ans;

    // 4.pallindrome check 
    // pallindrome("abca",0,3);

    // // 5.printing all subarray of a array
    // int a[3]={1,2,3};
    // string out="";
    // subarray(a,0,3,out);

    // 6.remove all occurance of a string 
    // string s="kishankumarmarjaiskumkkum";
    // string part ="kum";
    // string ans=removeOccurrences(s,part);
    // cout<<ans<<endl;

    // 7.buy&sell stock
    // 8.house robber problem
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);
    int ans=houserob(v,0,0);
    cout<<ans;




}