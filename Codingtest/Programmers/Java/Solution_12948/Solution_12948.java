package Java.Programmers.Solution_12948;

public class Solution_12948 {
    public static void main(String[] args) {
        String phone_number = "01033334444";
        String answer = "";

        for (int i = 0; i < phone_number.length() - 4; i++) {
            answer += "*";
        }

        System.out.print(answer + phone_number.substring(phone_number.length() - 4, phone_number.length()));

    }

}
