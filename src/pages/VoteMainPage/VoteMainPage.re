module Navbar = {
  [@react.component]
  let make = _ => {
    let handleSelect = (v: string, _e) => {
      Js.log(v);
      ();
    };

    RsuiteUi.(
      <Navbar>
        <Navbar.Body>
          <Nav onSelect=handleSelect activeKey="2">
            <Nav.Item eventKey="1" icon={<Icon icon="home" />}>
              {React.string("Home")}
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
                <Text id="Vote.Settings" />
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
        <Sidenav.Header> 
               <Logo />
        </Sidenav.Header>
        <Sidenav.Body>
          <Nav>
            <Nav.Item
              active=true
              eventKey="1"
              icon={<Icon icon="dashboard" />}
            >
              <Text id="Vote.Dashboard" />
            </Nav.Item>
            <Dropdown
              eventKey="2"
              title={<Text id="Vote.Text" />}
              icon={<Icon icon="group" />}>
              <Dropdown.Item eventKey="2-1"  icon={<Icon icon="plus" />}>
                <Text id="Vote.AddCandidate" />
              </Dropdown.Item>
              <Dropdown.Item eventKey="2-2" icon={<Icon icon="exchange" />}>
                 <Text id="Vote.GenerateBulletin" />
              </Dropdown.Item>
              <Dropdown.Item eventKey="2-3"  icon={<Icon icon="bar-chart" />}>
                <Text id="Vote.Rating" />
              </Dropdown.Item>
            </Dropdown>
            <Nav.Item
              eventKey="3" icon={<Icon icon="gear-circle" />}>
              <Text id="Vote.Settings" />
            </Nav.Item>
          </Nav>
        </Sidenav.Body>
      </Sidenav>
    );
  };
};

module Content = {
  [@react.component]
  let make = _ => {
    <Flex columns=true> <Navbar /> </Flex>;
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
      <Grid className=Styles.page> <Sidenav /> <Content /> </Grid>
    </Layout.Body>
  </Layout>;
};
