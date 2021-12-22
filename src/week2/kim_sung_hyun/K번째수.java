import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int i = 0; i <commands.length ; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            int f = commands[i][0]-1;
            int l = commands[i][1]-1;
            int target = commands[i][2]-1;
            for (int j = f; j <= l; j++) {
                temp.add(array[j]);
            }
            Collections.sort(temp);
            System.out.println(temp.size());
            answer[i] = temp.get(target);
        }

        return answer;
    }
}