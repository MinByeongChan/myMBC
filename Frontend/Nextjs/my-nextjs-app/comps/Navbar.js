import React from "react";
import Link from "next/link";
import Image from "next/image";

const Navbar = () => {
  return (
    <nav>
      <div className="logo">
        <Image src="/logo.png" width={100} height={100} />
      </div>
      <Link href="/about">About</Link>
      <Link href="/">Home</Link>
      <Link href="/mbc">MBC Listing</Link>
    </nav>
  );
};

export default Navbar;
