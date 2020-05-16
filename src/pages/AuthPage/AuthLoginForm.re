 module Styles = {
    open Css

    let controls = style([
      display(grid),
      gridTemplateColumns([fr(1.0), fr(1.0)]),
      gridGap(px(10)),
      marginTop(px(20)),
    ]);

    let group = style([
      display(`block),
      margin2(~v=px(15), ~h=`zero)
    ])
  };

  module SubmitButton = {
     [@react.component]
     let make = _ => {
      <RsuiteUi.Button appearance=`primary size=`lg >
             <Text id="Auth.Submit" />
      </RsuiteUi.Button>
    }
  };

  module ForgetPasswordButton = {
    [@react.component]
     let make = _ => {
      <RsuiteUi.Button size=`lg>
            <Text id="Auth.ForgetPassword" />
      </RsuiteUi.Button>
    }
  }

  [@react.component]
  let make = _ => {
      <div>

      <div className=Styles.group>
      <label>
        <Text id="Auth.Login" />
        <Input 
              _type=`text 
              placeholderId={"Auth.TypeLogin"}
        />
      </label> 
      </div>

      <div className=Styles.group>
       <label>
        <Text id="Auth.Password" />
        <Input 
            _type=`password 
            placeholderId="Auth.TypePassword"
        />
      </label> 
      </div>

      <div className=Styles.controls>
        <SubmitButton />

        <ForgetPasswordButton />
      </div>
       
      </div>
  };