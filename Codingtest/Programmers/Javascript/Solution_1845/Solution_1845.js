function solution(nums) {
  var answer = 0;
  var half = nums.length / 2;

  let s = new Set();
  for (let i in nums) {
    s.add(nums[i]);
  }
  console.log("s.size", s.size);
  if (s.size <= half) {
    // answer = half;
    answer = s.size;
  } else {
    answer = half;
  }

  return answer;
}

// const nums = [3, 1, 2, 3];
const nums = [3, 3, 3, 2, 2, 4];
// const nums = [3, 3, 3, 2, 2, 2];

const result = solution(nums);
console.log(result);
