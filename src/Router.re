
let goToAuthorization = () => {
    ReasonReactRouter.push("")
};

let goToDashboard = () => {
    ReasonReactRouter.push("/dashboard")
};

[@react.component]
let make = _ => {
    let url = ReasonReactRouter.useUrl();

    switch (url.path) {
        | ["dashboard"] => <Dashboard />
        | [] => <Authorization />
        | _ => <NotFound />
    }
}