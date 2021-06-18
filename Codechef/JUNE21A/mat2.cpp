#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif


using uint=unsigned;
using ull=unsigned long long;

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

#define USE_FMT

/*
//998244353
const mint prim_root=3;
//in-place fft
//size of input must be a power of 2
void inplace_fmt(vector<mint>&f,const bool inv){
	const int n=f.size();
	const mint root=inv?prim_root.inv():prim_root;
	vc<mint> g(n);
	for(int b=n/2;b>=1;b/=2){
		mint w=root.pow((mint::base-1)/(n/b)),p=1;
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=p;
				g[i/2+j]=f[i+j]+f[i+b+j];
				g[n/2+i/2+j]=f[i+j]-f[i+b+j];
			}
			p*=w;
		}
		swap(f,g);
	}
	if(inv)rep(i,n)
		f[i]*=inv[n];
}*/

//size of input must be a power of 2
//output of forward fmt is bit-reversed
//output elements are in the range [0,mod*4)
//input of inverse fmt should be bit-reversed
template<class mint>
void inplace_fmt(const int n,mint*const f,bool inv){
	static constexpr uint mod=mint::mod;
	static constexpr uint mod2=mod*2;
	static const int L=30;
	static mint g[L],ig[L],p2[L];
	if(g[0].v==0){
		rep(i,L){
			mint w=-mint::root().pow(((mod-1)>>(i+2))*3);
			g[i]=w;
			ig[i]=w.inv();
			p2[i]=mint(1<<i).inv();
		}
	}
	if(!inv){
		int b=n;
		if(b>>=1){//input:[0,mod)
			rep(i,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mod-x;
				f[i].v+=x;
			}
		}
		if(b>>=1){//input:[0,mod*2)
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
		while(b){
			if(b>>=1){//input:[0,mod*3)
				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						f[j+b].v=f[j].v+mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
			if(b>>=1){//input:[0,mod*4)
				mint p=1;
				for(int i=0,k=0;i<n;i+=b*2){
					rng(j,i,i+b){
						uint x=(f[j+b]*p).v;
						f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
						f[j+b].v=f[j].v+mod-x;
						f[j].v+=x;
					}
					p*=g[__builtin_ctz(++k)];
				}
			}
		}
	}else{
		int b=1;
		if(b<n/2){//input:[0,mod)
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					ull x=f[j].v+mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j+b].v=x*p.v%mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
			b<<=1;
		}
		for(;b<n/2;b<<=1){
			mint p=1;
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b/2){//input:[0,mod*2)
					ull x=f[j].v+mod2-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
					f[j+b].v=x*p.v%mod;
				}
				rng(j,i+b/2,i+b){//input:[0,mod)
					ull x=f[j].v+mod-f[j+b].v;
					f[j].v+=f[j+b].v;
					f[j+b].v=x*p.v%mod;
				}
				p*=ig[__builtin_ctz(++k)];
			}
		}
		if(b<n){//input:[0,mod*2)
			rep(i,b){
				uint x=f[i+b].v;
				f[i+b].v=f[i].v+mod2-x;
				f[i].v+=x;
			}
		}
		mint z=p2[__lg(n)];
		rep(i,n)f[i]*=z;
	}
}

template<class mint>
void inplace_fmt(vector<mint>&f,bool inv){
	inplace_fmt(si(f),f.data(),inv);
}

