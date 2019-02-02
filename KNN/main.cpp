#include <bits/stdc++.h>

using namespace std;

double eucdistance(vector<double>a,vector<double>b)
{
    double sum=0;
    for(int i=0;i<a.size();i++)
    {
        sum+=pow(a[i]-b[i],2);
    }
    return sqrt(sum);
}

int getResult(vector<double>train[5],vector<double>test,int k)
{
    vector<pair<double,int> >nn;
    for(int i=0;i<train[0].size();i++)
    {
        double dist=sqrt(pow(train[0][i]-test[0],2)+pow(train[1][i]-test[1],2)+pow(train[2][i]-test[2],2)+pow(train[3][i]-test[3],2));
        nn.push_back({dist,train[4][i]});
    }
    sort(nn.begin(),nn.end());
    int arr[4]={0,0,0,0};
    for(int i=0;i<k;i++)
        arr[nn[i].second]++;
    vector< pair<int,int> >v;
    for(int i=0;i<2;i++)
        v.push_back({arr[i],i});
    sort(v.begin(),v.end());
    return v[v.size()-1].second;
}

int main()
{
    freopen("com.txt","r",stdin);
    vector<double>train[5],test[5];
    for(int i=0;i<110;i++)
    {
        double a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(i<80)
        {
            train[0].push_back(a);
            train[1].push_back(b);
            train[2].push_back(c);
            train[3].push_back(d);
            train[4].push_back(e);
        }
        else
        {
            test[0].push_back(a);
            test[1].push_back(b);
            test[2].push_back(c);
            test[3].push_back(d);
            test[4].push_back(e);
        }
    }
    int corr=0;
    string st[2]={"Unsafe","Safe"};
    for(int i=0;i<test[0].size();i++)
    {
        vector<double>tmp;
        tmp.push_back(test[0][i]);
        tmp.push_back(test[1][i]);
        tmp.push_back(test[2][i]);
        tmp.push_back(test[3][i]);
        int pred=getResult(train,tmp,5);
        int ori=test[4][i];
        if(ori==pred)
            corr++;
        cout<<"original = "<<st[ori]<<" predicted = "<<st[pred]<<" , Acc = "<<corr/(double)(i+1)<<endl;
    }
    return 0;
}
