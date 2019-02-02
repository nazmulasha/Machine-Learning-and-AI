#include <bits/stdc++.h>

using namespace std;

#define pii 3.1416
#define M_PI 3.141592653589793238462643383
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

double gaussian_prob(double obs, double mu, double sig){
  double num = pow((obs - mu), 2);
  double denum = 2*pow(sig, 2);
  double norm = 1 / sqrt(2*M_PI*pow(sig, 2));
  return norm * exp(-num/denum);
}
int main()
{
    //cout<<exp(2)<<endl;
    freopen("db.txt","r",stdin);
    vector<double>sa1,sa2,sa3,sa4,sa5,sa6,sa7,sa8,ua1,ua2,ua3,ua4,ua5,ua6,ua7,ua8,r,test[10];
    for(int i=0;i<768;i++)
    {
            double a1,a2,a3,a4,a5,a6,a7,a8,rr;
            cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>rr;
        if(i<600)
        {
            r.push_back(rr);
            if(rr>0.0)
            {
                sa1.push_back(a1);
                sa2.push_back(a2);
                sa3.push_back(a3);
                sa4.push_back(a4);
                sa5.push_back(a5);
                sa6.push_back(a6);
                sa7.push_back(a7);
                sa8.push_back(a8);
            }
            else
            {
                ua1.push_back(a1);
                ua2.push_back(a2);
                ua3.push_back(a3);
                ua4.push_back(a4);
                ua5.push_back(a5);
                ua6.push_back(a6);
                ua7.push_back(a7);
                ua8.push_back(a8);
            }
        }
        else
        {
            test[0].push_back(a1);
            test[1].push_back(a2);
            test[2].push_back(a3);
            test[3].push_back(a4);
            test[4].push_back(a5);
            test[5].push_back(a6);
            test[6].push_back(a7);
            test[7].push_back(a8);
            test[8].push_back(rr);
        }
    }
    int corr=0;
    for(int i=0;i<test[0].size();i++)
    {
        double a1=test[0][i],a2=test[1][i],a3=test[2][i],a4=test[3][i],a5=test[4][i],a6=test[5][i],a7=test[6][i],a8=test[7][i];
        double ml,fml;
        int ori=(int)test[8][i];
        double ev1=0.5*prob(a1,mean(sa1),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))*prob(a4,mean(sa4),stddev(sa4))*prob(a5,mean(sa5),stddev(sa5))*prob(a6,mean(sa6),stddev(sa6))*prob(a7,mean(sa7),stddev(sa7))*prob(a8,mean(sa8),stddev(sa8))+0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3))*prob(a4,mean(ua4),stddev(ua4))*prob(a5,mean(ua5),stddev(ua5))*prob(a6,mean(ua6),stddev(ua6))*prob(a7,mean(ua7),stddev(ua7))*prob(a8,mean(ua8),stddev(ua8));
        //ev1+=0.125*prob(a4,mean(sa),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))+0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3));

        ml=0.5*prob(a1,mean(sa1),stddev(sa1))*prob(a2,mean(sa2),stddev(sa2))*prob(a3,mean(sa3),stddev(sa3))*prob(a4,mean(sa4),stddev(sa4))*prob(a5,mean(sa5),stddev(sa5))*prob(a6,mean(sa6),stddev(sa6))*prob(a7,mean(sa7),stddev(sa7))*prob(a8,mean(sa8),stddev(sa8));
        ml/=ev1;
        fml=0.5*prob(a1,mean(ua1),stddev(ua1))*prob(a2,mean(ua2),stddev(ua2))*prob(a3,mean(ua3),stddev(ua3))*prob(a4,mean(ua4),stddev(ua4))*prob(a5,mean(ua5),stddev(ua5))*prob(a6,mean(ua6),stddev(ua6))*prob(a7,mean(ua7),stddev(ua7))*prob(a8,mean(ua8),stddev(ua8));
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
