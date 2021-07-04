// units
module Color = {
  type t = [
    | `white
  ]

  let white = Css.white;

  let make = fun
    | Some(`white) => white
    | _ => raise(Not_found)
};

module Bg = {
  open Css;

  type t = [
        | `white
        | `society
        | `darkGray
    ];

  let backgroundCover = backgroundSize(cover);

  let societyBg = background(url(Images.society2));

  let white = style([background(Color.white)])
  let society = style([societyBg, backgroundCover]);
  let darkGray = style([background(rgba(0,0,0,`num(0.3)))]);

  let make =
    fun
    | Some(`society) => society
    | Some(`white) => white
    | Some(`darkGray) => darkGray
    | _ => ""
};

// like agreement when using flex/grid
module Align = {
   type t = [
        | `center
        | `middle
        | `middleCenter
        | `middleRight
    ];
};

module Margin = {
  type t = [
    | `mdSides
  ];
}

module Padding = {
  type t = [
    | `xs
  ];
}

module Size = {
  type t = [
    | `sm
    | `md
    | `lg
    | `xlg
  ]
}
