import React, { Component } from "react";
import propTypes from "prop-types";

export default (WrapperComponent) => {
  const { displayName, name: ComponentName } = WrapperComponent;
  const wrappedComponentName = displayName || ComponentName;

  function WithLoadingContext(props, context) {
    const { loading, setLoading } = context;

    // wrapperComponent 에 전달하는 과정들이 핵심!!
    return (
      <WrapperComponent {...props} loading={loading} setLoading={setLoading} />
    );
  }

  WithLoadingContext.displayName = `withLoadingContext(${wrapperComponentName})`;
  WithLoadingContext.contextTypes = {
    loading: propTypes.bool,
    setLoading: propTypes.func,
  };

  return WithLoadingContext;
};