template<class mint>
void half_fmt(const int n,mint*const f){
	static constexpr uint mod=mint::mod;
	static constexpr uint mod2=mod*2;
	static const int L=30;
	static mint g[L],h[L];
	if(g[0].v==0){
		rep(i,L){
			g[i]=-mint::root().pow(((mod-1)>>(i+2))*3);
			h[i]=mint::root().pow((mod-1)>>(i+2));
		}
	}
	int b=n;
	int lv=0;
	if(b>>=1){//input:[0,mod)
		mint p=h[lv++];
		for(int i=0,k=0;i<n;i+=b*2){
			rng(j,i,i+b){
				uint x=(f[j+b]*p).v;
				f[j+b].v=f[j].v+mod-x;
				f[j].v+=x;
			}
			p*=g[__builtin_ctz(++k)];
		}
	}
	if(b>>=1){//input:[0,mod*2)
		mint p=h[lv++];
		for(int i=0,k=0;i<n;i+=b*2){
			rng(j,i,i+b){
				uint x=(f[j+b]*p).v;
				f[j+b].v=f[j].v+mod-x;
				f[j].v+=x;
			}
			p*=g[__builtin_ctz(++k)];
		}
	}
	while(b){
		if(b>>=1){//input:[0,mod*3)
			mint p=h[lv++];
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
		if(b>>=1){//input:[0,mod*4)
			mint p=h[lv++];
			for(int i=0,k=0;i<n;i+=b*2){
				rng(j,i,i+b){
					uint x=(f[j+b]*p).v;
					f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
					f[j+b].v=f[j].v+mod-x;
					f[j].v+=x;
				}
				p*=g[__builtin_ctz(++k)];
			}
		}
	}
}

template<class mint>
void half_fmt(vector<mint>&f){
	half_fmt(si(f),f.data());
}

template<class mint>
vc<mint> multiply(vc<mint> x,const vc<mint>&y,bool same=false){
	int n=si(x)+si(y)-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);inplace_fmt(x,false);
	if(!same){
		vc<mint> z(s);
		rep(i,si(y))z[i]=y[i];
		inplace_fmt(z,false);
		rep(i,s)x[i]*=z[i];
	}else{
		rep(i,s)x[i]*=x[i];
	}
	inplace_fmt(x,true);x.resize(n);
	return x;
}

//59501818244292734739283969-1=5.95*10^25 までの値を正しく計算
//最終的な列の大きさが 2^24 までなら動く
//最終的な列の大きさが 2^20 以下のときは，下の 3 つの素数を使ったほうが速い（は？）
//VERIFY: yosupo
namespace arbitrary_convolution{
	//constexpr modinfo base0{167772161,3};//2^25 * 5 + 1
	//constexpr modinfo base1{469762049,3};//2^26 * 7 + 1
	//constexpr modinfo base2{754974721,11};//2^24 * 45 + 1
	constexpr modinfo base0{1045430273,3};//2^20 * 997 + 1
	constexpr modinfo base1{1051721729,6};//2^20 * 1003 + 1
	constexpr modinfo base2{1053818881,7};//2^20 * 1005 + 1
	using mint0=modular<base0>;
	using mint1=modular<base1>;
	using mint2=modular<base2>;
	template<class t,class mint>
	vc<t> sub(const vc<mint>&x,const vc<mint>&y,bool same=false){
		int n=si(x)+si(y)-1;
		int s=1;
		while(s<n)s*=2;
		vc<t> z(s);rep(i,si(x))z[i]=x[i].v;
		inplace_fmt(z,false);
		if(!same){
			vc<t> w(s);rep(i,si(y))w[i]=y[i].v;
			inplace_fmt(w,false);
			rep(i,s)z[i]*=w[i];
		}else{
			rep(i,s)z[i]*=z[i];
		}
		inplace_fmt(z,true);z.resize(n);
		return z;
	}
	template<class mint>
	vc<mint> multiply(const vc<mint>&x,const vc<mint>&y,bool same=false){
		auto d0=sub<mint0>(x,y,same);
		auto d1=sub<mint1>(x,y,same);
		auto d2=sub<mint2>(x,y,same);
		int n=si(d0);
		vc<mint> res(n);
		static const mint1 r01=mint1(mint0::mod).inv();
		static const mint2 r02=mint2(mint0::mod).inv();
		static const mint2 r12=mint2(mint1::mod).inv();
		static const mint2 r02r12=r02*r12;
		static const mint w1=mint(mint0::mod);
		static const mint w2=w1*mint(mint1::mod);
		rep(i,n){
			ull a=d0[i].v;
			ull b=(d1[i].v+mint1::mod-a)*r01.v%mint1::mod;
			ull c=((d2[i].v+mint2::mod-a)*r02r12.v+(mint2::mod-b)*r12.v)%mint2::mod;
			res[i].v=(a+b*w1.v+c*w2.v)%mint::mod;
		}
		return res;
	}
}
//using arbitrary_convolution::multiply;

