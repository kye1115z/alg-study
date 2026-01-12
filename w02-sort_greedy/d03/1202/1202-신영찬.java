import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[][] gemInfo = new int[N][2];
        int[] bagMaxWeights = new int[K];
        
        //TODO : 데이터 파싱
        for (int i = 0; i < N; i++) {
          st = new StringTokenizer(br.readLine());
          gemInfo[i][0] = Integer.parseInt(st.nextToken());
          gemInfo[i][1] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 0; i < K; i++) {
          bagMaxWeights[i] = Integer.parseInt(br.readLine());
        }
        
        //TODO : 보석, 가방 오름차순 정렬
        Arrays.sort(gemInfo, (o1, o2) -> o1[0] - o2[0]);
        Arrays.sort(bagMaxWeights);
        
        //TODO : 우선순위 큐 생성, 현재 가방 무게 이하의 보석 모두 집어넣기
        //가치 기준으로 우선순위를 정하기 때문에 내림차순 정렬이 필요
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int gemIndex = 0;
        long totalValue = 0;
        
        for (int i = 0; i < K; i++) {
          //현재 가방의 최대 무게 이하인 보석들을 모두 pq에 넣는다
          //가방에는 하나의 보석만 들어가기 때문에 가장 높은 우선순위를 가진 보석만 들어가면 됨
          //다음 가방으로 넘어가더라도 이전에 있던 고가치의 보석은 pa에 이미 담겨있음
          //가치 기준 내림차순 정렬이 되어 들어가기 때문에 poll을 통해 하나만 뽑으면 된다
          while(gemIndex < N && gemInfo[gemIndex][0] <= bagMaxWeights[i]) {
            pq.add(gemInfo[gemIndex][1]);
            gemIndex++;
          }
          
          if(!pq.isEmpty()) {
            totalValue += pq.poll();
          }
        }
        bw.write(String.valueOf(totalValue));
        bw.flush();
        br.close();
  }
}