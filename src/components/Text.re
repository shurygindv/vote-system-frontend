module Styles = {
  open Css;
  open Theme;

  let fontSizeCss = v =>
    rem(v)
    |> fontSize
    |> Belt.List.add([])
    |> style;

  let defaultFontSize = fontSizeCss(1.3);
  let textSize =
    fun
    | Some(`md) => defaultFontSize
    | Some(`lg) => fontSizeCss(1.9)
    | Some(`xlg) => fontSizeCss(3.2)
    | None => defaultFontSize;
    
  let uppercase = style([textTransform(`uppercase)]);  
  let center = style([textAlign(`center)]);
  let bold = style([fontWeight(bold)]);

  let color = fun 
    | Some(`white) => style([color(Color.white)])
    | None => ""
};

[@react.component]
let make = (
  ~id, 
  ~color: option(Theme.Color.t)=?, 
  ~size: option(Theme.Size.t)=?, 
  ~bold=false, 
  ~className: string= "",
  ~uppercase=false,
  ~centered=false,
) => {
  let classes =
    Cn.make([
      className,
      Cn.ifTrue(Styles.bold, bold),
      Cn.ifTrue(Styles.uppercase, uppercase),
      Cn.ifTrue(Styles.center, centered),
      Styles.textSize(size),
      Styles.color(color),
    ]);

  <span className=classes>
    {switch (Locale.t(id)) {
     | En(v) => React.string(v)
     | Ru(v) => React.string(v)
     }}
  </span>;
};
