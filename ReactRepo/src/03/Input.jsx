import React from "react";
import propTypes from "prop-types";

class Input extends React.PureComponent {
  constructor(props) {
    super(props);
    this.setRef = this.setRef.bind(this);
    this.handleChange = this.handleChange.bind(this);
  }
  handleChange(e) {
    const { name, onChange } = this.props;
    if (onChange) {
      onChange(name, e.target.value);
    }
  }

  componentDidMount() {
    if (this.props.autoFocus) {
      this.refs.focus();
    }
  }

  setRef(ref) {
    this.ref = ref;
  }

  render() {
    const { errorMessage, label, name, value, type, onFocus } = this.props;

    return (
      <div>
        <label>
          {label}
          <input
            id={"input_${name}"}
            ref={this.setRef}
            onChange={this.handleChange}
            onFocus={onFocus}
            value={value}
            type={type}
          />
          {errorMessage && <span className="error">{errorMessage}</span>}
        </label>
      </div>
    );
  }
}

Input.prototype = {
  type: propTypes.oneOf(["text", "number", "price"]),
  name: propTypes.string.isRequired,
  value: propTypes.oneOfType([propTypes.number, propTypes.string]),
  errorMessage: propTypes.string,
  label: propTypes.string,
  onChange: propTypes.func,
  autoFocus: propTypes.bool,
};

Input.defaultProps = {
  onChange: () => {},
  onFocus: () => {},
  autoFocus: false,
  type: "text",
};
export default Input;
