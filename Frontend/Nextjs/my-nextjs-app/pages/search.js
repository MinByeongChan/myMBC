import React from "react";
import Layout from "../comps/Layout";

const Search = ({ url }) => {
  console.log("url", url);
  return <Layout>당신이 검색한 키워드는 "{}" 입니다.</Layout>;
};

export default Search;
