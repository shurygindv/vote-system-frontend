module Styles = {
    open Css;

    let block = style([]);

    let fullHeight = style([
      height(vh(100.0))
    ]);
}


[@react.component]
let make = (
  ~children,
  ~bg: option(Theme.Bg.t) = ?,
  ~className: string= "",
  ~fullHeight=false
) => {
 let classes = Cn.fromList([
     className,
     Cn.on(Styles.fullHeight, fullHeight),
     Styles.block,
     Theme.Bg.make(bg)
  ]);

  <div className=classes>
    children
  </div>
};
