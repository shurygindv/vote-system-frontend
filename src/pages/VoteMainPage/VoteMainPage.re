module Navbar = {
  open IntlProvider;

  [@react.component]
  let make = _ => {
    let (_, toggleLang) = useToggleLang();

    let handleSelect = (v: string, _e) => {
      Js.log(v);
      ();
    };

    RsuiteUi.(
      <Navbar>
        <Navbar.Body>
          <Nav onSelect=handleSelect activeKey="2">
            <Nav.Item eventKey="1" icon={<Icon icon="home" />}>
              <Translator id="Home" />
            </Nav.Item>
          </Nav>

          <Nav pullRight=true>
            <Nav.Item 
              icon={<Icon icon="cog" />} 
              onClick={toggleLang}
            >
              <Translator id="Locale" />
            </Nav.Item>

            <Nav.Item icon={<Icon icon="cog" />}>
              <Translator id="Vote.Settings" />
            </Nav.Item>
          </Nav>
        </Navbar.Body>
      </Navbar>
    );
  };
};

module Sidenav = {
  module Navlink = {
    type linkProps = {
      href: string,
      className: string,
      onClick: Js.Nullable.t(ReactEvent.Mouse.t => unit),
      children: ReasonReact.reactElement,
    };

    // wrapper
    // https://github.com/reasonml/reason-react/blob/master/docs/component-as-prop.md
    // for details
    let linkFn = (props: linkProps) => {
      let handleClick = props.onClick -> Js.Nullable.toOption;

      <Link 
          href={props.href} 
          onClick={handleClick}
          className={props.className}
        >
        {props.children}
      </Link>;
    };

    [@react.component]
    let make = (~children, ~href: string="#", ~icon: React.element) => {
      <RsuiteUi.Dropdown.Item
        eventKey="2"
        componentClass=linkFn icon href >
        children
      </RsuiteUi.Dropdown.Item>;
    };
  };

  let firstItemIndex = "0";

  [@react.component]
  let make = _ => {
    let (activeEventKey, setActiveItem) = React.useState(() => firstItemIndex);

    let handleNavChange = (v: list(string), _e) => {
      switch(Belt.List.flatten([v])) {
        | [first] => setActiveItem(_ => first);
        | _ => ()
      }
    };

    RsuiteUi.(
      <Sidenav onSelect=handleNavChange>
        <Sidenav.Header> <Logo /> </Sidenav.Header>
        <Sidenav.Body>
          <Nav activeKey={activeEventKey}>
            <Nav.Item
              eventKey="0"
              href="/vote/dashboard"
              componentClass=Navlink.linkFn
              icon={<Icon icon="dashboard" />}
            >
              <Text id="Vote.Dashboard" />
            </Nav.Item>

            <Dropdown
              eventKey="1"
              title={<Text id="Vote.Text" />}
              icon={<Icon icon="group" />}>
              <Navlink
                href="/vote/add-candidate"
                icon={<Icon icon="plus" />}>
                <Translator id="Vote.AddCandidate" />
              </Navlink>

              <Navlink
                href="/vote/create-bulletin"
                icon={<Icon icon="exchange" />}>
                <Translator id="Vote.CreateBulletin" />
              </Navlink>

              <Navlink
                href="/vote/rating" icon={<Icon icon="bar-chart" />}>
                <Translator id="Vote.Rating" />
              </Navlink>

            </Dropdown>

            <Nav.Item
              eventKey="2" 
              href="/vote/settings"
              componentClass=Navlink.linkFn
              icon={<Icon icon="gear-circle" />}
            >
              <Text id="Vote.Settings" />
            </Nav.Item>
          </Nav>
        </Sidenav.Body>
      </Sidenav>
    );
  };
};

module DynamicContent = {

  module Styles = {
    open Css;

    let content = style([
      padding(px(20))
    ]);
  }

  [@react.component]
  let make = _ => {
    let url = ReasonReactRouter.useUrl();

    <Flex columns=true >
      <Navbar />

      <div className=Styles.content>
        {switch (url.path) {
        | ["vote", "dashboard"] => <VoteDashboard />
        | ["vote", "add-candidate"] => <VoteAddCandidate />
        | ["vote", "create-bulletin"] => <VoteCreateBulletin />
        | ["vote", "rating"] => <VoteRating />
        | ["vote", "settings"] => <VoteSettings />
        | _ => <NotFoundPage />
        }}
       </div>
    </Flex>;
  };
};

module Styles = {
  open Css;
  let page =
    style([
      height(`percent(100.0)),
      gridTemplateColumns([fr(0.2), fr(0.8)]),
    ]);
};

[@react.component]
let make = _ => {
  <Layout>
    <Layout.Body height=`vh100>
      <Grid className=Styles.page>
        <Sidenav />
        <DynamicContent />
      </Grid>
    </Layout.Body>
  </Layout>;
};
