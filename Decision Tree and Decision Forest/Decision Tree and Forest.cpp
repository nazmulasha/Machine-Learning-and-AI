#include <bits/stdc++.h>

using namespace std;

struct node{
    string spliton;
    string label;
    bool isleaf;
    vector<string>childv;
    vector<node*>child;
};
vector<int> distinct(vector<vector<string> > &table,int c);
string scolumn(vector<vector<string> > &table);
vector<vector<string> > prunetable(vector<vector<string> > &atr,string &cname,string v);
node* makeTree(vector<vector<string> >&table,node* ptr,vector<vector<string> >&dataset)
{

    if(table.size()==1)
        return NULL;
    bool same=true;
    for(int i=1;i<table.size();i++)
    {
        if(table[1][table[0].size()-1]!=table[i][table[0].size()-1])
        {
            same=false;
            break;
        }
    }
    if(same)
    {
        ptr->isleaf=true;
        ptr->label=table[1][table[1].size()-1];
        return ptr;
    }
    else{
    string split=scolumn(table);
    ptr->spliton=split;
    int index=-1;
    for(int i=0;i<dataset.size();i++)
    {
        if(dataset[i][0]==split)
        {
            index=i;
            break;
        }
    }
    for(int i=1;i<dataset[index].size();i++)
    {
        node* tmp=(node*) new node;
        tmp->label=dataset[index][i];
        ptr->childv.push_back(dataset[index][i]);
        tmp->isleaf=false;
        tmp->spliton=split;
        vector<vector<string> >atable=prunetable(table,split,dataset[index][i]);
        ptr->child.push_back(makeTree(atable,tmp,dataset));
    }
    return ptr;
    }
    return ptr;
}

node* makeRTree(vector<vector<string> >&table,node* ptr,vector<vector<string> >&dataset)
{

    if(table.size()==1)
        return NULL;
    bool same=true;
    for(int i=1;i<table.size();i++)
    {
        if(table[1][table[0].size()-1]!=table[i][table[0].size()-1])
        {
            same=false;
            break;
        }
    }
    if(same)
    {
        ptr->isleaf=true;
        ptr->label=table[1][table[1].size()-1];
        return ptr;
    }
    else
    {
        int index=rand()%16;
        for(int i=1;i<dataset[index].size();i++)
        {
            node* tmp=(node*) new node;
            tmp->label=dataset[index][i];
            ptr->childv.push_back(dataset[index][i]);
            tmp->isleaf=false;
            tmp->spliton=dataset[index][0];
            vector<vector<string> >atable=prunetable(table,dataset[index][0],dataset[index][i]);
            ptr->child.push_back(makeTree(atable,tmp,dataset));
        }
        return ptr;
    }
    return ptr;
}
string scolumn(vector<vector<string> > &table)
{
    double minentropy=999999999.99;
    int sc=0;
    vector<int>ent;
    for(int c=0;c<table[0].size()-1;c++)
    {
        string cname=table[0][c];
        map<string,int>m;
        vector<int>cnt;
        cnt=distinct(table,c);
        double ce=0.0;
        vector<double>enlist;
        for(int i=1;i<table.size()-1;i++)
        {
            double entropy=0.0;
            if(m.find(table[i][c])!=m.end())
                m[table[i][c]]++;
            else
            {
                m[table[i][c]]=1;
                vector<vector<string> >temp;
                temp=prunetable(table,cname,table[i][c]);
                vector<int>classes;
                classes=distinct(temp,temp[0].size()-1);
                for(int j=0;j<classes.size();j++)
                {
                    double tmp=(double)classes[j];
                    entropy-=(tmp/classes[classes.size()-1])*(log(tmp/classes[classes.size()-1])/log(2));
                }
                enlist.push_back(entropy);
                entropy=0.0;
            }
        }
        for(int i=0;i<cnt.size()-1;i++)
            ce+=((double)cnt[i]*(double)enlist[i]);
        ce=ce/((double)cnt[cnt.size()-1]);
        if(ce<=minentropy)
        {
            minentropy=ce;
            sc=c;
        }
    }
    return table[0][sc];
}
vector<int> distinct(vector<vector<string> > &table,int c)
{
    vector<string>v;
    bool ss=false;
    vector<int>cnt;
    int index;
    for(int i=1;i<table.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==table[i][c])
            {
                ss=true;
                index=j;
                break;
            }
            else
                ss=false;
        }
        if(ss)
            cnt[index]++;
        else
        {
            cnt.push_back(1);
            v.push_back(table[i][c]);
        }
    }
    int sum=0;
    for(int i=0;i<cnt.size();i++)
        sum+=cnt[i];
    cnt.push_back(sum);
    return cnt;
}

