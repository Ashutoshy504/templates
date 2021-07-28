#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define M 1000000007
void dfs (vector<vector<int >> &A , int i , int j , int n , int m  , vector<vector<bool >> &vis , int* cur){
    vis[i][j] = true;
    for(int x = i-1 ; x <= i+1 ; x++){
        for(int y = j-1 ; y <= j+1 ; y++ ){
            if(x >= 0 and y >=0 and x  < n and y < m){
                if( !(vis[x][y]) and A[x][y]){
                    *cur = *cur +1;
                  dfs(A , x , y , n , m , vis ,cur);
                }
            }
        }
    }
}
int main()
{
    fast
    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n>> m;
        vector<vector<int >> A(n , vector<int>(m,0));
        for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < m ; j++)
        cin >> A[i][j];
        vector<vector<bool >> vis(n , vector<bool>(m,false));
        int cur = 0  , ov_max = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m  ;j++){
                if(A[i][j] and !(vis[i][j])){
                    cur = 1;
                    dfs(A , i , j , n , m , vis ,&cur);
                    ov_max = max(ov_max , cur);
                }
            }
        }
        cout << ov_max << "\n";
    }
    return 0;
}
