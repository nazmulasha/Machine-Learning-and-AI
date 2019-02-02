#include <bits/stdc++.h>

using namespace std;

#define pii 3.141592653589793238462643383

double mean(vector<double>v)
{
    double sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        //cout<<v[i]<<" "<<sum<<endl;
    }
    return sum/v.size();
}

double stddev(vector<double>v)
{
    double avg=mean(v);
    double sum=0.0,sum2=0.0;

    for(int i=0;i<v.size();i++)
    {
        //double diff=v[i]-avg;
        sum2+=(v[i]*v[i]);
        sum+=v[i];
    }
    sum=(sum*sum)/v.size();
    //cout<<sum2<<endl;
    double var=(sum2-sum)/(v.size()-1);
    return var;
}

double prob(double x, double mn, double stdv)
{
    //cout<<mn<<" "<<stdv<<endl;
	double expo=((pow(x-mn,2)/(2*pow(stdv,2))));
	//expo=-23.26849;
	expo=exp(-expo);
	return (expo/(sqrt(2*pii*stdv*stdv)));
}

int main()
{
    //cout<<exp(2)<<endl;
    freopen("com.txt","r",stdin);
    vector<double>sa1,sa2,sa3,sa4,sa5,sa6,sa7,sa8,ua1,ua2,ua3,ua4,ua5,ua6,ua7,ua8,r,test[10];
    for(int i=0;i<110;i++)
    {
            double a1,a2,a3,a4,a5,a6,a7,a8,rr;
            cin>>a1>>a2>>a3>>a4>>rr;
        if(i<60)
        {
            r.push_back(rr);
            if(rr>0.0)
            {
                sa1.push_back(a1);
                sa2.push_back(a2);
                sa3.push_back(a3);
                sa4.push_back(a4);
            }
            else
            {
                ua1.push_back(a1);
                ua2.push_back(a2);
                ua3.push_back(a3);
                ua4.push_back(a4);
            }
        }
        else
        {
            test[0].push_back(a1);
            test[1].push_back(a2);
            test[2].push_back(a3);
            test[3].push_back(a4);
            test[4].push_back(rr);
        }
    }
 //   cout<<"all ok"<<endl;
    int corr=0;
    for(int i=0;i<test[0].size();i++)
    {
        double a1=test[0][i],a2=test[1][i],a3=test[2][i],a4=test[3][i];
        double ml,fml;
        int ori=(int)test[4][i];
        double ev1=0.5*prob(a1,mean(sa1),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))*prob(a4,mean(sa4),stddev(sa4))+0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3))*prob(a4,mean(ua4),stddev(ua4));
        //ev1+=0.125*prob(a4,mean(sa),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))+0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3));

        ml=0.5*prob(a1,mean(sa1),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))*prob(a4,mean(sa4),stddev(sa4));
        ml/=ev1;
        fml=0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3))*prob(a4,mean(ua4),stddev(ua4));
        fml/=ev1;
        int px;
        if(ml>=fml)
            px=1;
        else
            px=0;
        if(px==ori)
            corr++;
        cout<<"original = "<<ori<<" predicted = "<<px<<" , Acc = "<<corr/(double)(i+1)<<endl;
    }
    return 0;
}
