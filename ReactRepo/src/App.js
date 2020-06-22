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

function App() {
  return (
    <div className="body">
      <ChildProperty>
        <span>안뇽 자식노드1</span>
        <span>안뇽 자식노드2</span>
        <span>안뇽 자식노드3</span>
        <span>안뇽 자식노드4</span>
        <span>안뇽 자식노드5</span>
      </ChildProperty>
      <StateExample />
    </div>
  );
}

export default App;
