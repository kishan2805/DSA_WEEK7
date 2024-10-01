#include<iostream>
#include<limits.h>
#include<vector>
#include<string.h>
using namespace std ;

int arr[10];

// int no_ways=0;

int fact(int n){
    // base condition 
    if (n==1||n==0)
        return 1;
    
    // recurcive function
    int ans=n*fact(n-1);
    
    return ans;
}

void revcounting(int n){
    if (n==1){
        cout<<1<<"  ";
        return;
    }
    cout<<n<<"  ";   //this will print in revrese order   (tail recursion if 2nd count is removed)
    revcounting (n-1);
    // cout<<n<<" "; if we print after calling then it will print it in ascending order (head recursion if 1 count is removed )
        
}

int power(int n){
    if (n==0)
        return 1;
    int ans=2*power(n-1);
    return ans;
}

int fibonacci(int n ){
    if (n==1){
        // cout<<"0 ";
        arr[0]=0;
        return 0;
    }
    else if (n==2){
        // cout<<"1 ";
        arr[1]=1;
        return 1;
    }
    else {
        int ans=fibonacci(n-1)+fibonacci(n-2);
        // cout<<ans<<" ";
        arr[n-1]=ans;
        return ans ;
    }
}

int climbStairs(int n){
        if(n==0){
            // no_ways++;
            // return no_ways;
            return 1;
        }
        else if (n==1)
            // return no_ways;
            return 1;
        else {


            int ans=climbStairs(n-1)+climbStairs(n-2);
            return ans;
        }
}
int search(int arr[],int &size1,int key,int index){
    if(index>=size1 )
        return -1;
    else if (arr[index]==key)
        return index;
    else{
        int ans=search(arr,size1,key,index+1); //When you write int ans=search(arr,size1,key,index++);,
        // the value of index is passed to the search function, but the actual increment happens 
        //after the function call returns.
        // int ans = search(arr, size1, key, ++index); //can be used too but index++ cant be .

        return ans;
    }
}

/*if(index >= n) return mini;

   mini = min(mini, arr[index]);

   return minimum(arr, n, mini, index + 1);
   */
int minimum(int arr[],int &size1,int mini,int index){
    if(index>=size1 )
        return mini;
    if(mini > arr[index])
        mini=arr[index];
    return minimum(arr,size1,mini,index + 1);
}

void club(int a[],int size,int index, vector<int>& v){
    if(index>=size)
        return;
    if(a[index]%2==0){
        v.push_back(a[index]);
        
    }
    index=index+1;
    club(a,size,index,v);
}

void doub(int a[],int size,int index){
    if (index>=size)
        return ;
    else{
        a[index]=2*a[index];
        doub(a,size,++index);
    }
}

void search(int a[],int s, int tar,int i,int &key){
    if (i>=s){
        key=-1;
        return ;
    }
    if(a[i]==tar){
        key=i;
        return;
    }
    search(a,s,tar,++i,key);
}

void digits(int n,vector<int>&ans){
    if(n<=0)
        return;
    int rem =n%10;
    
    n=n/10;
    digits(n,ans);
    ans.push_back(rem);
    cout<<rem<<" ";
}
bool checkSorted(int arr[], int size, int index) {
	//base case
	if(index >= size) {
		return true;
	}

	//processing
	if(arr[index] > arr[index-1]) {
		//aage check krna padega ab
		//ab recursion sambhalega
		bool aageKaAns = checkSorted(arr, size, index+1);
		return aageKaAns;
	}
	else {
		//sorted nahi h 
		return false;
	}
}

int binary_search(int a[],int st,int end,int tar){
    if(st>end){
        
        return -1;
    }
    int mid=st+(end-st)/2;
    if(tar==a[mid]){
        return mid;
    }
    if(a[mid>tar])
        return binary_search(a,st,mid-1,tar);
    else
        return binary_search(a,mid+1,end,tar);
}

// subsequence of a string 
void subsequence(string str,string out,int i){
    if(i>=str.length()){
        cout<<"-> "<<out<<endl;
        return;
    }
    char c=str[i];
    // output is exclude from updation
    subsequence(str,out,i+1);
    // output is updated
    out.push_back(c);
    subsequence(str,out,i+1);

    /*
    here we can also do the include part first then exclude part but then we will need to popback the element
    added in the output then move to recurssion
    out.pop_back(c);
    subsequence(str,out,i+1);
    */

}

int solve(vector<int>& nums, int size, int index) {
    //base case
    if(index >= size ) {
        return 0;
    }

    //chori karlo -> ith index pr
    int option1 = nums[index] + solve(nums, size, index+2);

    //chori mat karo  -> ith index pr
    int option2 = 0 + solve(nums, size, index+1);

    int finalAns = max(option1, option2);
    return finalAns;
}
int rob(vector<int>& nums) {
    int size = nums.size();
    int index = 0;
    int ans = solve(nums, size, index);
    return ans;

    
}


int main (){

    // // find factorial using recursion 

    // int factorial=fact(6);
    // cout<<"factorial of 6 is "<<factorial<<endl;

    // // reversecounting 
    // revcounting(5);

    // // finding power of 2 
    // int ans=power(5);
    // cout<<ans<<endl;

    // printing fibonacci serie and last term 
    // int ans=fibonacci(5);
    // cout<<ans<<endl; 
    // for(int i=0;i<10;i++){
        // cout<<arr[i]<<"  ";
    // }

    // int ans=climbStairs(4);
    // cout<<ans;
    // // cout<<no_ways;

    // searching in an array
    // int arr[5]={1,2,3,4,5};
    // int ans=search(arr,5,4,0);
    // cout<<ans;
    
    // finding minimum in an array
    // int arr[5]={100,2,1,3,58};
    // int a = INT16_MAX;
    // int n = 5;
    // int ans=minimum(arr,n,a,0);
    // cout<<ans;

    // // clubing the even numbers 
    // int arr[5]={1,2,3,4,5};
    // int size=5,index=0;
    // vector<int> v;
    // club(arr,size,index,v);
    // for(int n: v){
    //     cout<<n<<"  ";
    // }

    // // doubling the values in the arrays
    // int a[5]={10,20,30,40,50};
    // doub(a,5,0);
    // for(int i =0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }

    // // searching an array
    // int a[5]={1,2,3,4,5};
    // int tar=8;
    // int key;
    // search(a,5,tar,0,key);
    // cout<<key;

    // // finding all the digits of a no.
    // int n=512437;
    // vector<int>v;
    // digits(n,v);
    // cout<<endl;
    // for( int i:v){
    //     cout<<i<<" ";
    // }

    // int arr[] = {};
	// int size = 0;
	// int index = 1;

	// bool isSorted = checkSorted(arr,size, index);

	// if(isSorted) {
	// 	cout << "Array is sorted" << endl;
	// }
	// else{
	// 	cout << "Array is not sorted" << endl;
	// }

    // // binary search
    // int arr[5]={1,2,3,4,5
    // };
    // int key=binary_search(arr,0,4,1);
    // cout<<key;

    // sub_sequence of string

    // string str="abc";
    // string output="";
    // int index=0;
    // subsequence(str,output,index);

    // // leetcode 198 house robber 
    // vector<int> nums{1,2,3,4,5,6,7,8,9};

    // int ans =rob(nums);
    // cout<<ans;

    

}