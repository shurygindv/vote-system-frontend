
// todo: json
let ruLocalePairs = [
  ("Auth.Enter", {j|Вход|j}),
  ("Auth.Login", {j|Логин|j}),
  ("Auth.Submit", {j|Войти|j}),
  ("Auth.TypeLogin", {j|Введите логин|j}),
  ("Auth.TypePassword", {j|Введите пароль|j}),
  ("Auth.RepeatTypePassword", {j|Повторите пароль|j}),
  ("Auth.ForgetPassword", {j|Забыли пароль|j}),
  ("Auth.Password", {j|Пароль|j}),
  ("Auth.ConfirmPassword", {j|Повторите пароль|j}),
  ("Auth.Registration", {j|Регистрация|j}),
  ("Auth.Register", {j|Зарегистрироваться|j}),
  ("Auth.Slogan", {j|Наш лозунг – «Голосовать легко!»|j}),

  ("Vote.Dashboard", {j|Панель управления|j}),
  ("Vote.Text", {j|Голосование|j}),
  ("Vote.Settings", {j|Настройки|j}),
  ("Vote.AddCandidate", {j|Добавить кандидата|j}),
  ("Vote.GenerateBulletin", {j|Сгенерировать бюллетень|j}),
  ("Vote.Rating", {j|Рейтинг|j}),
  ("Vote.Slogan", {j|Исполни свой гражданский долг!|j})
];

type locale = 
  | En(string)
  | Ru(string);

let ruLocale = ruLocalePairs
  -> Js.Dict.fromList

let translate = Js.Dict.get(ruLocale)

let t = id => {
  switch (translate(id)) {
    | Some(v) => Ru({j|$v|j})
    | None => {
      Js.log("locale:: invalid key");

      Ru("")
    }
  }
}