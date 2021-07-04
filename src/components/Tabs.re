// not designed for constructor
module TabList = {
  module Styles = {
    open Css;

    let textCentered = style([textAlign(center)]);

    let block =
      style([display(grid), gridTemplateColumns([fr(1.0), fr(1.0)])]);
  };

  [@react.component]
  let make = (~children, ~textCentered=false) => {
    let classes =
      Cn.fromList([Styles.block, Cn.on(Styles.textCentered, textCentered)]);

    <div className=classes> children </div>;
  };

  module Item = {
    open Css;

    module Styles = {
      let leftRadius = style([borderTopLeftRadius(px(15))]);
      let rightRadius = style([borderTopRightRadius(px(15))]);

      let whited = style([background(Theme.Color.white)]);
      let defaultColor = style([background(rgba(255, 255, 255, `num(0.8)))]);

      let block =
        style([
          cursor(`pointer),
          border(px(1), solid, rgba(0, 0, 0, `num(0.05))),
          borderBottomStyle(none),
          padding(px(20))
        ]);
    };

    [@react.component]
    let make = (
      ~children,
      ~topLeftRadius=false,
      ~topRightRadius=false,
      ~index:int
      ) => {
      let (activeTabIndex, setActiveTabIndex) = React.useContext(TabsProvider.context);

      let handleClick = _ => {
        index -> setActiveTabIndex;
      };

      let isActive = activeTabIndex == index;

      let classes =
        Cn.fromList([
          Styles.block,
          Cn.on(Styles.defaultColor, !isActive),
          Cn.on(Styles.whited, isActive),
          Cn.on(Styles.leftRadius, topLeftRadius),
          Cn.on(Styles.rightRadius, topRightRadius),
        ]);

      // TODO: use semantic button instead this
      <div
        className=classes
        onClick={handleClick}
      >
        children
       </div>;
    };
  };
};

module TabPanel = {
  module Styles = {
    open Css;

    let block = style([
      display(`flex),
      alignItems(`baseline),
      transition(
        ~duration=300,
        ~timingFunction=easeInOut,
        "transform",
      ),
      borderBottomRightRadius(px(15)),
      borderBottomLeftRadius(px(15))
    ]);
  };

  [@react.component]
  let make = (~children) => {
    let (activeTabIndex, _) = React.useContext(TabsProvider.context);

    let offset = activeTabIndex * -100;
    let transform = {j|translateX($offset%)|j}
    let style = ReactDOMRe.Style.make(~transform=transform, ());

    // use css scroll snap instead this :)

    <div className=Styles.block style=style> children </div>;
  };

  module Item = {
    module Styles = {
      open Css;

      let block = style([
        flexShrink(0.0),
        width(`percent(100.0)),
        padding2(~v=px(20), ~h=px(25)),
        borderBottomRightRadius(px(15)),
        borderBottomLeftRadius(px(15))
      ]);

      let whited = style([background(Theme.Color.white)]);
    }

    [@react.component]
    let make = (~children, ~className: string = "", ~whited=false) => {
      let classes = Cn.fromList([
        className,
        Styles.block,
        Cn.on(Styles.whited, whited)
      ]);

      <div className=classes>
        children
      </div>;
    };
  };
};

module Tabs = {
  [@react.component]
  let make = (~children, ~activeTabIndex: int = 0) => {
    let (activeIndex, setActiveIndex) = React.useState(() => activeTabIndex);

    let changeActiveIndex = (i: int) => {
      setActiveIndex(_ => i);
    };

    <TabsProvider value={(activeIndex, changeActiveIndex)}>
      children
    </TabsProvider>;
  };
};
