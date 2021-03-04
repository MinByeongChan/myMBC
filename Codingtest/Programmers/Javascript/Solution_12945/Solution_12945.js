let dp = new Array(100000);
for (let i = 0; i < 100000; ++i) dp[i] = 0;

function fibonacci(n) {
  if (n == 1) return 1;
  if (n == 2) return 1;
  if (n == 3) return 2;
  if (dp[n] != 0) return dp[n];
  return (dp[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1234567);
}
function solution(n) {
  var answer = fibonacci(n) % 1234567;
  console.log("fibonacci ", answer);

  return answer;
}

const n = 5;
const result = solution(n);

console.log(result);
