import React from "react";
import { shallow, mount } from "enzyme";
import Text from "../../04/Text";

describe("<Text>", () => {
  it("renders without crashing", () => {
    expect(() => {
      shallow(<Text>테스트</Text>);
    }).not.toThrow();
  });

  // 아프로디테 DOM 호출 사용시 Shallow는 걸림돌이 됨.
  // 아프로디테 호출을 suppress하고 shallow 함수 대신 mount함수를 사용하여 검증해야함.
  // it("contains <span>", () => {
  //   expect(mount(<Text>테스트</Text>).find("span")).toHaveLength(1);
  // });

  // mount는 render함수에 포함된 모든 컴포넌트를 출력하므로 성능 저하를 일으킴.
  // WithStyle 함수 안의 모든 컴포넌트를 렌더링하게 되어 성능 저하
  // 컴포넌트 별로 검증 할 수 있는 함수 dive가 있음
  it("contains <span>", () => {
    expect(
      shallow(<Text>테스트</Text>)
        .dive()
        .find("span")
    ).toHaveLength(1);
  });
});
