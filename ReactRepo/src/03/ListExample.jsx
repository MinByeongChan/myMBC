import React from "react";

class ListExample extends React.PureComponent {
  render() {
    const todoList = [
      { taskName: "빨래하기", finished: false },
      { taskName: "공부하기", finished: true },
    ];

    const todos = todoList.map((todo) => <div>{todo.taskName}</div>);

    return [1, 2, 3].map((num) => (
      <input
        type="radio"
        name="option1"
        key={"$(num)"}
        value={num}
        label={"${num} 개"}
      />
    ));
    //(
    // <div>
    //   {todoList.map((todo) => (
    //     <div key={todo.taskName}>{todo.taskName}</div>
    //   ))}

    // </div>

    //);
  }
}

export default ListExample;
