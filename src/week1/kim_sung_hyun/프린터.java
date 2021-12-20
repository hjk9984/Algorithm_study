import java.util.*;

class Solution {
        static boolean check[];

    public int solution(int[] priorities, int location) {
          int answer = 0;
        check = new boolean[100];
        LinkedList<int []> queue = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            queue.offer(new int[] {priorities[i],i});
        }

        while(!queue.isEmpty())
        {
            boolean flag = false;
            int temp[] = queue.poll(); //자바의 poll은 pop과 front를 합침
            int prioritie = temp[0];
            int num = temp[1];

            for (int i = 0; i < priorities.length; i++) { //현재 출력될 문서보다 중요한거 찾는 로직
                if(!check[i] && prioritie < priorities[i])
                {
                    queue.offer(new int[]{temp[0],temp[1]});
                    flag = true;
                    break;
                }
            }

            if(!flag) //인쇄된경우
            {
                check[num] = true;
                if(location == num) //만약 location과 같다면
                    break;
            }

        }
        return priorities.length - queue.size();
    }
}