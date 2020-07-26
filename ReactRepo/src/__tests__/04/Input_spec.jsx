import React from "react";
import { shallow } from "enzyme";
import Input from "../../03/Input1";

describe("<Input>", () => {
  it("renders without crashing", () => {
    expect(() => {
      shallow(<Input name="test_name" />);
    }).not.toThrow();
  });
  // it("has one element", () => {
  //   const wrapper = shallow(<Input name="test_name" />);
  //   expect(wrapper.length).toEqual(1);
  //   expect(wrapper).toHaveLength(1);
  // });

  describe("contains <input>", () => {
    it("renders one input", () => {
      const wrapper = shallow(<Input name="test_name" />);
      expect(wrapper.find("input")).toHaveLength(1);
      expect(wrapper.find("label")).toHaveLength(1);
    });
  });

  //prop(), props() 함수로 프로퍼티에 전달된 값 검증
  it("assigns the prop value and type", () => {
    const expectedValue = "123";
    const wrapper = shallow(<Input name="test_name" value={expectedValue} />);
    expect(wrapper.find("input").prop("value")).toBe(expectedValue);
    const { type, value } = wrapper.find("input").props();
    expect(value).toBe(expectedValue);
    expect(type).toBe("text");
  });

  // setProps() 함수로 변경된 프로퍼티 값 전달
  it("renders errorMessage", () => {
    const wrapper = shallow(<Input name="test_name" />);
    expect(wrapper.find(".error")).toHaveLength(0);
    const expectedErrorMessage = "옳지 못한 값이 입력되었습니다.";
    wrapper.setProps({ errorMessage: expectedErrorMessage }); // setProps() 사용
    expect(wrapper.find("span").prop("className")).toBe("error");
    expect(wrapper.find(".error")).toHaveLength(1);
    expect(wrapper.html()).toContain(expectedErrorMessage);
  });

  // simulate() 함수로 가상의 이벤트 검사하기
  it("call back onChange on input change", () => {
    const changeStub = jest.fn();
    const wrapper = shallow(<Input name="test_name" onChange={changeStub} />);
    expect(changeStub).not.toHaveBeenCalled();
    const expectedTargetValue = "updated input";
    wrapper
      .find("input")
      .simulate("change", { target: { value: expectedTargetValue } });
    expect(changeStub).toHaveBeenCalledTimes(1);
    expect(changeStub).toHaveBeenCalledWith("test_name", expectedTargetValue);
  });
});
