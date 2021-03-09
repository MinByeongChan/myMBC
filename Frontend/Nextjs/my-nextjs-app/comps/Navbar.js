import React from "react";
import Link from "next/link";

const Navbar = () => {
  return (
    <nav>
      <div className="logo">
        <h1>MBC Lists</h1>
      </div>
      <a href="/about">About</a>
      <a href="/">Home</a>
      <a href="/mbc">MBC Listing</a>
    </nav>
  );
};

export default Navbar;
