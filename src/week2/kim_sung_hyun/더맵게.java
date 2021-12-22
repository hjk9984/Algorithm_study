import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < scoville.length; i++) {
            pq.offer(scoville[i]);
        }

        while(pq.peek() < K)
        {
            if(pq.size() < 2) return -1;
            int a = pq.poll();
            int b = pq.poll();
            answer++;
            int nfood = a+(b*2);
            pq.offer(nfood);
        }

        return answer;
    }
}