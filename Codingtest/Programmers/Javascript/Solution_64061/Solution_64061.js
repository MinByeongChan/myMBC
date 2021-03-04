function solution(board, moves) {
  let st = [];
  const HEIGHT = board.length;
  let answer = 0;

  for (let i = 0; i < moves.length; i++) {
    let position = moves[i] - 1;
    for (let j = 0; j < HEIGHT; j++) {
      if (board[j][position] != 0) {
        if (st.length == 0) {
          st.push(board[j][position]);
        } else {
          if (st[st.length - 1] == board[j][position]) {
            st.pop();
            answer += 2;
          } else {
            st.push(board[j][position]);
          }
        }

        board[j][position] = 0;
        break;
      }
    }
  }

  return answer;
}

// const board = [
//   [0, 0, 0, 0, 0],
//   [0, 0, 1, 0, 3],
//   [0, 2, 5, 0, 1],
//   [4, 2, 4, 4, 2],
//   [3, 5, 1, 3, 1],
// ];
const board = [
  [0, 0, 0, 0, 0],
  [0, 0, 1, 0, 3],
  [0, 2, 5, 0, 1],
  [4, 2, 4, 4, 2],
  [3, 5, 1, 3, 1],
];

// const moves = [1, 5, 3, 5, 1, 2, 1, 4];

const moves = [1, 4, 5, 3, 5];

const result = solution(board, moves);
console.log(result);
