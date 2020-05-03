module Block = {
    open Css;

    let matchDisplay = fun 
     | `grid => style([display(`grid)]);

    let matchHeight = fun 
     | `full  => style([height(`vh(100.0))]);
    
    // align
    let center = unsafe("justifyItems", "center");
    let middle = alignItems(`center);

    let matchAlign= fun 
     | `center => style([center])
     | `middle => style([middle])
     | `middleCenter => style([center, middle]);

    let make = (
        ~display,
        ~height,
        ~align,
    ) => {
        merge([
            matchDisplay(display),
            matchAlign(align),
            matchHeight(height),
        ]);
    }
};