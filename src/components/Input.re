


[@react.component]
let make = (
    ~_type: RsuiteUi.Input.Type.t,
    ~placeholderId: string="",
) => {
   let placeholder = IntlProvider.useIntl(placeholderId);

  <RsuiteUi.Input _type={_type} placeholder={placeholder} />
};
