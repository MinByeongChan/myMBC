import React, { Component } from "react";

// export default function withLoading(
//   WrappedComponent,
//   loadingMessage = "로딩 중"
// ) {
//   const { displayName, name: componentName } = WrappedComponent;
//   const WrappedComponentName = displayName || componentName;

//   function WithLoading({ isLoading, ...otherProps }) {
//     if (isLoading) return loadingMessage;

//     return <WrappedComponent {...otherProps} />;
//   }

//   WithLoading.displayName = `withLoading(${WrappedComponentName})`;
//   return WithLoading;
// }

// 다중 커링으로 하이어오더 컴포넌트 반환.
export default function withLoading(loadingMessage = "로딩 중") {
  return function withLoading(WrappedComponent) {
    const { displayName, name: componentName } = WrappedComponent;
    const WrappedComponentName = displayName || componentName;

    function WithLoading({ isLoading, ...otherProps }) {
      if (isLoading) return loadingMessage;

      return <WrappedComponent {...otherProps} />;
    }

    WithLoading.displayName = `withLoading(${WrappedComponentName})`;
    return WithLoading;
  };
}
