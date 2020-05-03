module Header = {
  [@react.component]
  let make = (~children) => {
    <header> children </header>;
  };
};

module Body = {
  [@react.component]
  let make = (~children, ~height, ~align) => {
    let classes = Styles.Block.make(
        ~display = `grid,
        ~height,
        ~align,
    );

    <main className={classes}> 
        children 
    </main>;
  };
};

module Footer = {
  [@react.component]
  let make = (~children) => {
    <footer> children </footer>;
  };
};

[@react.component]
let make = (~children) => {
  <> children </>;
};
