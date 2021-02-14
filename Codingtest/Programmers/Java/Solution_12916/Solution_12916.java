package Java.Programmers.Solution_12916;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12916 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        boolean answer = false;
        int pNum = 0;
        int yNum = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'y' || s.charAt(i) == 'Y') {
                yNum++;
            } else if (s.charAt(i) == 'p' || s.charAt(i) == 'P') {
                pNum++;
            }
        }

        if (pNum == yNum) {
            answer = true;
        } else {
            answer = false;
        }

        System.out.println(answer);
    }
}
