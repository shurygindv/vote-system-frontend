
// context
let activeTabIndex = 0;
let changeActiveIndex = (_index: int) => ();

let value = (activeTabIndex, changeActiveIndex);

let context = React.createContext(value);
//
let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  
let make = React.Context.provider(context);

