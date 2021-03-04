function solution(numbers) {
  const NUM_LEN = numbers.length;

  let set = new Set();

  for (let i = 0; i < NUM_LEN; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      let a = parseInt(numbers[i] + numbers[j]);
      set.add(a);
    }
  }

  return Array.from(set).sort((a, b) => {
    return a - b;
  });
}

const numbers = [5, 0, 2, 7];
solution(numbers);
