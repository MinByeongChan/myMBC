import React from "react";
import { storiesOf } from "@storybook/react";

import ReduxApp01 from "../07/ReduxApp01";
import ReduxApp02 from "../07/ReduxApp02";

storiesOf("ReduxApp01", module)
  .addWithJSX("기본 예제", () => <ReduxApp01></ReduxApp01>)
  .addWithJSX("리듀서 예제", () => <ReduxApp02></ReduxApp02>);
