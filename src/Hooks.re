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

// =============== //
type progress = [
      | `rejected
      | `resolved
      | `pending
];

let useWaitingApi = () => {
    let (status, setStatus) = React.useState(_: option(progress) => None);

    let eq = fun
      | v => v === status;

    let isRejected = eq(Some(`rejected));
    let isPending = eq(Some(`pending));
    let isResolved= eq(Some(`resolved));

    let setStatusFn = v => setStatus(_ => Some(v));

  //  let setPending = _: unit => setStatusFn(`pending);
  //  let setResolved = _: unit => setStatusFn(`resolved);

    let i = setStatusFn;

    let o = {
      "isRejected": isRejected,
      "isPending": isPending,
      "isResolved": isResolved,
    };

    (o, i);
}
