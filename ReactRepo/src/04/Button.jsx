import React, { PureComponent } from "react";
import propTypes from "prop-types";
import withStyles, { css } from "./withStyles";

class Button extends PureComponent {
  render() {
    const {
      children,
      disabled,
      styles,
      large,
      xlarge,
      small,
      xsmall,
      secondary,
      primary,
      onPress,
    } = this.props;

    return (
      <div>
        <button
          {...css(
            styles.default,
            xsmall && styles.xsmall,
            small && styles.small,
            large && styles.large,
            xlarge && styles.xlarge,
            secondary && styles.secondary,
            primary && styles.primary
          )}
          onClick={onPress}
        >
          {children}
        </button>
      </div>
    );
  }
}

Button.propTypes = {
  children: propTypes.node.isRequired,
  xsmall: propTypes.bool,
  small: propTypes.bool,
  large: propTypes.bool,
  xlarge: propTypes.bool,
  secondary: propTypes.bool,
  primary: propTypes.bool,
  onPress: propTypes.func,
};

// undefined 오류 발생하는 것을 방지!
Button.defaultProps = {
  onPress: () => {},
  xsmall: false,
  small: false,
  large: false,
  xlarge: false,
  secondary: false,
  primary: false,
};

export default withStyles(({ color, size, unit, responsive }) => ({
  default: {
    border: 1,
    borderStyle: "solid",
    borderColor: color.default,
    borderRadius: 2,
    color: color.default,
    fontSize: size.md,
    padding: unit * 2,
    cursor: "pointer",
    [responsive.small]: {
      width: "100%",
    },
  },
  xlarge: {
    fontSize: size.xg,
  },
  large: {
    fontSize: size.lg,
  },
  small: {
    fontSize: size.sm,
    padding: unit,
  },
  xsmall: {
    fontSize: size.xs,
    padding: unit,
  },
  primary: {
    color: color.white,
    borderColor: color.primary,
    backgroundColor: color.primary,
  },
  secondary: {
    borderColor: color.secondary,
    color: color.secondary,
  },
}))(Button);
