const checkArr = (arr, LCM) => {
  console.log("LCM", LCM);
  for (let i = 0; i < arr.length; i++) {
    if (LCM % arr[i] != 0) {
      return false;
    }
  }
  return true;
};

const getMn = (arr) => {
  let mn = 10000000;
  for (let i in arr) {
    if (arr[i] < mn) mn = arr[i];
  }

  return mn;
};

function solution(arr) {
  var answer = 1;
  let LCM = 2;

  while (true) {
    if (checkArr(arr, LCM)) {
      answer = LCM;
      break;
    }
    LCM++;
  }

  return answer;
}

const arr = [2, 6, 8, 14];
// const arr = [1, 2, 3];

const result = solution(arr);
console.log(result);
