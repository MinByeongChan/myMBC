import React, { PureComponent } from "react";
import LoadingProvider from "./LoadingProvider";
import ButtonWithLoadingContext from "./ButtonWithLoadingContext";
import Button from "../04/Button";

function RowBComponent() {
  return <Button>버튼</Button>;
}

function RowCComponent() {
  return <ButtonWithLoadingContext>버튼</ButtonWithLoadingContext>;
}

function TableComponent() {
  return (
    <table>
      <RowBComponent />
      <RowCComponent />
    </table>
  );
}

// const TableComponent = () => <ButtonWithLoadingContext label="버튼" />;

class HomePageComponent extends PureComponent {
  render() {
    return (
      <LoadingProvider>
        <TableComponent />
        <ButtonWithLoadingContext>상태변경</ButtonWithLoadingContext>
      </LoadingProvider>
    );
  }
}

export default HomePageComponent;
