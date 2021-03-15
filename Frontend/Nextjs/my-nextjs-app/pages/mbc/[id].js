import React from "react";

// 동적으로 생성할 페이지 수를 반환하는 함수
export const getStaticPaths = async () => {
  const res = await fetch("https://jsonplaceholder.typicode.com/users");
  const data = await res.json();

  const paths = data.map((data) => {
    return {
      params: { id: data.id.toString() },
    };
  });

  return {
    paths,
    fallback: false,
  };
};

// 각 생성된
export const getStaticProps = async (context) => {
  const id = context.params.id;
  const res = await fetch("https://jsonplaceholder.typicode.com/users/" + id);
  const data = await res.json();

  return {
    props: { mbc: data },
  };
};

const Detail = ({ mbc }) => {
  return (
    <div>
      <h1>{mbc.name}</h1>
      <p>{mbc.email}</p>
      <p>{mbc.website}</p>
      <p>{mbc.address.city}</p>
    </div>
  );
};

export default Detail;
