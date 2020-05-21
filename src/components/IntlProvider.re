module Provider = {
  // context
  let lang = Locale.Ru("");
  let setLang = (_index: Locale.t) => {()};

  let value = (lang, setLang);

  let context = React.createContext(value);
  //
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(context);
};

let context = Provider.context;

let useIntl = (id: string) => {
  let (lang, _) = React.useContext(context);

  switch (lang) {
  | En(_) => Locale.translate(En(id))
  | Ru(_) => Locale.translate(Ru(id))
  };
};

let useToggleLang = _ => {
  let (lang, set) = React.useContext(context);

  let toggleLang = _ => {
      switch (lang) {
          | En(_) => set(Ru(""))
          | Ru(_) => set(En(""))
      }
  };

  (lang, toggleLang);
};


[@react.component]
let make = (~children) => {
    let (lang, setLang) = React.useState(() => Locale.Ru(""));

    let changeLang = (v: Locale.t) => {
      Js.log(11)
      setLang(_ => v);
    };

    Js.log(lang);
    <Provider value={(lang, changeLang)}>
      children
    </Provider>
};