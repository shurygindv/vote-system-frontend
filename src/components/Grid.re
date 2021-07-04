module Styles = {
    open Css;

    let block = style([display(`grid)]);
    let fullHeight = style([
        height(`percent(100.0))
    ]);

    module Align = {
      type t = Theme.Align.t;

      let center = unsafe("justifyItems", "center");
      let middle = alignItems(`center);
      let right = unsafe("justifyItems", "flex-end");

      let make = fun
        | Some(`middleCenter) => style([center, middle])
        | Some(`middleRight) => style([right, middle])
        | Some(`middle) => style([middle])
        | Some(`center) => style([center])
        | None => "";
    }

    // cols
    module Cols = {
      type t = [
          | `fr2
      ];

      let fr2Col = gridTemplateColumns([fr(1.0), fr(1.0)]);

      let make = fun
        | Some(`fr2) => style([fr2Col])
        | None => "";
    };
}


[@react.component]
let make = (
    ~children,
    ~className: string= "",
    ~fullHeight = false,
    ~cols: option(Styles.Cols.t) =?,
    ~align: option(Styles.Align.t) =?,
) => {
   let classes = Cn.fromList([
       className,
       Styles.block,
       Styles.Align.make(align),
       Styles.Cols.make(cols),
       Cn.on(Styles.fullHeight, fullHeight)
   ]);

  <div className=classes>
    children
  </div>
};
