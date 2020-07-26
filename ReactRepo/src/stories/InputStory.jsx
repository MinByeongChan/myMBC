import React from "react";
import { storiesOf } from "@storybook/react";
import { action } from "@storybook/addon-actions";

import Input1 from "../03/Input1";

storiesOf("Input", module)
  .addWithJSX("기본 설정", () => <Input1 name="name" />)
  .addWithJSX("label 기본 예제", () => <Input1 name="name" label="이름" />)
  .addWithJSX("onChange 예제", () => (
    <Input1 name="name" onChange={action("onChange 이벤트 발생!")} />
  ));
