#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Bucket sort: Partition the array into a finite number of buckets,and then sort each bucket individually. 
//Time complexity O(n+m) where n = number of items, m= number or distinct items

void bucketsort(float arr[], int n)
{
	//create n buckets
	vector <float> b[n];
	
	//put arr elements in separate buckets
	for(int i=0;i<n;i++)
	{
		int ind = n*arr[i];
		b[ind].push_back(arr[i]);
	}
	
	//print all elements
	for (int i =0; i<n; i++)
	{
		cout<<"\n Elements in bucket "<<i;		
		for(int k=0;k<b[i].size();k++)
			cout<<"\t"<<b[i][k];
		
	}
 
	//sort individual brackets
	for(int i=0;i<n;i++)
	{
		sort(b[i].begin(),b[i].end()); 	
	}

	//concatenate all buckets back into arr
	int index=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			arr[index++]=b[i][j];
		}
	}
}

int main()
{
	float a[7]={0.3,0.5,0.2,0.6,0.1,0.7,0.4};
	
	cout<<"\n original array \n";
	for(int i=0;i<7;i++)
		cout<<" "<<a[i]<<"\t";
	
	bucketsort(a,7);

	cout<<"\n bucket sorted array \n";
	for(int i=0;i<7;i++)
		cout<<" "<<a[i]<<"\t";
	
	return 0;
}
