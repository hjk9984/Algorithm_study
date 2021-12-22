import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> small = new PriorityQueue<>();
        PriorityQueue<Integer> big  = new PriorityQueue<>(Collections.reverseOrder());
        int cnt= 0;
        for (int i = 0; i < operations.length; i++) {
            String divStr[] = operations[i].split(" ");
            if(divStr[0].equals("I"))
            {
                big.offer(Integer.parseInt(divStr[1]));
                small.offer(Integer.parseInt(divStr[1]));
                cnt++;
            }
            else
            {
                if(divStr[1].equals("1"))
                    big.poll();
                else
                    small.poll();
                if(!big.isEmpty())
                    cnt--;
            }
            if(cnt == 0)
            {
                while(!big.isEmpty())
                    big.poll();
                while(!small.isEmpty())
                    small.poll();
            }
        }
        if(cnt <= 0) return answer;

        answer[0] = big.peek();
        answer[1] = small.peek();

        return answer;
    }
}