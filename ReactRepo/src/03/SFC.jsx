import React, { Component } from 'react';
import propTypes from 'prop-types';

function SFC(props, context) {
  const { somePropValue } = props;
  const { someContextValue } = context;
  return <h1>Hello, {somePropValue}</h1>;
}

SFC.prototype = { somePropValue: propTypes.any };
SFC.defaultProps = { somePropValue: 'default value' };

export default SFC;
