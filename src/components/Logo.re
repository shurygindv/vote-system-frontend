module Styles = {
    open Css;

    let logo = style([
        width(px(80)),
        height(px(80)),
    ]);

    let block = style([
        display(`flex),
        justifyContent(`center),
        alignItems(`center),
        background(rgba(0, 0, 0, `num(0.02)))
    ]);

    let text = style([
        marginLeft(px(20))
    ]);
}


[@react.component]
let make = (~withText=true) => {

  <a href="/vote/dashboard" className={Styles.block}>
    <img className={Styles.logo} src={Images.logo2} alt="logo" />

    {withText ?
        <Text
            id="Vote.Slogan"
            className={Styles.text}
            uppercase={true}
            bold={true}
        />
        : React.string("")
    }
  </a>
};
