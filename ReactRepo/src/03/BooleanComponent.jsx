import React, { Component } from "react";

class BooleanComponent extends Component {
  render() {
    const message = this.props.bored ? "놀러 가자" : "하던일 마무으리";

    return <div>{message}</div>;
  }
}

export default BooleanComponent;
