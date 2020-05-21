module JsonTransport = {
  let headers =
    Fetch.HeadersInit.make({"Content-Type": "application/json"});

  let get = (~path) => {
    Js.Promise.(
      Fetch.fetch(path)
      |> then_(Fetch.Response.json)
    );
  };

  let post = (~path: string, ~payload: Js.Dict.t(Js.Json.t)) => {
    let body = Js.Json.stringify(Js.Json.object_(payload));

    Js.Promise.(
      Fetch.fetchWithInit(
        path,
        Fetch.RequestInit.make(
          ~method_=Post,
          ~body=Fetch.BodyInit.make(body),
          ~headers=headers,
          ()
        ),
      )
      |> then_(Fetch.Response.json)
    );
  };
};

let json = (pairs): Js.Dict.t(Js.Json.t) => {
  let mapped =
    pairs->Belt.List.map(tuple => {
      let (field, value) = tuple;

      (field, Js.Json.string(value));
    });

  mapped->Js.Dict.fromList;
};

// ===

let auth = (~login: string, ~password: string) => {
  let payload = json([("login", login), ("password", password)]);

  JsonTransport.post("api/v1/auth", payload);
};
