import React, { Component } from "react";
import propTypes from "prop-types";

class Counter2 extends Component {
  render() {
    return (
      <div>
        현재 카운트 : {this.props.count}
        <button onClick={() => this.props.onAdd()}>카운트 증가</button>
      </div>
    );
  }
}

Counter2.propTypes = {
  count: propTypes.number,
  onAdd: propTypes.func,
};

export default Counter2;
