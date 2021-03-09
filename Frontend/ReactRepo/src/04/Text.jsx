import React, { PureComponent } from "react";
import propTypes from "prop-types";
import withStyles, { css } from "./withStyles";

class Text extends PureComponent {
  render() {
    const {
      children,
      styles,
      large,
      xlarge,
      small,
      xsmall,
      secondary,
      primary,
    } = this.props;

    return (
      <div>
        <span
          {...css(
            styles.default,
            xsmall && styles.xsmall,
            small && styles.small,
            large && styles.large,
            xlarge && styles.xlarge,
            secondary && styles.secondary,
            primary && styles.primary
          )}
        >
          {children}
        </span>
      </div>
    );
  }
}

Text.propTypes = {
  children: propTypes.node.isRequired,
  xsmall: propTypes.bool,
  small: propTypes.bool,
  large: propTypes.bool,
  xlarge: propTypes.bool,
  secondary: propTypes.bool,
  primary: propTypes.bool,
};

export default withStyles(({ color, size }) => ({
  default: {
    color: color.primary,
    fontSize: size.md,
  },
  xlarge: {
    fontSize: size.xg,
  },
  large: {
    fontSize: size.lg,
  },
  small: {
    fontSize: size.sm,
  },
  xsmall: {
    fontSize: size.xs,
  },
  primary: {
    color: color.primary,
  },
  secondary: {
    color: color.secondary,
  },
}))(Text);
