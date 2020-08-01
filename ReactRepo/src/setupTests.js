// jest-dom adds custom jest matchers for asserting on DOM nodes.
// allows you to do things like:
// expect(element).toHaveTextContent(/react/i)
// learn more: https://github.com/testing-library/jest-dom
//import "@testing-library/jest-dom/extend-expect";

import { configure } from "enzyme";
import Adapter from "enzyme-adapter-react-16.3";
import * as Aphrodite from "aphrodite";
import * as AphroditeNoImportant from "aphrodite/no-important";

// 아프로디테 DOM 함수 호출 과정을 중지 시킴
// enzyme test mount 로 테스트시 걸림돌이 됨.
Aphrodite.StyleSheetTestUtils.suppressStyleInjection();
AphroditeNoImportant.StyleSheetTestUtils.suppressStyleInjection();

configure({ adapter: new Adapter() });

afterEach(() => {
  console.error.mockClear();
});

beforeEach(() => {
  jest.spyOn(console, "error").mockImplementation((e) => {
    throw new Error(e);
  });
});
