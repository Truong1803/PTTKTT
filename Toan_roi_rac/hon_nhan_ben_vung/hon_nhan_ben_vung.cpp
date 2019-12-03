#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main() 
{
	int n, x;
	cin >> n;
	int nam_nu[n + 1], nu_nam[n + 1];
	queue<int> nam[n + 1];
	map<int,int> nu[n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			nam[i].push(x);
			nam_nu[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			nu[i][x] = j;
			nu_nam[i] = 0;
		}
	}
	int check = 1;
	while (check!=0) {
		for (int i = 1; i <= n; i++)
			if (nam_nu[i] == 0) {
				x = nam[i].front();
				nam[i].pop();
				if (nu_nam[x] == 0 || nu[x][i] < nu[x][nu_nam[x]]) {
					nam_nu[nu_nam[x]] = 0;
					nu_nam[x] = i;
					nam_nu[i] = x;
				}
			}
		check = 0;
		for (int i = 1; i <= n; i++)
			if (nam_nu[i] == 0) {
				check = 1;
				break;
			}
	}
	for (int i = 1; i <= n; i++)
		cout<<i<<" "<<nam_nu[i]<<endl;
	return 0;
}