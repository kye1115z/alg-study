//해당 문제 인덱스 별로 a[나]보다 큰애들을 collection에 집어넣기
//그 중 제일 큰 인덱스를 출력
//우선순위 큐를 사용하여 제일 큰 숫자가 top로 오게 하고
//우선순위 큐의 top보다 큰 인덱스가 뒤에 올경우 priority_queue에 삽입
//priority_queue의 인덱스가 가장 큰 애를 출력
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int a[n];
    priority_queue<int> pq[n];
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    //각 인덱스별로 가장 긴 증가하는 부분 수열 pq에 저장
    for(int i=0; i<n;i++){
        pq[i].push(a[i]); 
        for(int j=i;j<n;j++){
            if(pq[i].top()<a[j]){
                pq[i].push(a[j]);
            }
        }
    }

    //저장된 pq[n]중에 제일 큰 사이즈의 pq[i]와 i를 찾는과정
    int res=pq[0].size();
    int index;
    for(int i=1; i<n;i++){
        //pq[i].size()의 index를 저장
        if(res<=pq[i].size()){
            res=pq[i].size();
            index = i;
        }
    }

    //pq는 큰 순서대로 뺴내다보니 벡터에 오름차순으로 넣기위한 작업
    vector<int> v;
    for(int i=0; i<pq[index].size();i++){
        //벡터에 pq.top를 빼면서 vector에 저장
        int temp = pq[index].top();
        v.push_back(temp);
        pq[index].pop();
    }
    //오름차순
    sort(v.begin(),v.end());

    //제일 큰 사이즈 제출
    cout<< res << "\n";
    //그 안에 내용들 출력
    for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    
    return 0;
}
