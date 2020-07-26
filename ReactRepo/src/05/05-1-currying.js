function multiply(a, b) {
  return a * b;
}

function multiplyTwo(a) {
  return multiply(a, 2);
}

function multiplyX(x) {
  return function (a) {
    return multiply(a, x);
  };
}

// consnt multiplyX = x => a => multiply(a, x);

const multiplyThree = multiplyX(3);
const multiplyFour = multiplyX(4);

const result1 = multiplyThree(3);
// const result1 = multiplyX(3)(3);
const result2 = multiplyFour(3);
// const result2 = multiplyX(4)(3);

// 커링한번 더 사용해 보기
const equation = (a, b, c) => (x) => x * a * b + c;
const formula = equation(2, 3, 4);
const x = 10;
const result = formula(x);

const multiply = (a, b) => a * b;
const add = (a, b) => a + b;

const multiplyX = (x) => (a) => multiply(a, 2);
const addX = (x) => (a) => add(a, x);

const addFour = addX(4);
const multiplyTwo = multiplyX(2);
const multiplyThree = multiplyX(3);
const formula = (x) => addFour(multiplyThree(multiplyTwo(x)));
