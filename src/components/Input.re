
let unwrapPlaceholder = (id: string) => switch (Locale.t(id)) {
    | En(v) => v
    | Ru(v) => v
};

[@react.component]
let make = (
    ~_type: RsuiteUi.Input.Type.t,
    ~placeholderId: string="",
) => {
   let placeholder = unwrapPlaceholder(placeholderId); 

  <RsuiteUi.Input _type={_type} placeholder={placeholder} />
};
