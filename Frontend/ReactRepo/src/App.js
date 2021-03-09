import React from "react";
import propTypes from "prop-types";

//import "./App.css";
//import "./materialize.css";
import "./sass/materialize.scss";

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
import Counter from "./03/Counter";
import NewCounter from "./03/NewCounter";
import ListExample from "./03/ListExample";
import Counter2 from "./03/Counter2";
import Counter3 from "./03/Counter3";
import ScrollSpy from "./03/ScrollSpy";
import Input1 from "./03/Input1";

class App extends React.Component {
  // constructor(props) {
  //   super(props);

  //   this.state = {
  //     count: 1,
  //   };
  // }

  // increaseCount() {
  //   this.setState(({ count }) => ({ count: count + 1 }));
  // }

  render() {
    return (
      // <div className="body">
      //   <div>
      //     <ListExample />
      //   </div>
      // </div>
      // <Counter2
      //   count={this.state.count}
      //   onAdd={this.increaseCount.bind(this)}
      // />
      //<Input1 />
      <div>
        <nav>
          <div className="nav-wrapper">
            <div>두잇! 리액트 스타트!</div>
          </div>
        </nav>
        <h1>머티리얼 CSS</h1>
      </div>
    );
  }
}

export default App;
