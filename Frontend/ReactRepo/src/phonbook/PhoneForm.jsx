import React, { Component } from "react";

class PhoneForm extends Component {
  state = {
    name: "",
    phone: "",
  };
  handleChange = (e) => {
    this.setState({
      [e.target.name]: e.target.value,
    });
  };
  render() {
    return (
      <div>
        <form>
          <input
            placeholder="이름"
            value={this.state.name}
            onChange={this.handleChange}
            name="personName"
          />
          <input
            placeholder="전화번호"
            value={this.state.phone}
            onChange={this.handleChange}
            name="phone"
          />
          <div>
            {this.state.name} {this.state.phone}
          </div>
        </form>
      </div>
    );
  }
}

export default PhoneForm;
