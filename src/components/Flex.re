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
}


[@react.component]
let make = (
    ~children, 
    ~className: string= "", 
    ~fullHeight=false,
    ~align: option(Theme.Align.t) =?,
    ~content: option([ | `spaceBetween])=?
) => {
   let classes = Cn.make([
       className,
       Styles.block,
       Styles.align(align),
       Styles.content(content),
       Cn.ifTrue(Styles.fullHeight, fullHeight)
   ]);

  <div className=classes>
    children
  </div>
};
