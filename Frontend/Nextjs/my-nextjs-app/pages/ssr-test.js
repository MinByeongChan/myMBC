import React, { Component } from "react";
import Layout from "../comps/Layout";
import axios from "axios";

class SSRTest extends Component {
  static async getInitialProps({ req }) {
    const res = await axios.get("https://jsonplaceholder.typicode.com/users");
    return {
      users: res.data,
    };
  }

  render() {
    const { users } = this.props;

    const userList = users.map((user) => (
      <li key={user.id}>{user.username}</li>
    ));
    return (
      <Layout>
        <ul>{userList}</ul>
      </Layout>
    );
  }
}

export default SSRTest;
