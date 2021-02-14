#include<iostream>
#include <string>
#include <vector>

using namespace std;

//점검 함수
bool Check(string skill, string skill_tree) {
	int skillLen = skill.length(); // skill 길이
	int skill_treeLen = skill_tree.length(); //skill_trees 길이
	int idx = 0; // skill길이만큼 점검하는 인덱스
	for (int i = 0; i < skill_treeLen; i++) {
		for (int j = 0; j < skillLen; j++) {
			//매번 skill안에 있는 인자들을 모두 점검
			//idx가 기준점이 되고, idx와 j의 일치 여부에 따라 점검이 진행됨
			if (skill_tree[i] == skill[j] && idx != j) { 
				return false;
			}
			else if (skill_tree[i] == skill[j] && idx == j) { // 스킬을 제대로 찍고 있으면 idx 증가
				idx++;
			}
		}
	}
	return true;
}


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	int SIZE = skill_trees.size();

	for (int i = 0; i < SIZE; i++) {
		//반환값이 true이면 answer 증가
		if (Check(skill, skill_trees[i])) answer++;
	}


	return answer;
}

int main() {
	string skill = "CBD";
	vector<string> st;

	st.push_back("BACDE");
	st.push_back("CBADF");
	st.push_back("AECB");
	st.push_back("BDA");

	cout << solution(skill, st) << endl;

	return 0;
}