import React, { Component } from "react";

class TickTok extends Component {
  render() {
    return (
      <div>
        <h1>Hello, React!</h1>
        <h2>It is {new Date().toLocaleTimeString()}</h2>
      </div>
    );
  }
}
setInterval(TickTok, 1000);

export default TickTok;
