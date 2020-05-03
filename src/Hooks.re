open Webapi.Dom;

let unwrapUnsafely =
  fun
  | Some(v) => v
  | None => raise(Invalid_argument("Passed `None` to unwrapUnsafely"));

let andThen = (f: 'a => option('b)) =>
  fun
  | Some(v) => f(v)
  | None => None;

let useOverflowStyle = style => {
  let setOverflowProp = value => {
    CssStyleDeclaration.setProperty("overflow", value, "", style);
  };

  let resetOverflow = _ => {
    setOverflowProp("");
  };

  React.useLayoutEffect0(() => {
    setOverflowProp("hidden");

    Some(resetOverflow);
  });
};

let useOverflowHiddenBody = _ => {
  // TODO: rethink
  document
  |> Document.asHtmlDocument
  |> andThen(HtmlDocument.body)
  |> unwrapUnsafely
  |> Element.asHtmlElement
  |> unwrapUnsafely
  |> HtmlElement.style
  |> useOverflowStyle;
};
