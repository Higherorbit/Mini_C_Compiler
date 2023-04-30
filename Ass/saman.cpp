 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define in(n) int n; cin>>n;
#define w(x) int x; cin>>x; while(x--)
#define int long long
#define str(s) string s; cin>>s;
#define sz(x) static_cast<int>(x.size())
#define endl "\n"
#define dbg(x) cerr << #x << "->" << x << "\n"
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
#define prntp(x) cerr<<#x<<'{';for(auto T:x)cerr<<T.first<<'-'<<T.second<<' ';cerr<<"}\n";
const int mod = 1000000007;
#define INF numeric_limits<double>::infinity()
const int MAX=10000;
#define FAST cin.tie(0)->sync_with_stdio(0);
 
typedef tree <int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;
 
struct point{
	double x,y;
};
static bool cmp(point &a,point &b){
	return a.x>b.x;
}
 
void calculate_cost(double e[][MAX],vector<double>&dp,vector<double>&segments,int n,int c){
    dp[0]=0;
	for(int j=1;j<=n;j++){
		double val=INF;
		int k=0;
		for(int i=1;i<=j;i++){
			if(e[i][j]+dp[i-1]<val){
				val=e[i][j]+dp[i-1];
				k=i;
			}
		}
		dp[j]=val+c;
		segments[j]=k;
	}
 
}
void print_cost(vector<double>dp,int n){
    cout<<"The optimal cost is: ";
	cout<<dp[n]<<endl;
}
 
void print_optimal(double slope[][MAX],double intercept[][MAX],stack<int>s){
    printf("\n Optimal Solution is:\n");
	while(!s.empty()){
		i=s.top();
		s.pop();
		j=s.top();
		s.pop();
		cout<<"The line is y="<<intercept[i][j]<<"x+ "<<slope[i][j];
		cout<<" from points x`"<<i<<" to "<<j<<endl;
	}
}
 
void calculate_slope_intercept(vector<point>points,double slope[][MAX],double intercept[][MAX],double e[][MAX],int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            double x=sumX[j]-sumX[i-1];
            double y=sumY[j]-sumY[i-1];
            double xy=sumXY[j]-sumXY[i-1];
            double xx=sumXX[j]-sumXX[i-1];
            double m=(j-i+1)*xy-x*y;
            double b=xx*y-x*xy;
            m/=((j-i+1)*xx-x*x);
            b/=((j-i+1)*xx-x*x);
            slope[i][j]=m;
            intercept[i][j]=b;
            double val=0;
            for(int k=i;k<=j;k++){
                val+=(points[k].y-m*points[k].x-b)*(points[k].y-m*points[k].x-b);
            }
            e[i][j]=val;
        }
    }
}
 
void preparing_the_recipe(vector<point>points,vector<double>&sumX,vector<double>&sumY,vector<double>&sumXY,vector<double>&sumXX,int n){
    sumX[0]=0;
    sumY[0]=0;
    sumXY[0]=0;
    sumXX[0]=0;
    for(int i=1;i<=n;i++){
        sumX[i]=sumX[i-1]+points[i].x;
        sumY[i]=sumY[i-1]+points[i].y;
        sumXY[i]=sumXY[i-1]+points[i].x*points[i].y;
        sumXX[i]=sumXX[i-1]+points[i].x*points[i].x;
    }
}
 
int32_t main(){
 
    //taking input for the problem
	in(n);
	in(c);
	vector<point>points(n+1);
	for(int i=1;i<=n;i++){
		double x,y;
		cin>>x>>y;
		points[i].x=x;
		points[i].y=y;
	}
	std::vector<double> sumX(n+1),sumY(n+1),sumXY(n+1),sumXX(n+1);
 
    //sort and reverse the points vector according to the x coordinate
	sort(points.begin(),points.end(),cmp);
	reverse(points.begin(),points.end());
 
    // calculating the sum of x,y,xy and x^2
    preparing_the_recipe(points,sumX,sumY,sumXY,sumXX,n);
	
	for(auto i:points){
		cout<<i.x<<" "<<i.y<<endl;
	}
	double e[n+1][n+1],slope[n+1][n+1],intercept[n+1][n+1];
	memset(e,0.0,sizeof(e));
 
    // calculating the slope and intercept for the line connecting pi,.. pj
    calulate_slope_intercept(points,slope,intercept,e,n);
 
	
    // calculating the optimal cost
	vector<double>dp(n+1,INT_MAX),segments(n+1); // make dp array and segments array
    calculate_cost(e,dp,segments,n,c);
	
    // printing the optimal cost
    print_cost(dp,n);
	
	stack<int>s;
	int j,i=n;
	for(i;i>0;i=j-1){
		j=segments[i];
		s.push(i),s.push(j);
	}
 
    // printing the optimal solution
    print_optimal(slope,intercept,s);
    return 0;
 
}