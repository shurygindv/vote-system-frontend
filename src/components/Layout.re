module Header = {
  [@react.component]
  let make = (~children) => {
    <header> children </header>;
  };
};

module Body = {
  module Styles = {
    open Css;

    let block = style([]);

    let height = fun
      | Some(`vh100) => style([height(vh(100.0))])
      | _ => "";
  };

  [@react.component]
  let make =
      (
        ~children,
        ~background: option(Theme.Bg.t)=?,
        ~height: option([ | `vh100])=?
      ) => {
    let classes =
      Cn.make([
        Styles.block,
        Styles.height(height),
        Theme.Bg.make(background),
      ]);

    <main className=classes> children </main>;
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
