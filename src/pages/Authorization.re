open Hooks;

module RegisterForm = {
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
};

module LoginForm = {
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
};

module AuthorizationForm = {
  open Css;
  open Tabs;

  module Styles = {
    let login = style([
     // marginBottom(px(45))
    ]);

    let section = style([
      maxWidth(px(480)),
      overflow(`hidden),
      fontFamily(`cursive)
    ]);
  }

  [@react.component]
  let make = _ => {
    <div className=Styles.section>
      <Tabs>
        <TabList textCentered=true>
          <TabList.Item topLeftRadius=true index={0}>
            <Text id="Auth.Enter" size=`lg />
          </TabList.Item>
          <TabList.Item topRightRadius=true index={1}>
            <Text id="Auth.Registration" size=`lg />
          </TabList.Item>
        </TabList>
        <TabPanel>
          <TabPanel.Item className=Styles.login whited={true}>
              <LoginForm />
          </TabPanel.Item>

          <TabPanel.Item whited={true}> 
              <RegisterForm /> 
          </TabPanel.Item>
        </TabPanel>
      </Tabs>
    </div>;
  };
};


[@react.component]
let make = _ => {
  useOverflowHiddenBody();

  <Layout>
    <Layout.Body 
        background=`society 
        height=`vh100
     >
     <Grid cols=`fr2>
      <Background 
        fullHeight=true
        bg=`darkGray
      >
          <Flex align=`middleCenter fullHeight=true>
              <Text 
                  id="Auth.Slogan" 
                  size=`xlg 
                  color=`white 
                  uppercase={true} 
                  centered={true} 
              />
          </Flex>
      </Background>

      <Grid align=`middleCenter>
          <AuthorizationForm />
      </Grid>
      </Grid>
    </Layout.Body>
  </Layout>;
};
