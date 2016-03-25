#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin)
#define tlop(i,a,b) for(unsigned int i=a;i<=b;i++)
#define loop(i,a,b) for(unsigned int i=a;i<b;i++)
using namespace std;
int main()
{
    //read;
    int t,n,m;
    cout<<"How many times:";    ///for more then 1 test case.
    cin>>t;
    tlop(z,1,t){
        cout<<"How many process and resources:"<<"<column[p] & row[r] of metrics>";
        cin>>n>>m;

        int alloc[n+2][m+2]={0},maxx[n+2][m+2]={0},need[n+2][m+2]={0},avail[m+2]={0},sst[n+2]={0};
        ///input for allocation
        cout<<"\nRequest resources for process:"<<endl;
        loop(i,0,n){
            loop(j,0,m){
                cin>>alloc[i][j];
            }
        }
        ///max and need
        cout<<"Max resources for process:";
        loop(i,0,n){
            loop(j,0,m){
                cin>>maxx[i][j];
                need[i][j]=maxx[i][j]-alloc[i][j];
            }
        }
        ///input for initial available
        cout<<"Available resources for process:";
        loop(i,0,m) cin>>avail[i];
        ///Processing
        bool check[n+2]={0};
        int cunt=0,s=0;
        loop(i,0,n-1){
            loop(j,0,n){
                if(check[j]==0){
                    cunt=0;
                    loop(k,0,m){
                        if(need[j][k]<=avail[k]) cunt++;
                        else break;
                    }
                    if(cunt==m){
                        sst[s++]=j;
                        check[j]=1;
                        loop(l,0,m){
                            avail[l]+=alloc[j][l];
                        }
                    }
                }
            }
        }
        if(s<n){
            cout<<"Times: "<<z<<endl;
            cout<<"Deadlock found"<<endl;
        }
        else{
            cout<<"Times: "<<z<<endl;
            cout<<"Safe state are:";
            loop(q,0,n) printf("P%d ",sst[q]);
            cout<<endl;
        }
    }
    return 0;
}
