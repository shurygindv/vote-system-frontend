
let goTo = p => {
    ReasonReactRouter.push(p);
};

let goToAuthorization = () => {
    goTo("")
};

let goToDashboard = () => {
    goTo("/vote/dashboard")
};

let goToAddingCandidate = () => {
    goTo("/vote/add-candidate")
};

let goToGeneratingBulletin = () => {
   goTo("/vote/create-bulletin")
};

let goToRating = () => {
    goTo("/vote/rating")
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