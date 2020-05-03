ReactDOMRe.renderToElementWithId(<Application />, "root");

// global
[%bs.raw {|require('normalize.css')|}];
[%bs.raw {|require('rsuite/dist/styles/rsuite-default.css')|}];

// hot reload
[@bs.val] external moduleHot : Js.nullable('accept) = "module.hot";
[@bs.val] external moduleHotAccept : unit => unit = "module.hot.accept";

switch (Js.Nullable.toOption(moduleHot)) {
    | Some(_) => moduleHotAccept();
    | _ => Js.log("hmmmmmmmmm")
};