import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        class cmp implements Comparator<String>{
            public int compare(String a, String b){
                return (b+a).compareTo(a+b);
            }
        }
        String answer = "";
        String [] nTostr = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            nTostr[i] = Integer.toString(numbers[i]);
        }
        Arrays.sort(nTostr,new cmp());
        if(nTostr[0].equals("0"))
            return "0";
        for (int i = 0; i < nTostr.length; i++) {
            answer+=nTostr[i];
        }

        return String.join("",nTostr);
    }
}