import Head from "next/head";
import Footer from "../comps/Footer";
import Layout from "../comps/Layout";
import Navbar from "../comps/Navbar";
import styles from "../styles/Home.module.css";
import Link from "next/link";

export default function Home() {
  return (
    <>
      <Head>
        <title>Mbc List | Home</title>
        <meta name="keywords" content="mbc"></meta>
      </Head>
      <div>
        <h1 className={styles.title}>Homepage</h1>
        <p className={styles.text}></p>
        <Link href="/mbc">
          <a className={styles.btn}>See MBC Listing</a>
        </Link>
      </div>
    </>
  );
}
