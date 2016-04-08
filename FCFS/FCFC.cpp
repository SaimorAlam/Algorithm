#include<bits/stdc++.h>
#define tlop(i,a,b) for(unsigned int i=a;i<=b;i++)
#define lop(i,a,b) for(unsigned int i=a;i<b;i++)
#define read freopen("FCFSin.txt","r",stdin)
#define write freopen("FCFSout.txt","w",stdout)

using namespace std;

struct type_a{
    string s;
    int a;
    int b;
};

struct type_b{
    string s;
    int b;
};

bool cmp(type_a A,type_a B){
    return A.a<B.a;
}

type_a nod_a;
type_b nod_b;

int main()
{
    read;
    int t,pr,a1,b1;
    double avgwt,avgtrt;
    string s;
    cout<<"Case..??\n";
    cin>>t;
    tlop(z,1,t){
        avgwt=avgtrt=0.0;
        cout<<"How many process ?\n";
        cin>>pr;
        vector<type_a> in,gantt;
        cout<<"Process It's arrival time and Burst time:\n";
        ///Inputting Data
        lop(i,0,pr){
            cin>>s>>b1>>a1;
            nod_a.s=s;
            nod_a.a=a1;
            nod_a.b=b1;
            in.push_back(nod_a);
        }
        sort(in.begin(),in.end(),cmp);
        /// GANTT Chart 0 index
        nod_a.s=in[0].s;
        nod_a.a=in[0].a;
        nod_a.b=in[0].a+in[0].b;
        gantt.push_back(nod_a);
        /// Waiting Time 0 index
        vector<type_b>wt,trt;
        nod_b.s=in[0].s;
        nod_b.b=in[0].a-in[0].a;
        wt.push_back(nod_b);
        /// AVERAGE Waiting Time  Initialization
        avgwt=wt[0].b;
        ///Turn Around Time 0 index
        nod_b.s=in[0].s;
        nod_b.b=gantt[0].b-in[0].a;
        trt.push_back(nod_b);
        ///Turn Around time Initialization
        avgtrt=trt[0].b;
        lop(i,1,pr){
            /// GANTT Chart Ith index
            nod_a.s=in[i].s;
            nod_a.a=gantt[i-1].b;
            nod_a.b=gantt[i-1].b+in[i].b;
            gantt.push_back(nod_a);
            /// Waiting Time Ith index
            nod_b.s=in[i].s;
            nod_b.b=gantt[i].a-in[i].a;
            wt.push_back(nod_b);
            ///Turn Around Time Ith index
            nod_b.s=in[i].s;
            nod_b.b=gantt[i].b-in[i].a;
            trt.push_back(nod_b);
            /// AVERAGE Waiting Time and Turn Around time
            avgwt+=wt[i].b;
            avgtrt+=trt[i].b;
        }
        avgwt/=pr;
        avgtrt/=pr;
        //cout<<system("cls");
        cout<<"GANTT Chart:\n";
        lop(i,0,pr) cout<<gantt[i].s<<" "<<gantt[i].a<<" "<<gantt[i].b<<endl;
        cout<<"Waiting Time:\n";
        lop(i,0,pr) cout<<wt[i].s<<" "<<wt[i].b<<endl;
        cout<<"Average waiting time: "<<avgwt<<endl;
        cout<<"Turn Around Time:\n";
        lop(i,0,pr) cout<<trt[i].s<<" "<<trt[i].b<<endl;
        cout<<"Average Turn Around Time: "<<avgtrt<<endl;
    }
    return 0;
}
