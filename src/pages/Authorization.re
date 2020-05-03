open Hooks;


[@react.component]
let make = _ => {

  useOverflowHiddenBody();

  <Layout>
    <Layout.Body align={`middleCenter} height={`full}> 
        <div>
  {React.string("Privet")} 
        </div>
    </Layout.Body>
  </Layout>;
};
