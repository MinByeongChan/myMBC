package Java.Programmers.Solution_12935;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Solution_12935 {
    static int MAX = 1000000;

    public static void main(String[] args) {
        int[] arr = { 4, 0, 2, 1 };
        int mn = MAX;
        for (int i : arr) {
            if (mn > i)
                mn = i;
        }
        final int mn_final = mn;

        List<Integer> intList = Arrays.stream(arr).boxed().collect(Collectors.toList());
        List<Integer> list = intList.stream().filter(data -> data != mn_final).collect(Collectors.toList());

        for (Integer i : list) {
            System.out.print(i + " ");
        }

        System.out.println("Integer List => int Array");

        int[] array = list.stream().mapToInt(i -> i).toArray();

        for (Integer i : array) {
            System.out.print(i + " ");
        }

    }
}
