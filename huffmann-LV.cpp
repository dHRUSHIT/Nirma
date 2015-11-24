#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

typedef class symbol
{
	public:
	char a;
	float freq;
	class symbol *right;
	class symbol *left;
}symbol;
int read_input_file(char input_file_name[],symbol *sym)
{
	int k=0;
	cout<<"file open"<<input_file_name<<endl;
	ifstream input_file;
	input_file.open(input_file_name,ios :: in );
	char c;
	while (input_file >> c)
		sym[int(c)-97].freq+=1,k++;
	return k;
}
bool compare2(const symbol *a, const symbol *b)
{
	return a->freq>b->freq;
}
bool compare(const symbol x, const symbol y)
{
	return x.freq>y.freq;
}
void show_tree(symbol *z, string s)
{
	if(z==NULL)
		return;
	if(z->left==NULL && z->right==NULL)
	{
		cout << z->a <<' '<<s<<endl;
		return;
	}
	if((z)->left!=NULL)
		show_tree(z->left, s+"0");
	if((z)->right!=NULL)
		show_tree(z->right, s+"1");
}

int main(int argc, char ** argv)
{
	symbol huff[26];
	for(int i=0;i<26;i++){
		huff[i].a=char(i+97),huff[i].freq=0,huff[i].left=NULL,huff[i].right=NULL;
	}
	
	int l = read_input_file(argv[1],&huff[0]);
	sort(huff,huff+26,compare);
	for(int i=0;i<26;i++)
		huff[i].freq=(float)huff[i].freq/l;//,cout<<huff[i].a<<" "<<huff[i].freq<<" "<<endl;
	int e=0;
	while(huff[e].freq!=0)
		e++;
	int size=e;
	symbol *th[size];
	for(int i=0;i<size;i++)
		th[i]=&huff[i];
	while(size!=1)
	{
		symbol *s = new symbol;
		s->a='x';
		s->freq = th[size-2]->freq + th[size-1]->freq;
		s->left = th[size-2];
		s->right = th[size-1];
		size--;
		th[size-1] = s;
		th[size] = NULL;
		sort(th,th+size,compare2);
		symbol *temp;
		int f=0;
		while(th[f]!=s)
			f++;
		while(th[f]->freq==th[f-1]->freq)
		{
			symbol *tem = th[f];
			th[f] = th[f-1];
			th[f-1] = tem;
			f--;
		}
		
	}
	//cout<<l<<endl;
	show_tree(th[0],"");


	
}
