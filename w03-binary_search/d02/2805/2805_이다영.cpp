// // 나무의 개수=N, 가져갈 나무=M(미터)
// // 1. 배열 정렬
// // 2. 배열 모두 더하기
// // 3. N이하의 수 중 가장 먼저 2의 값과 나누어 떨어지는 수 구하기
// // 4. 2번 값/3의 값 출력

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int N;
//     int M;
//     int sum=0;
//     int getTree;

//     scanf("%d %d", &N, &M);

//     int trees[1000000];

//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &trees[i]);
//          sum+=trees[i];
//     }

// int getHeight(){
// for(int j=M;j>=M;j--){
//         if(sum%j==0){
//             getTree=j;
//             break;
//         }
//     }
//     return getTree;
// }


//     printf("%d",getTree);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int M;
    int max=0;
    int sum=0;
    int maxTreeHeight=0;

    scanf("%d %d",&N,&M);
    int trees[1000000];

    for(int i=0;i<N;i++){
        scanf("%d",&trees[i]);
        if(trees[i]>max){
            max=trees[i];
        }
    }
    
    int left=0;
    int right=max;


    while(left<=right){
        int mid=(left+right)/2;

    for(int i=0;i<N;i++){
        sum+=trees[i]-mid;
    }

    if(sum<M){
        mid=mid-1;
    } else{ 
        right=mid-1;
    }
    }

    printf("%d",maxTreeHeight);
    return 0;
}
