#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
using namespace std;
int w[8];
int cyclef=0;
	/*
     3
   -------
2 |       | 4
  |	1	 |
  ---------
7 |		 | 5
  |		 |
   --------
		6
*/
bool f_ZERO(int* input, int n)
{
	if(!(input[1]==0 && input[2]==1 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==1 && input[7]==1))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_ONE(int* input, int n)
{
	if(!(input[1]==0 && input[2]==0 && input[3]==0 && input[4]==1 && input[5]==1 && input[6]==0 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_TWO(int* input, int n)
{
	if(!(input[1]==1 && input[2]==0 && input[3]==1 && input[4]==1 && input[5]==0 && input[6]==1 && input[7]==1))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_THREE(int* input, int n)
{
	if(!(input[1]==1 && input[2]==0 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==1 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_FOUR(int* input, int n)
{
	if(!(input[1]==1 && input[2]==1 && input[3]==0 && input[4]==1 && input[5]==1 && input[6]==0 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_FIVE(int* input, int n)
{
	if(!(input[1]==1 && input[2]==1 && input[3]==1 && input[4]==0 && input[5]==1 && input[6]==1 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_SIX(int* input, int n)
{
	if(!(input[1]==1 && input[2]==0 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==1 && input[7]==1))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_SEVEN(int* input, int n)
{
	if(!(input[1]==0 && input[2]==0 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==0 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_EIGHT(int* input, int n)
{
	if(!(input[1]==1 && input[2]==1 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==1 && input[7]==1))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

bool f_NINE(int* input, int n)
{
	if(!(input[1]==1 && input[2]==1 && input[3]==1 && input[4]==1 && input[5]==1 && input[6]==1 && input[7]==0))
	{
		for(int i=0;i<=n;i++)
			input[i]=-input[i];
	}
}

void fill(int* arr, int i, int n)
{
	for(int j=1;j<=n;j++)
	{
		arr[j]=i%2;
		i=i/2;
	}
}

void print(int* arr, int n)
{
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

int* percep(int digit)
{
	cyclef=0;
	int n,max; 
	n=7;
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
	
	switch(digit)
	{
		case 0:
			for(int i=0;i<max;i++)
				f_ZERO(arr[i], n);
			break;
		
		case 1:
			for(int i=0;i<max;i++)
				f_ONE(arr[i], n);
			break;
			
		case 2:
			for(int i=0;i<max;i++)
				f_TWO(arr[i], n);
			break;
		
		case 3:
			for(int i=0;i<max;i++)
				f_THREE(arr[i], n);
			break;
		
		case 4:
			for(int i=0;i<max;i++)
				f_FOUR(arr[i], n);
			break;
		
		case 5:
			for(int i=0;i<max;i++)
				f_FIVE(arr[i], n);
			break;
			
		case 6:
			for(int i=0;i<max;i++)
				f_SIX(arr[i], n);
			break;
			
		case 7:
			for(int i=0;i<max;i++)
				f_SEVEN(arr[i], n);
			break;
			
		case 8:
			for(int i=0;i<max;i++)
				f_EIGHT(arr[i], n);
			break;
			
		case 9:
			for(int i=0;i<max;i++)
				f_NINE(arr[i], n);
			break;
	}
	
	
	
	
	for(int i=0;i<n+1;i++)
		w[i]=1; ////////// Can vary
	
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
				cyclef=1;
				cout<<"Cycle found"<<endl;
				break;
			}
			else
				hmap[wstr]=0;
		}
	}
	
	//cout << "Iteration = " << iteration << endl;
	 
	/*for(int i = 0; i < n+1; i++)
		cout<<w[i]<<" ";
	cout << endl;		*/
	return w;
}

int main()
{
	int wt[10][8];
	for(int i=0;i<10;i++)
	{
		if(cyclef==0)
		{
			int* a=percep(i);
			for(int j=0; j<8;j++)
				wt[i][j]=a[j];
		}
		else
		{
			cout<<"Cycle"<<endl;
		}
	}
	
	int x[8];
	x[0]=-1;

	
	for(int i=0;i<7;i++)
	{
		cout<<"Enter value for "<<i+1<<" : ";
		cin>>x[i+1];
	}
	int dot=0;
	cout<<"Digit Recognized: ";
	int found = 0;
	for(int i=0;i<10;i++)
	{
		dot=0;
		for(int j=0;j<8;j++)
			dot+=wt[i][j]*x[j];
		if(dot>0)
		{
			found = 1;
			cout<<i<<" "<<endl;
		}
	}
	if (found == 0)
		cout<<"None"<<endl;
	
}
