#include <iostream>
using namespace std;
int n;
int A[100];
int F[100];
int main()
{
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>A[i];
	}
	F[0] = 1;
	int Fmax;
	for (int i=1; i<n; i++)
	{
		Fmax = 0;
		for (int j = 0; j<i; j++)
		{
			if (A[i] > A[j])
				Fmax=max(F[j],Fmax);	
		}
		F[i] = Fmax + 1;
	}
	int Max = 0;
	int dem = 0;
	for (int i=0; i<=n; i++)
	{
		if (F[i] > Max)
		{
			if (A[i] < A[i+1])
			{
				cout<<A[i]<<" ";
				dem = i;
			}
		}
	}
	cout<<A[dem+1]<<endl;
	/*for(int i=0;i<n;i++)
		cout<<F[i]<<" ";
	cout<<endl;*/
	return 0;
	
}