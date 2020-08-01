import React, { Component } from "react";
import { render } from "react-dom";
const { Provider, Consumer } = React.createContext({});

export { Consumer };

// createContext를 사용하여 만든 공급자
export default class LoadingProvider extends React.PureComponent {
  constructor(props) {
    super(props);

    this.state = {};
    this.setLoading = this.setLoading.bind(this);
  }

  setLoading(key, value) {
    const newState = { [key]: value };
    this.setState(newState);
  }

  render() {
    const context = {
      ...this.state,
      setLoading: this.setLoading,
    };

    return <Provider value={context}>{this.props.children}</Provider>;
  }
}
