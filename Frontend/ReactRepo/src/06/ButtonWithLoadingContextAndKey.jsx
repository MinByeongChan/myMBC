import React from "react";
import PropTypes from "prop-types";
import Button from "../04/Button";
import withLoadingContextAndKey, {
  loadingPropTypes,
} from "./withLoadingContextAndKey";

function ButtonWithLoadingContext({ children, loading, setLoading }) {
  return (
    <Button onPress={() => setLoading(!loading)}>
      {loading ? "로딩 중" : children}
    </Button>
  );
}

ButtonWithLoadingContext.propTypes = {
  ...loadingProptypes,
  children: PropTypes.string,
};

export const ButtonWithDefaultLoadingContext = withLoadingContextAndKey()(
  ButtonWithLoadingContext
);
export const ButtonWithLoading2Context = withLoadingContextAndKey("loading2")(
  ButtonWithLoadingContext
);
