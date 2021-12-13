import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<>();

        //굳이 remove안하고 value 값을 조작하는 이유 = 동명이인이 있을 수 있다라는 조건 때문에

        for (String part : participant)
            map.put(part,map.getOrDefault(part,0)+1); //동명이인 존재 때문에 getOrDefault 함수를 쓰는것

        for (String part : completion)
            map.put(part,map.get(part)-1);


        //entrySet
        for (Map.Entry<String, Integer> entry : map.entrySet())
            if(entry.getValue() != 0)
                answer = entry.getKey();

        return answer;
    }
}