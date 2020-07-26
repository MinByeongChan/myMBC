import React from "react";
import { storiesOf } from "@storybook/react";

import Button from "../04/Button";
import Text from "../04/Text";
import withHoc from "../05/withHoc";

const ButtonWithHoc = withHoc(Button);
const TextWithHoc = withHoc(Text);

storiesOf("WithHoc", module)
  .addWithJSX("기본 설정", () => (
    <div>
      <ButtonWithHoc>안녕하세요</ButtonWithHoc>
      <TextWithHoc>안녕하세요</TextWithHoc>
    </div>
  ))
  .addWithJSX("large 예제", () => (
    <div>
      <ButtonWithHoc large>안녕하세요.</ButtonWithHoc>
      <TextWithHoc large>안녕하세요</TextWithHoc>
    </div>
  ));
