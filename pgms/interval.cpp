#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval
{
	int start,finish;
};

bool compare(Interval a, Interval b)
{
	return (a.start <= b.start);
}

int main()
{
	int n,count=1;
	cout<<"Enter the number of intervals: ";
	cin>>n;
	struct Interval I[n];
	for(int i=0;i<n;i++)
		cin>>I[i].start>>I[i].finish;
	sort(I,I+n,compare);
	struct Interval Current;
	vector < vector <Interval> > resource;
	for(int i=0;i<n;i++)
	{
		Current=I[i];
		bool val=true;
		for(int j=0;j<resource.size();j++)
		{
			if(Current.start>=resource[j].back().finish)
			{
				resource[j].push_back(Current);
				val=false;
				break;
			}
		}
		if(val==true)
		{
			vector < Interval > another;
			another.push_back(Current);
			resource.push_back(another);
		}
	}
	cout<<"Minimum number of resources: "<<resource.size()<<"\n";
	for(int i=0;i<resource.size();i++)
	{
		cout<<"Resource "<<i+1<<" jobs: ";
		for(int j=0;j<resource[i].size();j++)
			cout<<"["<<resource[i][j].start<<","<<resource[i][j].finish<<"] ";
		cout<<"\n";		
	}
	return 0;
}