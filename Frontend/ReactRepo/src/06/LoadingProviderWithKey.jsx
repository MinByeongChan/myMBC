import React from "react";
import PropTypes from "prop-types";
import { render } from "react-dom";

export const DEAULT_KEY = "defaultLoadingKey";
export const contextPropTypes = {
  loading: PropTypes.bool,
  setLoading: PropTypes.func,
};

export default (contextKey = DEAULT_KEY) => {
  class LoadingProvider extends React.Component {
    constructor(props) {
      super(props);

      this.state = { loading: false };
      this.setLoading = this.setLoading.bind(this);
    }

    getChildContext() {
      return {
        [contextKey]: {
          loading: this.state.loading,
          setLoading: this.setLoading,
        },
      };
    }

    setLoading(loading) {
      this.setState({ loading });
    }

    render() {
      return this.props.children;
    }
  }

  LoadingProvider.childContextTypes = {
    [contextKey]: contextPropTypes,
  };

  return LoadingProvider;
};