template<class mint>
struct Poly:public vc<mint>{
	template<class...Args>
	Poly(Args...args):vc<mint>(args...){}
	Poly(initializer_list<mint>init):vc<mint>(all(init)){}
	int size()const{
		return vc<mint>::size();
	}
	void ups(int s){
		if(size()<s)this->resize(s,0);
	}
	Poly low(int s)const{
		return Poly(this->bg,this->bg+min(max(s,int(1)),size()));
	}
	Poly rev()const{
		auto r=*this;
		reverse(all(r));
		return r;
	}
	mint freq(int i)const{
		return i<size()?(*this)[i]:0;
	}
	Poly operator-()const{
		Poly res=*this;
		for(auto&v:res)v=-v;
		return res;
	}
	Poly& operator+=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]+=r[i];
		return *this;
	}
	template<class T>
	Poly& operator+=(T t){
		(*this)[0]+=t;
		return *this;
	}
	Poly& operator-=(const Poly&r){
		ups(r.size());
		rep(i,r.size())
			(*this)[i]-=r[i];
		return *this;
	}
	template<class T>
	Poly& operator-=(T t){
		(*this)[0]-=t;
		return *this;
	}
	template<class T>
	Poly& operator*=(T t){
		for(auto&v:*this)
			v*=t;
		return *this;
	}
	Poly& operator*=(const Poly&r){
		return *this=multiply(*this,r);
	}
	Poly square()const{
		return multiply(*this,*this,true);
	}
	#ifndef USE_FMT
	Poly inv(int s)const{
		Poly r{mint(1)/(*this)[0]};
		for(int n=1;n<s;n*=2)
			r=r*2-(r.square()*low(2*n)).low(2*n);
		return r.low(s);
	}
	#else
	//source: Section 4 of "Removing redundancy from high-precision Newton iteration"
	// 5/3
	Poly inv(int s)const{
		Poly r(s);
		r[0]=mint(1)/(*this)[0];
		for(int n=1;n<s;n*=2){
			vc<mint> f=low(2*n);
			f.resize(2*n);
			inplace_fmt(f,false);
			vc<mint> g=r.low(2*n);
			g.resize(2*n);
			inplace_fmt(g,false);
			rep(i,2*n)f[i]*=g[i];
			inplace_fmt(f,true);
			rep(i,n)f[i]=0;
			inplace_fmt(f,false);
			rep(i,2*n)f[i]*=g[i];
			inplace_fmt(f,true);
			rng(i,n,min(2*n,s))r[i]=-f[i];
		}
		return r;
	}
	#endif
	template<class T>
	Poly& operator/=(T t){
		return *this*=mint(1)/mint(t);
	}
	Poly quotient(const Poly&r,const Poly&rri)const{
		int m=r.size();
		assert(r[m-1].v);
		int n=size();
		int s=n-m+1;
		if(s<=0) return {0};
		return (rev().low(s)*rri.low(s)).low(s).rev();
	}
	Poly& operator/=(const Poly&r){
		return *this=quotient(r,r.rev().inv(max(size()-r.size(),int(0))+1));
	}
	Poly& operator%=(const Poly&r){
		*this-=*this/r*r;
		return *this=low(r.size()-1);
	}
	Poly operator+(const Poly&r)const{return Poly(*this)+=r;}
	template<class T>
	Poly operator+(T t)const{return Poly(*this)+=t;}
	Poly operator-(const Poly&r)const{return Poly(*this)-=r;}
	template<class T>
	Poly operator-(T t)const{return Poly(*this)-=t;}
	template<class T>
	Poly operator*(T t)const{return Poly(*this)*=t;}
	Poly operator*(const Poly&r)const{return Poly(*this)*=r;}
	template<class T>
	Poly operator/(T t)const{return Poly(*this)/=t;}
	Poly operator/(const Poly&r)const{return Poly(*this)/=r;}
	Poly operator%(const Poly&r)const{return Poly(*this)%=r;}
	Poly dif()const{
		Poly r(max(int(0),size()-1));
		rep(i,r.size())
			r[i]=(*this)[i+1]*(i+1);
		return r;
	}
	Poly inte(const mint invs[])const{
		Poly r(size()+1,0);
		rep(i,size())
			r[i+1]=(*this)[i]*invs[i+1];
		return r;
	}
	//VERIFY: yosupo
	//opencupXvcIII GP of Peterhof H
	Poly log(int s,const mint invs[])const{
		return (low(s).dif()*inv(s-1)).low(s-1).inte(invs);
	}
	//Petrozavodsk 2019w mintay1 G
	//yosupo judge
	Poly exp(int s)const{
		return exp2(s).a;
	}
	//2つほしいときはコメントアウトの位置ずらす
	pair<Poly,Poly> exp2(int s,const mint invs[])const{
		assert((*this)[0]==mint(0));
		Poly f{1},g{1};
		for(int n=1;;n*=2){
			if(n>=s)break;
			g=g*2-(g.square()*f).low(n);
			//if(n>=s)break;
			Poly q=low(n).dif();
			q=q+g*(f.dif()-f*q).low(2*n-1);
			f=f+(f*(low(2*n)-q.inte(invs))).low(2*n);
		}
		return make_pair(f.low(s),g.low(s));
	}
	//11/6
	//VERIFY: yosupo
	Poly sqrt(int s)const{
		assert((*this)[0]==1);
		static const mint half=mint(1)/mint(2);
		vc<mint> f{1},g{1},z{1};
		for(int n=1;n<s;n*=2){
			rep(i,n)z[i]*=z[i];
			inplace_fmt(z,true);
			
			vc<mint> delta(2*n);
			rep(i,n)delta[n+i]=z[i]-freq(i)-freq(n+i);
			inplace_fmt(delta,false);
			
			vc<mint> gbuf(2*n);
			rep(i,n)gbuf[i]=g[i];
			inplace_fmt(gbuf,false);
			
			rep(i,2*n)delta[i]*=gbuf[i];
			inplace_fmt(delta,true);
			f.resize(2*n);
			rng(i,n,2*n)f[i]=-half*delta[i];
			
			if(2*n>=s)break;
			
			z=f;
			inplace_fmt(z,false);
			
			vc<mint> eps=gbuf;
			rep(i,2*n)eps[i]*=z[i];
			inplace_fmt(eps,true);
			
			rep(i,n)eps[i]=0;
			inplace_fmt(eps,false);
			
			rep(i,2*n)eps[i]*=gbuf[i];
			inplace_fmt(eps,true);
			g.resize(2*n);
			rng(i,n,2*n)g[i]=-eps[i];
		}
		f.resize(s);
		return f;
	}
	pair<Poly,Poly> divide(const Poly&r,const Poly&rri)const{
		Poly a=quotient(r,rri);
		Poly b=*this-a*r;
		return make_pair(a,b.low(r.size()-1));
	}
	//Yukicoder No.215
	Poly pow_mod(int n,const Poly&r)const{
		Poly rri=r.rev().inv(r.size());
		Poly cur{1},x=*this%r;
		while(n){
			if(n%2)
				cur=(cur*x).divide(r,rri).b;
			x=(x*x).divide(r,rri).b;
			n/=2;
		}
		return cur;
	}
	mint eval(mint x)const{
		mint r=0,w=1;
		for(auto v:*this){
			r+=w*v;
			w*=x;
		}
		return r;
	}
};

