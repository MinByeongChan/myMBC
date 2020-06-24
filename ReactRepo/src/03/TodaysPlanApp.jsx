import React, { Component } from 'react';

class TodaysPlanApp extends Component {
  render() {
    const { onButtonClick, hasPlan } = this.props;

    return (
      <div className="body">
        {hasPlan ? <TodaysPlanApp /> : null}
        <button onClick={onButtonClick}>계획없음</button>
      </div>
    );
  }
}

// function TodaysPlan(props) {
//   const { onButtonClick, hasPlan } = props;
//   return (
//     <div className="body">
//       {hasPlan ? <TodaysPlan /> : null}
//       <button onClick={onButtonClick}>계획없음</button>
//     </div>
//   );
// }

export default TodaysPlanApp;
