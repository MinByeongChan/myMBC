import React, { Component } from "react";
import propTypes from "prop-types";

class ChildComponent2 extends Component {
  render() {
    const { objValue, requiredStringValue } = this.props;
    return (
      <div>
        <div>객체값 : {String(Object.entries(objValue))}</div>
        <div>필수값 : {requiredStringValue}</div>
      </div>
    );
  }
}

ChildComponent2.propTypes = {
  objValue: propTypes.shape({
    name: propTypes.string,
    age: propTypes.number,
  }),

  requiredStringValue: propTypes.string.isRequired,
};

export default ChildComponent2;