//source: Tellegen’s Principle into Practice

template<class mint>
struct subproduct_tree{
	using poly=Poly<mint>;
	int raws,s,h;
	mint*buf;
	vc<mint*>f;
	vi len;
	poly top;
	void inner_product(const int n,const mint*a,const mint*b,mint*c){
		rep(i,n)c[i]=a[i]*b[i];
	}
	//first n elements are fft-ed
	//last n elements are raw data mod x^n-1
	//the coefficient of x^n is v
	//convert the whole array into size-2n fft-ed array
	void doubling_fmt(const int n,mint*a,const mint v){
		a[n]-=v*2;
		half_fmt(n,a+n);
	}
	subproduct_tree(const vc<mint>&a){
		raws=si(a);
		s=1;while(s<si(a))s*=2;
		h=__lg(s)+1;
		buf=new mint[s*h*2];
		f.resize(s*2);
		len.resize(s*2);
		{
			mint*head=buf;
			rng(i,1,s*2){
				len[i]=s>>__lg(i);
				f[i]=head;
				head+=len[i]*2;
			}
		}
		rep(i,s){
			mint w=i<si(a)?a[i]:0;
			f[s+i][0]=-w+1;
			f[s+i][1]=-w-1;
		}
		if(s==1)f[1][1]=f[1][0];
		gnr(i,1,s){
			inner_product(len[i],f[i*2],f[i*2+1],f[i]);
			copy(f[i],f[i]+len[i],f[i]+len[i]);
			inplace_fmt(len[i],f[i]+len[i],true);
			if(i>1)doubling_fmt(len[i],f[i],1);
		}
		top.resize(s+1);
		rep(i,s)top[i]=f[1][s+i];
		top[0]-=1;
		top[s]=1;
	}
	~subproduct_tree(){
		delete[] buf;
	}
	//VERIFY: yosupo
	vc<mint> multieval(const poly&b){
		mint*buf2=new mint[s*2];
		vc<mint*> c(s*2);
		{
			mint*head=buf2;
			rng(i,1,s*2){
				if((i&(i-1))==0&&__lg(i)%2==0)head=buf2;
				c[i]=head;
				head+=len[i];
			}
		}
		{
			poly tmp=top.rev().inv(si(b)).rev()*b;
			rep(i,s)c[1][i]=i<si(b)?tmp[si(b)-1+i]:0;
		}
		vc<mint> tmp(s);
		rng(i,1,s){
			inplace_fmt(len[i],c[i],false);
			rep(k,2){
				tmp.resize(len[i]);
				rep(j,len[i])tmp[j]=f[i*2+(k^1)][j]*c[i][j];
				inplace_fmt(tmp,true);
				rep(j,len[i]/2)c[i*2+k][j]=tmp[len[i]/2+j];
			}
		}
		vc<mint> ans(raws);
		rep(i,raws)ans[i]=c[s+i][0];
		delete[] buf2;
		return ans;
	}
	poly interpolate(const vc<mint>&val){
		mint*buf2=new mint[s*2*2];
		vc<mint*> c(s*2);
		{
			mint*head=buf2;
			rng(i,1,s*2){
				if((i&(i-1))==0&&__lg(i)%2==0)head=buf2;
				c[i]=head;
				head+=len[i]*2;
			}
		}
		{
			vc<mint> z=multieval(poly(top.bg+(s-si(val)),top.ed).dif());
			rep(i,s){
				mint w=i<si(val)?val[i]/z[i]:0;
				c[s+i][0]=c[s+i][1]=w;
			}
		}
		poly tmp(s);
		gnr(i,1,s){
			tmp.resize(len[i]);
			rep(j,len[i])
				tmp[j]=c[i][j]=c[i*2][j]*f[i*2+1][j]+c[i*2+1][j]*f[i*2][j];
			inplace_fmt(tmp,true);
			if(i>1)doubling_fmt(0,tmp,c[i]);
		}
		delete[] buf2;
		return poly(tmp.bg+(s-si(val)),tmp.ed);
	}
};

