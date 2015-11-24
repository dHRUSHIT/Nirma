#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#define FOR(x,y) for(int x=0;x<y;x++)
using namespace std;

typedef struct node
{
	char a;
	node *l;
	node *r;
	string code;
	float freq;
}node;
int read_input_file(char input_file_name[],float *ft)
{
	int k=0;
	cout<<"file open"<<input_file_name<<endl;
	ifstream input_file;
	input_file.open(input_file_name,ios :: in );
	char c;
	while (input_file >> c)
		ft[int(c)-97]=ft[int(c)-97]+1,k++;
	return k;
}

bool compare(node a,node b)
{
	return a.freq>b.freq;
}

node * sf(node m[],int lo,int h,string s)
{
	if (lo+1==h)
	{
		node *ts;
		ts=new node;
		ts->l = &m[lo];
		ts->r = &m[h];
		string c;
		c.assign(s);
		c+="0";
		m[lo].code=c;
		c.assign(s);
		c+="1";
		m[h].code=c;
		cout<<m[lo].a<<" "<<m[lo].code<<endl;
		cout<<m[h].a<<" "<<m[h].code<<endl;
		return ts;
	}
	else if (lo==h)
	{
		m[lo].code = s;
		cout<<m[lo].a<<" "<<m[lo].code<<endl;
		return &m[lo];
	}
	else
	{
		int tl=lo,th=h;
		float cl=m[tl].freq;
		float ch=m[th].freq;
//		cout<<<<" "<<m[th].a<<endl;
		while(tl<th)
		{
			if(cl>ch)
			{
				th--;
				ch+=m[th].freq;
			}
			else
			{
				tl++;
				cl+=m[tl].freq;
			}
		}
		//cout<<tl<<" "<<th<<endl;
		node *ts = new node;
		ts->l = sf(m,lo,tl-1,s+"0");
		ts->r = sf(m,th,h,s+"1");
		return ts;
	}
}


int main(int argc,char ** argv)
{
	string s;
	cin>>s;
	node n[26]={'\0',NULL,NULL,"",0};
	FOR(i,26)
	{
		n[i].a=(char)(i+97);
		//cout<<n[i].a<<" "<<n[i].freq<<" "<<n[i].l<<" "<<n[i].r<<endl;
	}
	for(int i=0;i<s.length();i++)
	{
		char ctemp=s[i];
		int temp=(int)ctemp-97;
		n[temp].freq++;
	}
	
	sort(n,n+26,compare);
	int u=0;
	FOR(i,26)
	{
		n[i].freq/=s.length();
		if(n[i].freq!=0)
			cout<<n[i].a<<" "<<n[i].freq<<endl,u++;
	}
	
	node * t[u];
	FOR(i,u)
	{
		t[i]=&n[i];
	}
	node *root;
	root = sf(n,0,u-1,"");
	//sf(n,0,u,"");
}
