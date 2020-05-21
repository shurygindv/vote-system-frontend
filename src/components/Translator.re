

[@react.component]
let make = (~id: string) => {
  let text = IntlProvider.useIntl(id);

  React.string(text);
};
