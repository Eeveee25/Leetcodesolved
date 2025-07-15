import java.util.*;

public class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> roman = new HashMap<>();
        roman.put('I', 1);
        roman.put('V', 5);
        roman.put('X', 10);
        roman.put('L', 50);
        roman.put('C', 100);
        roman.put('D', 500);
        roman.put('M', 1000);

        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            int val = roman.get(s.charAt(i));

            // Look ahead to see if a subtractive pair is present
            if (i < s.length() - 1 && val < roman.get(s.charAt(i + 1))) {
                total -= val;
            } else {
                total += val;
            }
        }

        return total;
    }
}
