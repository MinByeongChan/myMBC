import React, { Component } from "react";

class MyDocument extends Component {
  static getInitialProps({ renderPage }) {
    const { html, head } = renderPage();
    const styles = flush();

    return { html, head, styles };
  }

  render() {
    return <html></html>;
  }
}

export default MyDocument;
