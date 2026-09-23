#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

void lap_day_0( string &a , string &b){
	while( a.length() < b.length() ) a = "0" + a ; 
	while( b.length() < a.length() ) b = "0" + b ; 
}

string cong(string a ,string b , int K){
	int n = a.length() ; 
	// ham co ban == 1
	if ( n == 1){
		int sum = a[0] - '0' + b[0] - '0' ; 
		string s = "" ;
		if ( sum >= K ){
			s += to_string( sum / K) ; 
			s += to_string( sum % K ) ; 
		}
		else{
			s += to_string(sum) ; 
		}
		return s ; 
	}
	int mid = n/2 ; 
	string a_dau = a.substr( 0 , n - mid ) ; 
	string a_cuoi = a.substr( n -mid) ;
	
	string b_dau = b.substr( 0 , n - mid ) ; 
	string b_cuoi = b.substr( n -mid) ;
	
	lap_day_0(a_dau , b_dau) ; 
	lap_day_0(a_cuoi,b_cuoi) ; 
	
	string dau = cong(a_dau , b_dau , K) ; 
	string cuoi = cong( a_cuoi , b_cuoi , K) ; 
	
	if ( cuoi.length() > mid ){
		string tmp = cuoi.substr( 0 , cuoi.length() - mid ) ; 
		cuoi = cuoi.substr( cuoi.length() - mid ) ; 
		lap_day_0(dau , tmp) ; 
		dau = cong(dau , tmp , K) ; 
	}
	return dau + cuoi ; 
}

void solve(){
	string a , b ; 
	int K ; 
	cin >> K  >> a >> b ; 
	lap_day_0(a,b) ;
	string kq = cong(a,b,K) ;  
	cout << kq << "\n" ; 
}

int main(){
	int t;
	cin >> t ; 
	while( t--){
	 	solve();
	}
	return 0 ; 
	
}