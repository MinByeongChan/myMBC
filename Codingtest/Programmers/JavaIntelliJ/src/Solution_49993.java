/*
*  @ 프로그래머스 솔루션
*  @ 문제 : 스킬트리
*  @ 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 스파크 → 힐링 → 라이트닝 볼트 → 썬더와 같은 스킬트리는 가능하지만, 썬더 → 스파크나 라이트닝 볼트 → 스파크 → 힐링 → 썬더와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.
* */

import java.util.ArrayList;

public class Solution_49993 {

    public static int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for (String s: skill_trees) {
            int pivot = 0;

            // 초기화
            ArrayList<Character> list = new ArrayList<>();
            for (int i=0; i<skill.length(); i++)
                list.add(skill.charAt(i));

            for(int i=0; i<s.length(); i++) {
                if(pivot == list.size()) break;
                if(s.charAt(i) == list.get(pivot)) {
                    pivot++;
                    continue;
                }

                for(int j=pivot; j<skill.length(); j++) {
                    if(s.charAt(i) == skill.charAt(j)){
                        pivot = -1;
                        break;
                    }
                }
                if(pivot == -1) break;
            }

            if(pivot != -1) answer++;


        }

        return answer;
    }

    public static void main(String[] args) {
        String skill = "CBD";
        String[] skill_trees = {"BACDE", "CBADF", "AECB", "BDA", "ASSDASAS", "ASASASWAQCSAASBASD"};

        int result = solution(skill, skill_trees);
        System.out.println("result "+ result);
    }
}
