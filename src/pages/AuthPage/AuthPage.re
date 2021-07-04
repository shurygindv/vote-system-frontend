open Hooks;

module AuthorizationForm = {
  open Css;
  open !Tabs;

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
              <AuthLoginForm />
          </TabPanel.Item>

          <TabPanel.Item whited={true}>
              <AuthRegisterForm />
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
