public class Solution {
    public boolean isPalindrome(int x) {
        // Edge cases: negative number or ends with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            int lastDigit = x % 10;
            reversedHalf = reversedHalf * 10 + lastDigit;
            x = x / 10;
        }

        // For even-length: x == reversedHalf
        // For odd-length: x == reversedHalf / 10 (middle digit doesn’t matter)
        return x == reversedHalf || x == reversedHalf / 10;
    }
}
