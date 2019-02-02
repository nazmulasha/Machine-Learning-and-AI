#include <bits/stdc++.h>
#include <dos.h>
using namespace std;
double a=-1,b=-1;
double linear(vector<double>x, vector<double>y, int n,double k)
{
    double sumx=0,sumy=0,sumxy=0,sumx2=0;
   // double a,b;

    for(int i=0;i<n;i++)
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +y[i];
        sumxy=sumxy +x[i]*y[i];
      //  cout<<sumx<<" "<<sumx2<<" "<<sumy<<" "<<sumxy<<endl;
    }
    a=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
   // printf("\n\nThe line is Y=%3.3f +%3.3f X\n",a,b);
   //cout<<a<<" "<<b<<endl;
    return a+b*k;
}

int main()
{
    freopen("com.txt","r",stdin);
    using namespace std::chrono;
    using namespace std::this_thread;
    int n,ln=80;
    double yr[ln], salary[ln],test[7];
    double total =0;
    vector<double>xx,yy[4],data[5];
    for(int i=0;i<110;i++)
    {
        for(int j=0;j<5;j++)
        {
            double xp;
            cin>>xp;
            data[j].push_back(xp);
        }
    }
    int tst=80;
    for(int i=0;i<4;i++)
    {
        vector<double>x,y;
        for(int j=0;j<110;j++)
        {
            double arr[4],rr=data[4][j],rrr[4];

            y.push_back(data[i][j]);
            x.push_back((j%10)+1);
            if(j>tst)
            {
                rrr[i]=linear(x,y,50,(j%10)+1);
                yy[i].push_back(rrr[i]);
                xx.push_back(rr);

            }
        }
    }
    double corr=0.0;
    string bg[2]={"Unsafe","Safe"};
    for(int i=0;i<110-tst-1;i++)
    {
        double tmp=yy[0][i],ph=yy[1][i],turb=yy[2][i],ec=yy[3][i];
        int ver,vr=(int)xx[i];
        //cout<<tmp<<" "<<ph<<" "<<turb<<" "<<ec<<endl;
        if(tmp>=15&&tmp<=45&&ph>=6&&ph<=8.5&&turb>=8.25&&turb<=11&&ec>=0&&ec<=1.5)
            ver=1;
        else
            ver=0;
        if(vr==ver){
            corr++;

        }
        cout<<"Original = "<<bg[vr]<<", Predicted = "<<bg[ver]<<" , Accuracy: "<<corr/double(i+1)<<endl;
    }

    return 0;
}
