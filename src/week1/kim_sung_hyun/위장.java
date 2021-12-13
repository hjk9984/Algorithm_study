import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> map = new HashMap<>();

        for(int i=0; i<clothes.length; i++)
        {
            String clothe = clothes[i][1];
            map.put(clothe,map.getOrDefault(clothe,0)+1);
        }


        Iterator<Map.Entry<String,Integer>> entries = map.entrySet().iterator();
        while(entries.hasNext())
        {
            Map.Entry<String,Integer> entry = entries.next();
            answer *=entry.getValue()+1;
        }

        //clothes.size + 각 옷 개수를 곱해야함

        return answer-1;
    }
}