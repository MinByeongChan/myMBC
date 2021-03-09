import React, { Component } from 'react';
import propTypes from 'prop-types';

class ChildProperty extends Component {
  render() {
    const { objValue, requiredStringValue } = this.props;
    return <div>{this.props.children[1]}</div>;
  }
}

ChildProperty.propTypes = {
  children: propTypes.node,
};

export default ChildProperty;
