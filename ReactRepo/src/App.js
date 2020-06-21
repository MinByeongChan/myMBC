import React from "react";

//import "./App.css";
import TodaysPlan from "./03/TodaysPlan";
import MyComponent from "./03/MyComponent";
import PropComponenet from "./03/PropsComponenet";
import ChildComponent from "./03/ChildComponent";
import BooleanComponent from "./03/BooleanComponent";
import ChildComponent2 from "./03/ChildComponent2";

function App() {
  const arr = [1, 2, 3];
  const numb = 1;
  const obj1 = { name: "MBC", age: 26 };
  const func = () => {
    console.log("message");
  };
  return (
    <div className="body">
      <ChildComponent
        boolValue={false}
        numValue={numb}
        arrayValue={arr}
        objValue={obj1.name}
        funcValue={func}
      />
      <BooleanComponent bored />
      <ChildComponent2 objValue={{ age: 20 }} requiredStringValue="String" />
    </div>
  );
}

export default App;
