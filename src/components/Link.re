[@react.component]
let make = (
      ~children,
      ~href: string="#",
      ~className="",
      ~onClick: option(ReactEvent.Mouse.t => unit),
    ) => {
  let handleClick = (e: ReactEvent.Mouse.t) => {
    ReactEvent.Synthetic.preventDefault(e);
    ReasonReactRouter.push(href);

    switch (onClick) {
        | Some(next) => next(e)
        | None => ()
    }
  };

  <a href className onClick=handleClick> children </a>;
};
