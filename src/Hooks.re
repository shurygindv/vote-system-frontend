open Webapi.Dom;

let (>>=) = Belt.Option.flatMap;

let useOverflowHiddenStyle = style => {
  let setOverflowProp = v => {
    CssStyleDeclaration.setProperty("overflow", v, "", style);
  };

  let applyOverflow = _ => {
    setOverflowProp("hidden");

    Some(_ => setOverflowProp(""));
  };

  React.useLayoutEffect0(applyOverflow);
};

let useOverflowHiddenBody = _ => {
  let documentBody =
    Document.asHtmlDocument(document)
    >>= HtmlDocument.body
    >>= Element.asHtmlElement
    |> Belt.Option.getExn;

  documentBody -> HtmlElement.style -> useOverflowHiddenStyle;
};
