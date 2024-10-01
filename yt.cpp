#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

// int arr[6]={2,3,1,5,4,6};

// nprinting the factorial of a number 
void fact(int n,int ft=1){
    if(n<=0){
        cout<<ft;
        return;
    } 
    ft=ft*n;
    fact(n-1,ft);
} 

void insert(vector<int>&v,int temp){
    if (v.size()<=0||temp>=v[v.size()-1]){
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
}

// sorting an array 
void sorting(vector <int>&v){
    if(v.size()<=1 ){
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sorting(v);
    insert(v,temp);
}

void insert1(int a[],int temp,int top){
    if (top<0||temp>=a[top]){
        a[top]=(temp);
        return;
    }
    int val=a[top--];
    // a.pop_back();
    insert1(a,temp,top-1);

    a[top+1]=val;
}

// sorting the stack
void sorting1(int a[],int top){
    if(top<0){
        return;
    }
    int temp=a[top];
    top--;
    sorting1(a,top);

    insert1(a,temp,top);
    
}
// deleting middle elements from the stack
void del(stack<int> stk,int k){
    // base condition
    if (k==1){
        stk.pop();
        del(stk,(--k));
        return;
    }
    if (stk.empty())
        return;
    else{
        cout<<stk.top()<<" ";
        stk.pop();
        k--;
        del(stk,k);

    }
}
void insertstk(stack<int > &stack,int temp){
    if(stack.size()==0){
        stack.push(temp);
        return;
    }
    int t=stack.top();
    stack.pop();
    insertstk(stack,temp);
    stack.push(t);
    return ;

}

// reversing a stack 
void reversestk(stack<int> &stack){
    if(stack.empty()){
        // stack.push(i);
        return;
    }
    int i=stack.top();
    stack.pop();
    reversestk(stack);
    // stack.push(i);
    insertstk(stack,i);
    return;

}


void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;
 
// Extract top of the stack
    int x = s.top();
 
    // Pop the top element
    s.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';
 
    // Proceed to print
// remaining stack
    PrintStack(s);
 
    // Push the element back
    s.push(x);
}
int solve(int n,int k){
    // int mid = (2^(n-1))/2;
    int mid=pow(2,n-1)/2;
    
    // base condition 
    if (n==1 && k==1)
        return 0;
    // else 
    //     return 1;
 
    if(k<=mid){
        return solve(n-1,k);
    }
    else{
        return !(solve(n-1,k-mid));
    }
}
// tower of hanoi 
void hanoi(int n,int s,int h,int d ){
    // base condition 
    if (n<=1){
        cout<< "moving plate "<<n<< " from "<<s << " to "<<d<< endl;
        return;
    }
    // moving the top plates to helper rod so that bottom plate can be moved to destination
    hanoi(n-1,s,d,h);
    cout<<"moving plate "<<n<< " from "<<s << " to "<<d<< endl;
    // moving all the plates from helper rod to destination using source rod as helper function 
    hanoi(n-1,h,s,d);
    return ;
    
}

void unique_sub(vector<string >&s,string out){
    int flag =1;
    for(int i =0;i<s.size();i++){

        if (s[i]==out){
            flag=0;
            break;
        }
        if(flag){
            s.push_back(out);
        }
    }
}
void printing1(string s,int i,string out,vector<string >&new1){
    // base condition
    if(i>=s.length()){
        // cout<<out<<endl ;
        unique_sub(new1,out);
        return;
    }
    // excluding the character 
    printing1(s,++i,out,new1);
    out.push_back(s[--i]);
    // including the character in output 
    printing1(s,++i,out,new1);
    return ;

}



// printing all subset of a string 
void printing(string s,int i,string out){
    // base condition
    if(i>=s.length()){
        cout<<out<<endl ;
        return;
    }
    // excluding the character 
    printing(s,++i,out);
    out.push_back(s[--i]);
    // including the character in output 
    printing(s,++i,out);
    return ;

}

// permutation with spaces
void perm1(string str,string out ,int i){
    // base case 
    if(i>=str.length()){
        cout<<out<<endl;
        return;
    }
    //  space excluded 
    out.push_back(str[i]);
    perm1(str,out,++i);
    if (i<str.length()){
        out.push_back('@');
        perm1(str,out,i);
    }
    return;
}
// permutation with capitals
void perm2(string str,string out , int i ){
    // base condi
    if (i>=str.length()){
        cout<<out<<endl;
        return ;
    }
    // excluding capital
    out.push_back(str[i]);
    perm2(str,out,++i);
    out.pop_back();
    char c =str[--i]+'A'-'a';
    out.push_back(c);
    perm2(str,out,++i);

    return ;

}
// generate balanced paranthesis
void generate (vector <string> &v,int m , int n,string str){
    if(m==0 && n==0){
        v.push_back(str);
        return;
    }
    if(m!=0){
        str.push_back('(');
        generate(v,--m,n,str);
    }
    if(n>m){
        str.push_back(')');
        generate(v,m,--n,str);
        return;
    }  

}
void generate1(vector <string> &v,int m,int n, string out,int len){
    if(len==0){
        cout<<out<<" ";
        v.push_back(out);
        return;
    }
    // out.push_back('1');
    // generate1(v,++m,n,out,--len);
    if(n<m){
        out.push_back('0');
        generate1(v,m,++n,out,--len);
    }
    else{
        out.push_back('1');
        generate1(v,++m,n,out,--len);
    }
    // return ;
}

void printvector(vector<string >v){
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void josephus(vector<int> &v, int k,int i){
    // base condition
    if(v.size()==1){
        cout<<v[0]<<endl;
        return ;
    }
    int kill=(i+k)%v.size();
    v.erase(v.begin()+kill);
    i=kill;
    josephus(v,k,i);
    // return ;


}



int main(){

    // // factorial of a number 
    // fact(5);

    // // sorting an array
    // vector<int> v;
    // v.push_back(5);
    // v.push_back(4);
    // v.push_back(1);
    // v.push_back(40);
    // v.push_back(5);
    // v.push_back(2);
    // sorting(v);
    // for(int i =0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    // // sorting the stack 
    // int arr[6]={1,3,2,6,4,5}; 
    // sorting1(arr,5);
    // for(int i =0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }

    // stack <int> stack;
    // stack.push(1);
    // stack.push(2);
    // stack.push(3);
    // stack.push(4);
    // stack.push(5);
    // int k=stack.size()/2 +1;
    // del(stack,k);

    // reversestk(stack);
    // cout<<stack.size();

    // PrintStack(stack);

    // int ans =solve (4,7);
    // cout<<ans;

    // tower of hanoi 
    // int  n=3;
    // int s=1;
    // int h=2;
    // int d=3;
    // hanoi(n,s,h,d);


    // printing all subset of a string 
    // string s ="abc";
    // string out="";
    // printing(s,0,out);

    // string str="aab";
    // string out ="";
    // vector <string>new;
    // printing1(str,0,out,new);

    // permutation with spaces 
    // string s="ABCD";
    // string out="";
    // perm1(s,out,0);

    // permutation with capital
    // string s="abc";
    // string out="";
    // perm2(s,out,0);

    // generate all balanced parathesis
    // vector<string> v;
    // int n=3 ;
    // string out="" ;
    // generate(v,n,n,out);
    // printvector(v);
    // cout<< v.size();

    // n-digit binary no. having prefix where no. of 0 always less than equal to 1 .
    // vector<string >v;
    // int len=4,m=0,n=0;
    // string out="";
    // generate1(v,m,n,out,len);
    // printvector(v);
    // cout<<v.size();

    // joseph's circle of death problem 
    vector<int> v;
    int n=40;
    int k=7;
    for (int i =0;i<n;i++){
        v.push_back(i+1);
    }
    int index=0;
    josephus(v,k-1,index);  // k-1 because we are going to start counting from current index only 

    



}