import React, { Component } from "react";

class StateExample extends Component {
  constructor(props) {
    super(props);
    this.state = {
      loading: true,
      formData: "no data",
    };
    this.handleData = this.handleData.bind(this);
    setTimeout(this.handleData, 4000);
  }

  // handleData() {
  //   const data = "newdata";
  //   const { formData } = this.state;

  //   this.setState({
  //     loading: false,
  //     formData: data + formData,
  //   });

  //   console.log("loading 값", this.state.loading);
  // }

  handleData(data) {
    this.setState(function (prevData) {
      const newState = {
        loading: false,
        formData: data + prevData.formData,
      };
      return newState;
    });
  }

  render() {
    return (
      <div>
        <span>로딩중: {String(this.state.loading)}</span>
        <span>결과: {String(this.state.formData)}</span>
      </div>
    );
  }
}

export default StateExample;
