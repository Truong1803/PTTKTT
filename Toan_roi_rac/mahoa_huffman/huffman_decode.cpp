#include <bits/stdc++.h>
using namespace std;
map<string,char> m;
string kq="";
string convert(char c){
	int c1=c;
	if(c1<0)
		c1=256+c1;
	int n;
	string str="";
	while (c1!=0)
    {
        n=c1%2;
        if (n==1)
            str="1"+str;
        else
            str="0"+str;
        c1=c1/2;
    }
    int j=str.size();
    for(int i=0;i<8-j;i++){
    	str='0'+str;
    }
    return str;
}
int main(int argc,char const* argv[])
{
    ifstream encode (argv[1]);
    ofstream decode (argv[2]);
    int n,q;
    encode>>n>>q;
    encode.ignore();
    for(int i=0;i<n;i++){
        string t;
        getline(encode,t);  
        //cout<<t<<endl;
        m[t.substr(2,t.size()-2)]=t[0];
    }
    int q1=0;
    while(!encode.eof()){
        vector<char> kq1;
        string str1="";
        getline(encode,str1);
        int x=str1[str1.size()-1]-'0'; 
        string s="";  
        for(int i=0;i<str1.size()-x-2;i++){
            if(str1[i]=='$'&&str1[i+1]=='.'&&str1[i+2]=='$'&&str1[i+3]=='&'){
                s.append("00001010");     
                i=i+3;      
            }
            else{         
                s.append(convert(str1[i]));
            }
        }       
        s.append(str1.substr(str1.size()-x-2,x));
        for(int i=0;i<s.size();i++){
            kq=kq+s[i];
            for(auto it=m.begin();it!=m.end();++it){
                if(kq==it->first){
                    kq1.push_back(it->second);
                    kq="";
                }
            }
        }
        for(int i=0;i<kq1.size();i++){
            decode<<kq1[i];
        }
        if(q1!=q-1){
            q1++;
            decode<<endl;
        }
    }
    decode.close();
    encode.close();
}
