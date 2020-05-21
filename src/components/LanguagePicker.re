open RsuiteUi;

[@react.component]
let make = _ => {
  let (lang, set) = React.useContext(IntlProvider.context);

  let toggleLang = _ => {
      switch (lang) {
          | En(_) => set(Ru(""))
          | Ru(_) => set(En(""))
      }
  };

  <Button appearance=`subtle onClick=toggleLang>
    <Translator id="Locale" />
  </Button>;
};
