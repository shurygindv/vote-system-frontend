module Styles = {
    open Css;

    let block = style([display(`grid)]);

    // align
    let center = unsafe("justifyItems", "center");
    let middle = alignItems(`center);
    let right = unsafe("justifyItems", "flex-end");
  
    let align = fun
      | Some(`middleCenter) => style([center, middle])
      | Some(`middleRight) => style([right, middle])
      | Some(`middle) => style([middle])
      | Some(`center) => style([center])
      | None => "";

    let fullHeight = style([
        height(`percent(100.0))
    ]);
}


[@react.component]
let make = (
    ~children,
    ~className: string= "",
    ~fullHeight = false,
    ~align: option(Theme.Align.t) =?, 
) => {
   let classes = Cn.make([
       className,
       Styles.block,
       Styles.align(align),
       Cn.ifTrue(Styles.fullHeight, fullHeight)
   ]);

  <div className=classes>
    children
  </div>
};
