module Styles = {
    open Css;
    let group = style([
      display(`block),
      margin2(~v=px(15), ~h=`zero)
    ]);
  }

  module SubmitButton = {
    [@react.component]
    let make = _ => {
     <RsuiteUi.Button appearance=`primary size=`lg block={true} >
            <Text id="Auth.Register" />
     </RsuiteUi.Button>
   }
 };

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

      <div className=Styles.group>
        <label>
         <Text id="Auth.ConfirmPassword" />
         <Input 
            _type=`password
            placeholderId="Auth.RepeatTypePassword"
          />
        </label> 
     </div>

      <SubmitButton />
       
      </div>
  };