#include<iostream>
#include<cstring>
#include<bitset>

using namespace std;

typedef struct node{
  char c;
  int w;
  node * l;
  node * r;
  node * p;
}node;

node * CreateNode(node * n,char tc)
{
  node * left, * right;
  left = new node;
  right = new node;

  left->c = '*';
  left->w = 0;
  left->l=NULL;
  left->r=NULL;
  left->p=n;

  right->c=tc;
  right->w=1;
  right->l=NULL;
  right->r=NULL;
  right->p=n;

  n->l=left;
  n->r=right;

  return n->l;
}

node * isThere(node * tr,char tc)
{
  node * ret=NULL;
  if(tr->c == tc)
    return tr;
  if(tr->r!=NULL)
    ret = isThere(tr->r,tc);
  if(ret==NULL)
    if(tr->l!=NULL)
      ret = isThere(tr->l,tc);
  return ret;
}
void UpdateTree(node * nd)
{
  while(nd!=NULL)
  {
    if(nd->r!=NULL && nd->l!=NULL)
    {
      nd->w = nd->l->w + nd->r->w;
      if(nd->r->w < nd->l->w)
        {
          node * e=nd->r;
          nd->r=nd->l;
          nd->l=e;
        }
    }
    nd = nd->p;
  }
}
void display_code(char tempc)
{
  int g=(int )tempc;
  g>117?cout<<bitset<4>(g-97-10)<<" ":cout<<bitset<5>(g-97)<<" ";
}

void display_path(node * tr,node * find,string path="")
{
  if(tr==NULL)
    return ;
  if(tr==find){
  	if(path=="")
  		cout<<"0 ";
  	else
    	cout<<path<<" ";
    return;
  }
  display_path(tr->r,find,path+"1");
  display_path(tr->l,find,path+"0");
}

void Adaptive(node * rt,char * str)
{
  node * curNYT=rt;
  int size=strlen(str);
  for(int i=0;i<size;i++)
  {
    char temc = str[i];
    node * temp = isThere(rt,temc);
    if(temp==NULL){
    	cout<<"(NYT)";
      display_path(rt,curNYT,"");
      curNYT = CreateNode(curNYT,temc);
      UpdateTree(curNYT);
      display_code(temc);
    }
    else{
      temp->w+=1;
      UpdateTree(temp);
      display_path(rt,temp,"");
    }
  }
}

int main()
{
  string s ;
  cin>>s;
  char * st = new char[s.length()];
  strcpy(st,s.c_str());

  node * root= new node;
  root->c='*';
  root->w=0;
  root->l=NULL;
  root->r=NULL;
  root->p=NULL;

  Adaptive(root,st);
}
