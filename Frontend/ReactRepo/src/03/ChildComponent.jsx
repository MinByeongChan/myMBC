import React, { Component } from "react";
import propTypes from "prop-types";

class ChildComponent extends Component {
  render() {
    const {
      boolValue,
      numValue,
      arrayValue,
      objValue,
      nodeValue,
      funcValue,
    } = this.props;
    return (
      <div>
        <span>bool : {boolValue}</span>
        <span>num : {numValue}</span>
        <span>array : {arrayValue}</span>
        <span>obj : {objValue}</span>
        <span>node : {nodeValue}</span>
        <span>func : {funcValue}</span>
      </div>
    );
  }
}

ChildComponent.propTypes = {
  boolValue: propTypes.bool,
  numValue: propTypes.number,
  arayValue: propTypes.arrayOf(propTypes.number),
  objValue: propTypes.object,
  nodeValue: propTypes.node,
  funcValue: propTypes.func,
};

export default ChildComponent;
