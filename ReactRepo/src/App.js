import React from "react";

//import "./App.css";
import TodaysPlan from "./03/TodaysPlan";
import MyComponent from "./03/MyComponent";
import PropComponenet from "./03/PropsComponenet";
import ChildComponent from "./03/ChildComponent";
import BooleanComponent from "./03/BooleanComponent";
import ChildComponent2 from "./03/ChildComponent2";
import DefaultPropsComponent from "./03/DefaultPropsComponent";
import ChildProperty from "./03/ChildProperty";
import StateExample from "./03/StateExample";
import ForceUpdateExample from "./03/ForceUpdateExample";

function App() {
  return (
    <div className="body">
      <ChildProperty>
        <span>hi</span>
      </ChildProperty>
      <StateExample />
      <ForceUpdateExample />
    </div>
  );
}

export default App;
