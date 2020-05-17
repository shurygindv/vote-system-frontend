
let goToAuthorization = () => {
    ReasonReactRouter.push("")
};

let goToDashboard = () => {
    ReasonReactRouter.push("/vote/dashboard")
};

let goToAddingCandidate = () => {
    ReasonReactRouter.push("/vote/add-candidate")
};

let goToGeneratingBulletin = () => {
    ReasonReactRouter.push("/vote/create-bulletin")
};

let goToRating = () => {
    ReasonReactRouter.push("/vote/rating")
};

[@react.component]
let make = _ => {
    let url = ReasonReactRouter.useUrl();

    switch (url.path) {
        | ["vote", ..._rest] => <VoteMainPage />
        | [] => <AuthPage />
        | _ => <NotFoundPage />
    }
}