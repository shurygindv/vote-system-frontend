
[@react.component]
let make = _ => {

  RsuiteUi.(
  <Form layout=`horizontal>
    <FormGroup>
      <ControlLabel>{React.string("user")}</ControlLabel>
      <FormControl name="name" />
      <HelpBlock>{React.string("required")}</HelpBlock>
    </FormGroup>
    <FormGroup>
      <ControlLabel>{React.string("email")}</ControlLabel>
      <FormControl name="email" _type=`email />
      <HelpBlock tooltip={true}>{React.string("Required")}</HelpBlock>
    </FormGroup>
    <FormGroup>
      <ControlLabel>{React.string("password")}</ControlLabel>
      <FormControl name="password" _type=`password  />
    </FormGroup>
    <FormGroup>
      <ControlLabel>{React.string("Textarea")}</ControlLabel>
      <FormControl name="textarea" rows={5} componentClass="textarea" />
    </FormGroup>
    <FormGroup>
      <ButtonToolbar>
        <Button appearance=`primary>{React.string("Submit")}</Button>
        <Button appearance=`default>{React.string("Cancel")}</Button>
      </ButtonToolbar>
    </FormGroup>
  </Form>
  );
};
