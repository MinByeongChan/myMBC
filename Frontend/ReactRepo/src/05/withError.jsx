import React, { Component } from "react";
import withStyle, { css, withStyles } from "../04/withStyles";

// 다중 커링으로 하이어오더 컴포넌트 반환.
export default function (defaultMessage) {
  return (WrappedComponent) => {
    const { displayName, name: componentName } = WrappedComponent;
    const WrappedComponentName = displayName || componentName;

    function ComponentWithError({ hasError, errorMessage, styles, ...props }) {
      return (
        <React.Fragment>
          <WrappedComponent {...props} />
          {hasError && <div {...css(styles.error)}>{errorMessage}</div>}
        </React.Fragment>
      );
    }
    ComponentWithError.defaultProps = {
      errorMessage: defaultMessage,
    };

    ComponentWithError.displayName = `withError(${WrappedComponentName})`;
    return withStyles(({ color }) => ({
      error: {
        color: color.error,
      },
    }))(ComponentWithError);
  };
}
