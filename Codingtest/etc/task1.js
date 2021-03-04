let result = 0;

const makeStr = (S) => {
  let arr = S.split("");
  for (let i = 0; i < arr.length; i++) {
    let balloon = "BALLOON";
    let b_arr = balloon.split("");

    for (let j = 0; j < balloon.length; j++) {
      if (arr[i] === balloon[j]) {
        arr[i] = "";
        b_arr[i] = "";
        break;
      }
    }
  }

  let rtnVal = "";
  for (let i = 0; i < arr.length; i++) {
    rtnVal += arr[i];
  }

  return rtnVal;
};

const validate = (str) => {
  console.log("str", str);
  let balloon = "BALLOON";
  let b_arr = balloon.split("");
  let cnt = 7;

  for (let i = 0; i < str.length; i++) {
    for (let j = 0; j < balloon.length; j++) {
      if (str[i] == balloon[j]) {
        cnt--;
        b_arr[j] = "";
        break;
      }
    }
  }
  if (cnt === 0) return true;
  else return false;
};

let s = "BAOOLLNNOLOLGBAX";
let str = s;

while (true) {
  if (!validate(str)) break;
  str = makeStr(str);
  result++;
  console.log("str", str);
}

console.log("result " + result);
