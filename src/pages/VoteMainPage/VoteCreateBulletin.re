open RsuiteUi;

let callCreatingBulletinApi = (name: string, description: string) => {
  Api.createBulletin(~name, ~description);
};

let showSuccesNotification = _ => {
  Notification.success(
    Notification.Props.make(
      ~title=<Text id="Vote.Bulletin.Created" />,
      ~description=<EmptyText />,
      ~placement="bottomStart",
      (),
    ),
  );
};

let showErrorNotification = _ => {
  Notification.error(
    Notification.Props.make(
      ~title=<Text id="Error.Unexpected" />,
      ~description=<Text id="Error.TryLater" size=`sm />,
      ~placement="bottomStart",
      (),
    ),
  );
};

[@react.component]
let make = _ => {
  let (progress, setProgress) = Hooks.useWaitingApi();
  let (formValues, setFormValues) =
    React.useState(_ =>
      {"bulletinName": "", "bulletinDescription": ""}
    );

  let addCandidate = (candidateName: string, candidateDesc: string) => {
    Js.Promise.(
      callCreatingBulletinApi(candidateName, candidateDesc)
      |> then_(_ => {
           setProgress(`resolved);
           showSuccesNotification();
           resolve();
         })
      |> catch(_ => {
           setProgress(`rejected);
           showErrorNotification();
           resolve();
         })
    );
    ();
  };

  let handleSubmit = _ => {
    setProgress(`pending);

    addCandidate(
      formValues##bulletinName,
      formValues##bulletinDescription,
    );
  };

  <Panel
    header={<Text id="Vote.CreatingBulletin" size=`lg bold=true />}>
    <Form
      formValue=formValues
      onSubmit=handleSubmit
      onChange={v => setFormValues(_ => v)}>
      <FormGroup>
        <ControlLabel>
          <Text id="Vote.Bulletin.Name" />
        </ControlLabel>
        <FormControl
          _type=`text
          name="bulletinName"
          required=true
        />
        <HelpBlock tooltip=true>
          <Text id="Validation.Required" />
        </HelpBlock>
      </FormGroup>
      <FormGroup>
        <ControlLabel>
          <Text id="Vote.Bulletin.Description" />
        </ControlLabel>
        <FormControl
          name="bulletinDescription"
          rows=5
          componentClass="textarea"
        />
      </FormGroup>
      <FormGroup>
        <ButtonToolbar>
          <Button
            loading={progress##isPending}
            appearance=`primary
            _type=`submit>
            <Translator id="Action.Create" />
          </Button>
        </ButtonToolbar>
      </FormGroup>
    </Form>
  </Panel>;
};
