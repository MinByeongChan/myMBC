import React, { Component } from "react";

export default function withHoc(WrappedComponent) {
  const { displayName, name } = WrappedComponent;
  const WrappedComponentName = displayName || name;

  return class withHoc extends Component {
    static displayName = `withHoc(${WrappedComponentName})`;
    render() {
      return <WrappedComponent {...this.props} />;
    }
  };
}
