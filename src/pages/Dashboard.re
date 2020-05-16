module Navbar = {
  [@react.component]
  let make = _ => {
    let handleSelect = (v: string, _e) => {
      Js.log(v);
      ();
    };

    RsuiteUi.(
      <Navbar>
        <Navbar.Header>
          <a href="#" className="navbar-brand logo">
            {React.string("2")}
          </a>
        </Navbar.Header>
        <Navbar.Body>
          <Nav onSelect=handleSelect activeKey="2">
            <Nav.Item eventKey="1" icon={<Icon icon="home" />}>
              {React.string("Home")}
            </Nav.Item>
            <Nav.Item eventKey="2">
              {React.string("News")}
            </Nav.Item>
            <Nav.Item eventKey="3">
              {React.string("Products")}
            </Nav.Item>
            <Dropdown title={React.string("About")}>
              <Dropdown.Item eventKey="4">
                {React.string("News")}
              </Dropdown.Item>
              <Dropdown.Item eventKey="5">
                {React.string("News")}
              </Dropdown.Item>
              <Dropdown.Item eventKey="6">
                {React.string("News")}
              </Dropdown.Item>
            </Dropdown>
          </Nav>
          <Nav pullRight=true>
            <Nav.Item icon={<Icon icon="cog" />}>
              {React.string("Settings")}
            </Nav.Item>
          </Nav>
        </Navbar.Body>
      </Navbar>
    );
  };
};

module Sidenav = {

    [@react.component]
    let make = _ => {

    let handleDropdownSelect = (v: array(string), _e) => {
       Js.log(v);
       ();
     };

    RsuiteUi.(
        <Sidenav onSelect=handleDropdownSelect>
            <Sidenav.Header> {React.string("2")} </Sidenav.Header>
            <Sidenav.Body>
              <Nav>
                <Nav.Item
                  active=true
                  eventKey="1"
                  icon={<Icon icon="dashboard" />}>
                  <Text id="Home.Dashboard" />
                </Nav.Item>
                <Dropdown
                  eventKey="2"
                  title={<Text id="Home.Vote" />}
                  icon={<Icon icon="group" />}>
                  <Dropdown.Item eventKey="2-1">
                    {React.string("1")}
                  </Dropdown.Item>
                  <Dropdown.Item eventKey="2-2">
                    {React.string("2")}
                  </Dropdown.Item>
                  <Dropdown.Item eventKey="2-3">
                    {React.string("3")}
                  </Dropdown.Item>
                  <Dropdown.Item eventKey="2-4" />
                </Dropdown>

                <Nav.Item
                  eventKey="3"
                  icon={<Icon icon="gear-circle" />}
                >
                  <Text id="Home.Settings" />
                </Nav.Item>
              </Nav>
            </Sidenav.Body>
          </Sidenav>
        );
    }
}

module Content = {
    [@react.component]
    let make = _ => {
        <Flex columns={true}>
            <Navbar />
        </Flex>
    }
}

module Styles = {
  open Css;
  let page = style([gridTemplateColumns([fr(0.3), fr(0.7)])]);
};

[@react.component]
let make = _ => {

  <Layout>
    <Layout.Body>
      <Grid className=Styles.page>
        <Sidenav />

        <Content />
      </Grid>
    </Layout.Body>
  </Layout>;
};
