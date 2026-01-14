#include<bits/stdc++.h>
using namespace std;

int findLeft(vector<int>& v, int x){
    int l= 0;
    int r=v.size()-1;
    int res = -1;

    while(l <= r){
        int mid = (l+r)/2;
        if(v[mid] >=x){
            if(v[mid]==x)res = mid;
            r = mid -1;
        }else{
            l = mid +1;
        }
    }
    return res;
}

int findRight(vector<int>& v, int x){
    int l= 0;
    int r=v.size()-1;

    int res = -1;

    
    while(l <= r){
        int mid = (l+r)/2;
        if(v[mid] <=x){
            if(v[mid]==x)res = mid;
            l = mid +1;
        }else{
            r = mid -1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    cin >> m;
    while(m--){
        int x;
        cin >> x;

        int left = findLeft(v,x);
        if(left == -1) {
            cout << 0 << ' ';
            continue;
        }

        int right = findRight(v,x);
        cout << right - left + 1 << " ";
    }
    return 0;
}

//-10 -10 2 3 3 6 7 10 10 10
