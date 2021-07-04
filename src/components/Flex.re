module Styles = {
    open Css;

    let block = style([
        display(`flex)
    ]);

    let centered = justifyContent(`center);
    let spaceBetween = justifyContent(`spaceBetween);
    let middle = alignItems(`center);

    let align = fun
        | Some(`middle) => style([middle])
        | Some(`center) => style([centered])
        | Some(`middleCenter) => style([middle, centered])
        | None => ""
        | _ => raise(Not_found);

    let content = fun
        | Some(`spaceBetween) => style([spaceBetween])
        | None => ""
        | _ => raise(Not_found);

    let fullHeight = style([
        height(`percent(100.0))
    ]);

    let columns = style([
        flexDirection(`column)
    ]);
}


[@react.component]
let make = (
    ~children,
    ~className: string= "",
    ~fullHeight=false,
    ~columns=false,
    ~align: option(Theme.Align.t) =?,
    ~content: option([ | `spaceBetween])=?
) => {
   let classes = Cn.fromList([
       className,
       Styles.block,
       Styles.align(align),
       Styles.content(content),
       Cn.on(Styles.fullHeight, fullHeight),
       Cn.on(Styles.columns, columns),
   ]);

  <div className=classes>
    children
  </div>
};
