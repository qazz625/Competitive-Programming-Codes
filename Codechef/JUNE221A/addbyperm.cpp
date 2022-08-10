#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MAX 200010

int k;
int arr[MAX], visited[MAX], perm[MAX];

// https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/NumberTheoreticTransform.h

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}


vector<vector<int>> binomSumValues;
int binomindices[MAX];
int binomvalue[MAX];
int factorial[MAX];
int modinv[MAX];

int C(int n, int k){
	if(n < k)
		return 0;
	int num = factorial[n];
	int denom = modinv[k]*modinv[n-k] % mod;
	return num*denom % mod;
}

vl solve(vector<int> &values){
	int n = values.size();

	if(binomindices[n] == -1){
		binomindices[n] = binomSumValues.size();
		vector<int> temp(n);
		for(int i=0; i<n; i++){
			int cur = 0;
			for(int j=i; j<=k; j+=n){
				cur += binomvalue[j];
			}
			temp[i] = cur%mod;
		}
		// debug(n);
		// print(temp);
		binomSumValues.push_back(temp);
	}


	vector<int> add = binomSumValues[binomindices[n]];

	vector<int> a(2*n);
	vector<int> b(2*n);
	for(int i=0; i<n; i++){
		a[i] = values[n-1-i];
		b[i] = add[i];
		b[i+n] = add[i];
	}
	// print(a);
	// print(b);

	vl res = conv(a, b);
	vl ret(n);
	ret[0] = res[n-1];
	for(int i=2*n-2, j=1; i>n-1; i--, j++){
		ret[j] = res[i];
	}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	factorial[0] = 1;
	modinv[0] = 1;
	binomindices[0] = -1;
	for(int i=1; i<MAX; i++){
		factorial[i] = factorial[i-1]*i % mod;
		modinv[i] = modpow(factorial[i], mod-2);
		binomindices[i] = -1;
	}

	int n;
	cin >> n >> k;

	for(int i=0; i<=k; i++){
		binomvalue[i] = C(k, i);
	}

	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<n; i++){
		cin >> perm[i];
		perm[i]--;
	}

	int res[n] = {0};

	for(int i=0; i<n; i++){
		if(visited[i] == 0){
			vector<int> indices, values;
			int cur = i;
			while(visited[cur] == 0){
				visited[cur] = 1;
				indices.push_back(cur);
				values.push_back(arr[cur]);
				cur = perm[cur];
			}
			vl ans = solve(values);

			for(int i=0; i<indices.size(); i++){
				res[indices[i]] = ans[i];
			}
		}
	}

	for(int i=0; i<n; i++)
		cout << res[i] << " ";
	cout << "\n";
}

