import React, { Component } from "react";
import { DEFAULT_KEY, contextPropTypes } from "./LoadingProviderWithKey";

export const loadingPropTypes = contextPropTypes;

export default (contextKey = DEFAULT_KEY) => (WrappedComponent) => {
  const { displayName, name: componentName } = WrappedComponent;
  const WrappedComponentName = displayName || componentName;

  function WithLoadingContext(props, context) {
    const { loading, setLoading } = context[contextKey];
    return (
      <WrappedComponent {...props} loading={loading} setLoading={setLoading} />
    );
  }

  WithLoadingContext.displayName = `withLoadingContext(${WrappedComponentName})`;
  WithLoadingContext.contextPropTypes = {
    [contextKey]: contextPropTypes,
  };
  return WithLoadingContext;
};