template<class mint>
vc<mint> multieval(const Poly<mint>&f,const vc<mint>&x){
	return subproduct_tree<mint>(x).multieval(f);
}

template<class mint>
Poly<mint> interpolate(const vc<mint>&x,const vc<mint>&y){
	assert(si(x)==si(y));
	if(si(x)==1)return {y[0]};
	subproduct_tree<mint> tree(x);
	return tree.interpolate(y);
}

constexpr modinfo base{998244353,3};
//constexpr modinfo base{1000000007,0};
using mint=modular<base>;

// int fact[200010], modinv[200010];
// int dp[200010][2];

// typedef long long ll;

// int C(int n, int r){
// 	if(n < r)
// 		return 1;

// 	ll num = fact[n];
// 	ll denom = (ll)modinv[r]*modinv[n-r] % mod;
// 	// debug(num, denom);

// 	return (ll)num*denom%mod;
// }

// int binpow(int a, int b, int m){
// 	if(b == 0)
// 		return 1;

// 	int x = binpow(a, b/2, m);
// 	x = (ll)x*x%m;

// 	if(b%2 == 0)
// 		return x;
// 	else
// 		return (ll)x*a%m;
// }


// signed main(){
// 	//cin.tie(0);
// 	//ios::sync_with_stdio(0);
// 	//cout<<fixed<<setprecision(20);

