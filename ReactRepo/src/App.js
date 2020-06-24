import React from 'react';

//import "./App.css";
import TodaysPlan from './03/TodaysPlan';
import MyComponent from './03/MyComponent';
import PropComponenet from './03/PropsComponenet';
import ChildComponent from './03/ChildComponent';
import BooleanComponent from './03/BooleanComponent';
import ChildComponent2 from './03/ChildComponent2';
import DefaultPropsComponent from './03/DefaultPropsComponent';
import ChildProperty from './03/ChildProperty';
import StateExample from './03/StateExample';
import ForceUpdateExample from './03/ForceUpdateExample';
import Counter from './03/Counter';
import NewCounter from './03/NewCounter';

function App() extends React.Component{
  constructor(props){
    super(props);
    this.state = {count: 10};
    this.resetCount = this.resetCount.bind(this);
  }

  resetCount(){
    this.setState(({count}) => ({count: count+10}));
  }
  return (
    <div className="body">
      <div><Counter count={this.state.count}/></div>

    </div>
  );
}

export default App;
