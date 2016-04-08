#include<bits/stdc++.h>
#define lop(i,a,b) for(unsigned int i=a;i<b;i++)
#define read freopen("fcfs_without_sorting.txt","r",stdin)
using namespace std;

int main()
{
    read;
    int pr;
    double avgwt=0.0,avgtat=0.0;
    cin>>pr;
    int in[pr][2],gant[pr],wt[pr],tat[pr];
    gant[0]=wt[0]=0;
    lop(i,0,pr){
        lop(j,0,2){
            cin>>in[i][j];
            if(i==0){
                gant[i]+=in[i][j];
                if(j==1) tat[i]=gant[i]-in[i][j];
            }
        }
        if(i>0){
            gant[i]=gant[i-1]+in[i][0];
            wt[i]=gant[i-1]-in[i][1];
            tat[i]=gant[i]-in[i][1];
        }
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    avgwt/=pr;
    avgtat/=pr;
    lop(i,0,pr) cout<<wt[i]<<endl;
    cout<<endl;
    lop(i,0,pr) cout<<tat[i]<<endl;
    cout<<endl;
    cout<<avgwt<<endl;
    cout<<avgtat<<endl;
    return 0;
}