// 	int r, k;
// 	cin >> r >> k;

// 	fact[0] = 1;
// 	for(int i=1; i<200010; i++){
// 		fact[i] = (ll)fact[i-1]*i%mod;
// 	}
// 	modinv[200010-1] = binpow(fact[200010-1], mod-2, mod);
// 	for(int i=200010-2; i>=0; i--){
// 		modinv[i] = (ll)modinv[i+1]*(i+1)%mod;
// 	}
	
// 	using poly=Poly<mint>;

// 	vector<int> arr(k), prob(k);
// 	set<mint> evalpoints;
// 	for(int i=0; i<k; i++){
// 		cin >> arr[i];
// 		if(arr[i]-(r-1) >= 1)
// 			evalpoints.insert(arr[i]-(r-1));
// 	}
// 	for(int i=0; i<k; i++){
// 		cin >> prob[i];
// 	}
// 	// debug(prob[0]);
// 	vector<mint> evalpts;
// 	for(auto x: evalpoints)
// 		evalpts.push_back(x);


// 	vector<mint> yval, xval;
// 	for(int i=0; i<=r+1; i++){
// 		yval.push_back(C(i+r, r));
// 		xval.push_back(i+1);
// 	}

// 	Poly<mint> coeff = interpolate(xval, yval);

// 	// for(auto x: coeff){
// 	// 	cout << x << " ";
// 	// }
// 	// cout << "\n";

// 	// print(evalpts);
// 	// evalpts.resize(xval.size(), 0);

// 	// auto ncrvals = coeff.eval(evalpts);

// 	// for(auto x: evalpts){
// 	// 	cout << x << " ";
// 	// }
// 	// cout << "\n";
	
// 	// Scanner sc(stdin);
// 	// Printer pr(stdout);
	
// 	// int n;sc.read(n);
// 	// int m;sc.read(m);
// 	// poly c(n);
// 	// rep(i,n)sc.read(c[i].v);
// 	// vc<mint> p(m);
// 	// rep(i,m)sc.read(p[i].v);
	
// 	// auto ans=multieval(c,p);
// 	// rep(i,m){
// 	// 	pr.write(ans[i].v);
// 	// 	if(i+1<m)pr.write(' ');
// 	// 	else pr.write('\n');
// 	// }
// }
