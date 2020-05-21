let ru = [
  ("Locale", {j|Русский|j}),
  ("Home", {j|Главная|j}),
  ("Auth.Enter", {j|Вход|j}),
  ("Auth.Login", {j|Логин|j}),
  ("Auth.Submit", {j|Войти|j}),
  ("Auth.TypeLogin", {j|Введите логин|j}),
  ("Auth.TypePassword", {j|Введите пароль|j}),
  (
    "Auth.RepeatTypePassword",
    {j|Повторите пароль|j},
  ),
  ("Auth.ForgetPassword", {j|Забыли пароль|j}),
  ("Auth.Password", {j|Пароль|j}),
  ("Auth.ConfirmPassword", {j|Повторите пароль|j}),
  ("Auth.Registration", {j|Регистрация|j}),
  ("Auth.Register", {j|Зарегистрироваться|j}),
  (
    "Auth.Slogan",
    {j|Наш лозунг – «Голосовать легко!»|j},
  ),
  ("Vote.Dashboard", {j|Панель управления|j}),
  ("Vote.Text", {j|Голосование|j}),
  ("Vote.Settings", {j|Настройки|j}),
  (
    "Vote.AddCandidate",
    {j|Регистрировать кандидата|j},
  ),
  (
    "Vote.AddingCandidate",
    {j|Регистрация кандидата|j},
  ),
  ("Vote.CreateBulletin", {j|Создать бюллетень|j}),
  (
    "Vote.CreatingBulletin",
    {j|Создание бюллетеня|j},
  ),
  ("Vote.Rating", {j|Рейтинг|j}),
  (
    "Vote.Slogan",
    {j|Исполни свой гражданский долг!|j},
  ),
  (
    "Vote.Candidate.Name",
    {j|Наименование кампании|j},
  ),
  (
    "Vote.Candidate.Goal",
    {j|Цель, (проект, программа)|j},
  ),
  ("Vote.Candidate.Description", {j|Описание|j}),
  (
    "Vote.Candidate.Registered",
    {j|Кандидат зарегистрирован|j},
  ),
  ("Vote.Bulletin.Name", {j|Имя|j}),
  ("Vote.Bulletin.Description", {j|Описание|j}),
  ("Vote.Bulletin.Submit", {j|Сгенерировать|j}),
  (
    "Vote.Bulletin.Created",
    {j|Бюллетень успешно создан|j},
  ),
  (
    "Validation.Required",
    {j|Обязательно к заполнению|j},
  ),
  (
    "Error.Unexpected",
    {j|Произошла непредвиденная ошибка|j},
  ),
  ("Error.TryLater", {j|Попробуйте позже...|j}),
  ("Action.Submit", {j|Отправить|j}),
  ("Action.Cancel", {j|Отменить|j}),
  ("Action.Create", {j|Создать|j}),
  ("Action.Register", {j|Регистрировать|j}),
];

let en = [
  ("Locale", "English"),
  ("Home", "Home"),
  ("Vote.Dashboard", "Dashboard"),
  ("Vote.Text", "Voting"),
  ("Vote.Settings", "Setting"),
  ("Vote.AddCandidate", "Register a candidate"),
  ("Vote.AddingCandidate", "Registering the candidate"),
  ("Vote.CreateBulletin", "Create a bulletin"),
  ("Vote.CreatingBulletin", "Creating the bulletin"),
  ("Vote.Rating", "Rating"),
  ("Vote.Slogan", "Do your civic duty!"),
  ("Vote.Candidate.Name", "Name of the campaign"),
  ("Vote.Candidate.Goal", "Goal, programs"),
  ("Vote.Candidate.Description", "Description"),
  (
    "Vote.Candidate.Registered",
    "Candidate has been registered, stay tuned",
  ),
  ("Vote.Bulletin.Name", "Name"),
  ("Vote.Bulletin.Description", "Description"),
  ("Vote.Bulletin.Submit", "Generate"),
  (
    "Vote.Bulletin.Created",
    "Bulletin has been successfully created",
  ),
  ("Validation.Required", "Required"),
  ("Error.Unexpected", "An unexpected error occurred"),
  ("Error.TryLater", "try later again..."),
  ("Action.Submit", "Submit"),
  ("Action.Cancel", "Cancel"),
  ("Action.Create", "Create"),
  ("Action.Register", "Register"),
];

type t =
  | En(string)
  | Ru(string);

let ruDict = ru->Js.Dict.fromList;
let enDict = en->Js.Dict.fromList;

let translate = (locale: t) => {
  let v =
    switch (locale) {
    | Ru(id) => Js.Dict.get(ruDict, id)
    | En(id) => Js.Dict.get(enDict, id)
    };

  switch (v) {
  | Some(v) => v
  | _ =>
    Js.log("[Locale] key isn't defined");
    "";
  };
};
