import React from "react";
import { storiesOf } from "@storybook/react";

import PhoneForm from "../phonbook/PhoneForm";

storiesOf("PhoneForm", module).addWithJSX("기본 설정", () => (
  <PhoneForm></PhoneForm>
));
