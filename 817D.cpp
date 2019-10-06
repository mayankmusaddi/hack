#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
const int lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> a;
	for(int i=0;i<n;i++)
	{
		ll k;
		cin >> k;
		a.pb(k);
	}

	stack<ll> st;
	vector <ll> lt(n,0);
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[i] < a[st.top()])
			st.pop();
		if(st.empty())
			lt[i] = i + 1;
		else
			lt[i] = i - st.top();
		st.push(i);
	}
	while(!st.empty())
		st.pop();

	vector <ll> gt(n,0);
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[i] > a[st.top()])
			st.pop();
		if(st.empty())
			gt[i] = i + 1;
		else
			gt[i] = i - st.top();
		st.push(i);
	}
	while(!st.empty())
		st.pop();
	
	reverse(a.begin(),a.end());

	vector <ll> ltR(n,0);
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[i] <= a[st.top()])
			st.pop();
		if(st.empty())
			ltR[n-i-1] = i + 1;
		else
			ltR[n-i-1] = i - st.top();
		st.push(i);
	}
	while(!st.empty())
		st.pop();

	vector <ll> gtR(n,0);
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[i] >= a[st.top()])
			st.pop();
		if(st.empty())
			gtR[n-i-1] = i + 1;
		else
			gtR[n-i-1] = i - st.top();
		st.push(i);
	}
	while(!st.empty())
		st.pop();

	reverse(a.begin(),a.end());
	ll mn  = 0,mx = 0;
	for(int i=0;i<n;i++)
	{
		mn+=lt[i]*ltR[i]*a[i];
		mx+=gt[i]*gtR[i]*a[i];
	}
	cout << mx - mn << endl;
	return 0;
}