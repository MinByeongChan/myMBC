import Link from "next/link";
import React from "react";
import styles from "../../styles/mbc.module.css";

export const getStaticProps = async () => {
  const res = await fetch("https://jsonplaceholder.typicode.com/users");
  const data = await res.json();

  return {
    props: { mbc: data },
  };
};

const Mbc = ({ mbc }) => {
  return (
    <div>
      <h1>MBC</h1>
      {mbc.map((data) => (
        <div key={data.id}>
          <Link href={`/mbc/${data.id}`}>
            <a className={styles.single}>
              <h3>{data.name}</h3>
            </a>
          </Link>
        </div>
      ))}
    </div>
  );
};

export default Mbc;
