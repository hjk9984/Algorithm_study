import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        for (int i = 0; i < citations.length; i++) {
            int temp = citations.length-i;

            if(citations[i]>=temp)
            {
                answer= temp;
                break;
            }
        }
        return answer;
    }
}