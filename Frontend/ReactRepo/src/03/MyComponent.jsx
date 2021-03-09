import React, { Component } from "react";

class MyComponent extends Component {
  render() {
    const name1 = this.props.name1;
    const name2 = this.props.name2;
    return (
      <div>
        <div>
          <span>{name1}</span>
        </div>

        <div>
          <span>{name2}</span>
        </div>
      </div>
    );
  }
}

export default MyComponent;
