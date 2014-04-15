#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
using namespace std;

bool f_OR(int* input, int n)
{
	//or function
	int res=0;
	for(int i=1;i<=n;i++)
		res=(res || input[i]);
	if(res==0)
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool xor2(int a,int b)
{
	if(a==b)
		return false;
	else
		return true;
}

bool f_XOR(int* input, int n)
{
	
	//res=(input[1]==input[2])?0:1;
	bool res = xor2(input[1],input[2]);
	for(int i=3; i<= n; i++)
		res = xor2(res, input[i]);
	if(res==false)
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_NAND(int* input, int n)
{
    //nand function
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res= (res && input[i]);
        res = (0 == res) ? 1 : 0;
    }
    if(res==0)
    {
        for(int i=0;i<=n;i++)
            input[i]=-input[i];
    }
}

bool f_NOR(int* input, int n)
{
    //nor function
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res= (res || input[i]);
        res = (0 == res) ? 1 : 0;
    }
    if(res==0)
    {
        for(int i=0;i<=n;i++)
            input[i]=-input[i];
    }
}

bool IsPalindrome(int* palindrome,int n){
   
    int beg=1;
    int last=n-1;

    bool result=false;

    while(beg<last){
        if(palindrome[beg]!=palindrome[last]){
            //cout<<"here"<<endl;
            break;
        }
        else{
            beg++;
            last--;
        }

    }
    if(beg>=last)
        result=true;

    if (!result){
		for(int i=0;i<=n;i++)
			palindrome[i]=-palindrome[i];
	}
}

void IsMajority(int* arr,int n){

    bool result=false;
    int i=1;
    int count=0;
    while(i<n){

        if(arr[i]==1){
            count++;
        }
        i++;
    }

    if((n%2 == 1 && count>=n/2 + 1) || (n%2 == 0 && count>n/2 + 1))
        result=true;
    if (!result){
		for(int i=0;i<=n;i++)
			arr[i]=-arr[i];
	}

}

void IsParity(int* arr,int n){
    bool result=false;
    int i=1;
    int count=0;
    while(i<n){

        if(arr[i]==1){
            count++;
        }
        i++;
    }

    if(count%2==0)
        result=true;
    if (!result){
		for(int i=0;i<=n;i++)
			arr[i]=-arr[i];
	}


}

void fill(int* arr, int i, int n)
{
	//convert i to decimal and fill in arr
	for(int j=1;j<=n;j++)
	{
		arr[j]=i%2;
		i=i/2;
	}
}

void print(int* arr, int n)
{
	/*cout<<arr[1]<<endl;
	cout<<arr[2]<<endl;*/
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl;
}

int dot(int* a,int* b,int n)
{
	int res=0;
	for(int i=0;i<n;i++){
		res=res+a[i]*b[i];
	}
	return res;
}

void add(int* a,int* b,int n, int C)
{
	for(int i=0;i<n;i++)
	{
		a[i]+=C*b[i];
	}
}

string tostring(int* w,int n)
{
	string a="";
	for(int i=0;i<n;i++)
	{
		
		ostringstream oss;
		oss << w[i];
		a=a+";"+oss.str();
	}
	return a;
}

int main()
{
	int n,max;
	cout<<"Enter no of inputs: ";
	cin>>n;
	max=pow(2,n);
	int arr[max][n+1];
	int C = 1; //////////// Can vary
	map <string, bool> hmap;
	map <string, bool>::iterator it;
	string wstr;
	for(int i=0;i<max;i++)
	{
		arr[i][0]=-1;
		fill(arr[i],i,n);
	}
	
	for(int i=0;i<max;i++)
	{
		IsMajority(arr[i], n); // Give the required function
	}
	
	int w[n+1];
	for(int t=0; t<100;t++)
	{
		cout<<t<<",";
		for(int i=0;i<n+1;i++)
			w[i]=t; // Weights initialized as 0 for all w
		
		int iteration = 0;
		
		for(int i = 0; i < max; i++)
		{
			if (dot(w,arr[i],n+1)<=0)
			{
				
				add(w, arr[i],n+1, C);
				iteration++;
				i=-1;
				wstr=tostring(w,n+1);
				
				it=hmap.find(wstr);
				if(it!=hmap.end())
				{
					//cout<<"Cycle found"<<endl;
					break;
				}
				else
					hmap[wstr]=0;
			}
		}
		
		cout<<iteration<<endl;
		//cout<<hmap.size()<<endl;
		//cout<<hmap.max_size()<<endl;
		hmap.clear();
	}		
	
	return 0;
}
