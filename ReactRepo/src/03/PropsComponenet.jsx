import React, { Component } from "react";
import PropTypes from "prop-types";

class PropsComponenet extends Component {
  render() {
    return <div className="message-container">{this.props.name}</div>;
  }
}

export default PropsComponenet;
