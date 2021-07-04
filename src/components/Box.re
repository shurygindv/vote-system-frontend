module Styles = {
    open Css;


    let margin = fun
        | Some(`mdSides) => style([margin2(~v=`zero, ~h=px(20))])
        | None => ""
        | _ => raise(Not_found)
}


[@react.component]
let make = (
    ~children,
    ~className: string= "",
    ~margin: option(Theme.Margin.t) =?,
//  ~padding: option(Theme.Padding.t) =?,
) => {
   let classes = Cn.fromList([
       className,
       Styles.margin(margin),
     //  Styles.padding(padding),
   ]);

  <div className=classes>
    children
  </div>
};
