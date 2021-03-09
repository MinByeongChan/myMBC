import React, { Component } from "react";
import PropTypes from "prop-types";
import Button from "../04/Button";
import { Consumer } from "./LoadingProviderWithNewContext";

function ButtonWithNewConsumer({ children }) {
  return (
    <React.Fragment>
      {/* // 공급자로부터 받은 프로퍼티를 적용하여 Button에 전달 */}
      <Consumer
        children={(value) => (
          <Button onPress={() => value.setLoading("loading", !value.loading)}>
            {value.loading ? "로딩 중" : children}
          </Button>
        )}
      />

      {/* // 공급자로부터 받은 프로퍼티를 적용하여 Button에 전달 */}
      <Consumer
        children={({ loading2 = false, setLoading }) => (
          <Button onPress={() => setLoading("loading2", !loading2)}>
            {loading2 ? "로딩 중" : children}
          </Button>
        )}
      />

      {/* // 공급자로부터 받은 프로퍼티를 적용하여 Button에 전달 */}
      <Consumer
        children={({ loading = false, loading2 = false }) => (
          <Button>{loading && loading2 ? "로딩 중" : children}</Button>
        )}
      />
    </React.Fragment>
  );
}

export default ButtonWithNewConsumer;
