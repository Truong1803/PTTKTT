#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> f;
priority_queue <ii> pq;
map<char,int> m;
vector<int> luu;
vector<char> ki_tu;
map<char,string> kq;
string s;
int dem=0;
int check_line=0;
int convert(string str);
void huffman();
int main(int argc,char const *argv[])
{
	ifstream vanban (argv[1]);
    while(!vanban.eof()){
    	getline(vanban,s);
    	for(int i=0;i<s.size();i++){
			m[s[i]]++;
		}
		dem++;
    }
    vanban.close();
    //////////
	for(int i=0;i<s.size();i++){
		m[s[i]]++;
	}
	if(m.size()==1){
		kq[s[0]]='0';
	}
	else{
		f.resize(2*m.size()-1);
		luu.resize(2*m.size()-1,-1);
		int i=0;
		for(auto it=m.begin();it!=m.end();++it){
			f[i]=it->second;
			pq.push(make_pair(-1*it->second,i));
			i++;
			ki_tu.push_back(it->first);
		}
		huffman();
		for(int i=0;i<m.size();i++){
			string t="";
			if(luu[i]<0)
				t='0'+t;
			else
				t='1'+t;
			int j=abs(luu[i]);
			while(j!=(luu.size()-1)){
				if(luu[j]<0)
					t='0'+t;
				else
					t='1'+t;
				j=abs(luu[j]);
			}
			kq[ki_tu[i]]=t;
		}
	}
	ofstream encode (argv[2]);
    encode<<kq.size()<<" "<<dem<<endl;
    for(auto it=kq.begin();it!=kq.end();++it){
   		encode<<it->first<<" "<<it->second<<endl;
 	}
   	ifstream vanban1 (argv[1]);
   	int j=0;
   	while(!vanban1.eof()){
   		getline(vanban1,s);
   		string kq1="";
   		for(int i=0;i<s.size();i++){
   			kq1.append(kq[s[i]]);
   		}
   		int count=kq1.size()/8;
   		for(int i=0;i<count*8;i=i+8){
   			int thap_phan=convert(kq1.substr(i,8));
   			if(thap_phan==10){
   				encode<<"$.$&";
   			}
   			else
   				encode<<char(thap_phan);
   		}
   		encode<<kq1.substr(count*8,kq1.size()-count*8)<<" "<<kq1.size()-count*8;
   		if(j!=dem-1){
   			j++;
   			encode<<endl;
   		}
   	}
   	vanban1.close();
    encode.close();
}
int convert(string str)
{	
	int kq2=0;
	for(int i=0;i<8;i++){
		kq2=kq2+(str[i]-'0')*pow(2,8-i-1);
	}
	return kq2;
}
void huffman(){
	int i=0,j=0,x,y;
	for(int k=m.size();k<2*m.size()-1;k++){
		i=abs(pq.top().first);
		x=pq.top().second;
		pq.pop();
		j=abs(pq.top().first);
		y=pq.top().second;
		pq.pop();
		f[k]=i+j;
		luu[x]=k;
		luu[y]=-k;
		pq.push(make_pair(-1*(i+j),k));
	}
}