vector<vector<string> > prunetable(vector<vector<string> > &atr,string &cname,string val)
{
    vector<vector<string> >v;
    int c=-1;
    vector<string>r;
    for(int i=0;i<atr[0].size();i++)
    {
        if(atr[0][i]==cname)
        {
            c=i;
            break;
        }
    }
    for(int i=0;i<atr[0].size();i++)
    {
        if(i==c)
            continue;
        r.push_back(atr[0][i]);
    }
    v.push_back(r);
    for(int i=0;i<atr.size();i++)
    {
        vector<string>tmp;
        if(atr[i][c]==val)
        {
            for(int j=0;j<atr[i].size();j++)
            {
                if(j==c)
                    continue;
                tmp.push_back(atr[i][j]);
            }
            v.push_back(tmp);
        }
    }
    return v;
}

string testData(vector<string> &str,node* ptr,vector<vector<string> > &dataset,string dc)
{
    string cls;
    while(!ptr->isleaf&&!ptr->child.empty())
    {
        int in=-1;
        for(int i=0;i<dataset.size();i++)
        {
            if(dataset[i][0]==ptr->spliton)
            {
                in=i;
                break;
            }
        }
        string val=str[in];
        int cind=-1;
        for(int i=0;i<ptr->childv.size();i++)
        {
            if(ptr->childv[i]==val)
            {
                cind=i;
                break;
            }
        }
        ptr=ptr->child[cind];
        if(ptr==NULL)
        {
            cls=dc;
            break;
        }
        cls=ptr->label;
    }
    return cls;
}

string defaultclass(vector<vector<string> > &data)
{
    map<string,int>als;
    for(int  i=1;i<data.size();i++)
    {
        if(als.count(data[i][data[0].size()-1])==0)
            als[data[i][data[0].size()-1]]=1;
        else
            als[data[i][data[0].size()-1]]++;
    }
    map<string,int>::iterator iter;
    int mx=0;
    string ds;
    for(iter=als.begin();iter!=als.end();iter++)
    {
        if(iter->second>=mx)
        {
            mx=iter->second;
            ds=iter->first;
        }
    }
    return ds;
}
int main(int argc, char ** argv)
{
    if(argc!=4)
    {
        cout<<"Insufficient Arguments"<<endl;
        return 1;
    }
    ifstream inp;
    string cmd=argv[1];
    inp.open(cmd.c_str());
    vector<vector<string> >data;
    string str;
    while(getline(inp,str))
    {
        int arc=0;
        vector<string>v;
        istringstream is(str);
        for(string s;is>>s;)
        {
            if(s!=" "||s.size()>0)
                v.push_back(s);
        }
        data.push_back(v);
        v.clear();
    }
    inp.close();
    vector<vector<string> >dataset;
    for(int i=0;i<data[0].size();i++)
    {
        vector<string>tmp;
        map<string,int>m;
        for(int j=0;j<data.size();j++)
        {
            if(m.count(data[j][i])==0)
            {
                m[data[j][i]]=1;
                tmp.push_back(data[j][i]);
            }
            else
                m[data[j][i]]++;
        }
        dataset.push_back(tmp);
    }

    node* root=new node;
    node* rootarr[15];
    string type=argv[3];
    if(type=="optimized")
        root=makeTree(data,root,dataset);
    else if(type=="randomized")
        root=makeRTree(data,root,dataset);
    else if(type=="forest3")
    {
        for(int i=0;i<3;i++)
            rootarr[i]=makeRTree(data,rootarr[i],dataset);
    }
    else
    {
        for(int i=0;i<15;i++)
            rootarr[i]=makeRTree(data,rootarr[i],dataset);
    }
    string dc=defaultclass(data);
    cmd=argv[2];
    inp.open(cmd.c_str());
    data.clear();
    while(getline(inp,str))
    {
        int arc=0;
        vector<string>v;
        istringstream is(str);
        for(string s;is>>s;)
        {
            if(s!=" "||s.size()>0)
                v.push_back(s);
            else
                continue;

        }

        data.push_back(v);
    }

    map<string,int>total,correct;
    for(int i=0;i<data.size();i++)
    {
        string gc,pc;
        gc=data[i][data[0].size()-1];
        if(type=="optimized"||type=="randomized")
            pc=testData(data[i],root,dataset,dc);
        else if(type=="forest3")
        {
            map<string,int>tmap;
            int mx=0;
            for(int j=0;j<3;j++)
            {
                string mm=testData(data[i],rootarr[j],dataset,dc);
                tmap[mm]++;
                if(tmap[mm]>mx)
                {
                    mx=tmap[mm];
                    pc=mm;
                }
            }
        }
        else if(type=="forest15")
        {
            map<string,int>tmap;
            int mx=0;
            for(int j=0;j<15;j++)
            {
                string mm=testData(data[i],rootarr[j],dataset,dc);
                tmap[mm]++;
                if(tmap[mm]>mx)
                {
                    mx=tmap[mm];
                    pc=mm;
                }
            }
        }
        total[gc]++;
        if(gc==pc)
            correct[gc]++;
        double acc=(double)correct[gc]/(double)total[gc];
        printf("ID=%5d, predicted= %s, true= %s, accuracy=%4.2lf\n",i+1, pc.c_str(),gc.c_str(), acc);
    }
    return 0;
}
