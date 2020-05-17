
[@react.component]
let make = (
  ~id, 
) => {
    {switch (Locale.t(id)) {
     | En(v) => React.string(v)
     | Ru(v) => React.string(v)
     }}
};
