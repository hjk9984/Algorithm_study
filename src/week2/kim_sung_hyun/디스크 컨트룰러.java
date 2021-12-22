import java.util.ArrayList;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] work = new int[progresses.length];
        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            int val = (100 - progresses[i]) / speeds[i];
            if ((100 - progresses[i]) % speeds[i] != 0) // 안 나누어 떨어지면
                val += 1;
            work[i] = val;
        }

        int tmp = work[0];
        int cnt = 1;

        for (int i = 1; i < work.length; i++) {
            //전 작업이 안끝났을 경우
            if(tmp >= work[i])
                cnt++;
            else
            {
                list.add(cnt);
                tmp = work[i];
                cnt = 1;
            }
        }
        list.add(cnt);

        int[] answer = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
                
        
        return answer;
    }
}